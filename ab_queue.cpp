#include "queue.h"

ArrayBasedQueue::ArrayBasedQueue(const int capacity)
{
    this->capacity = capacity;
    queue = new int[capacity];
    front = -1;
    rear = -1;
}

ArrayBasedQueue::ArrayBasedQueue(const ArrayBasedQueue& other)
{
    capacity = other.capacity;
    queue = new int[capacity];
    front = other.front;
    rear = other.rear;

    for (int i = 0; i < capacity; i++)
        queue[i] = other.queue[i];
}

ArrayBasedQueue& ArrayBasedQueue::operator = (const ArrayBasedQueue& other)
{
    if (this != &other)
    {
        delete[] queue;
        capacity = other.capacity;
        queue = new int[capacity];
        front = other.front;
        rear = other.rear;

        for (int i = 0; i < capacity; i++)
            queue[i] = other.queue[i];
    }
    return *this;
}

ArrayBasedQueue::~ArrayBasedQueue()
{
    delete[] queue;
    queue = NULL;
    front = rear = -1;
    capacity = 0;
}

void ArrayBasedQueue::enqueue(const int data)
{
    if (front == -1 && rear == -1)
    {
        front = rear = 0;
        queue[rear] = data;
        return;
    }

    int nextRear = (rear + 1) % capacity;

    if (nextRear == front)
    {
        std::cout << "Overflow" << std::endl;
        return;
    }

    rear = nextRear;
    queue[rear] = data;
}

int ArrayBasedQueue::dequeue()
{
    if (front == -1)
    {
        std::cout << "Underflow" << std::endl;
        return -1;
    }

    int val = queue[front];

    if (front == rear)
    {
        front = rear = -1;
    }
    else
    {
        front = (front + 1) % capacity;
    }

    return val;
}

int ArrayBasedQueue::peek() const
{
    if (front == -1)
        return -1;

    return queue[front];
}

bool ArrayBasedQueue::isEmpty() const
{
    return (front == -1);
}

int ArrayBasedQueue::getSize() const
{
    if (front == -1)
        return 0;

    if (rear >= front)
        return (rear - front + 1);

    return (capacity - front) + (rear + 1);
}
