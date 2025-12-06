#include "ab_circular_buffer.h"

CircularBuffer::CircularBuffer(const int bufferSize)
{
    this->bufferSize = bufferSize;
    buffer = new int[bufferSize];
    for(int i = 0; i < bufferSize; i++)
        buffer[i] = 0;
}

CircularBuffer::CircularBuffer(const CircularBuffer& other)
{
    bufferSize = other.bufferSize;
    buffer = new int[bufferSize];
    for(int i = 0; i < bufferSize; i++)
        buffer[i] = other.buffer[i];
}

CircularBuffer& CircularBuffer::operator = (const CircularBuffer& other)
{
    if(this != &other)
    {
        delete[] buffer;
        bufferSize = other.bufferSize;
        buffer = new int[bufferSize];
        for(int i = 0; i < bufferSize; i++)
            buffer[i] = other.buffer[i];
    }
    return *this;
}

CircularBuffer::~CircularBuffer()
{
    delete[] buffer;
    buffer = NULL;
}

void CircularBuffer::update(const int val)
{
    for(int i = bufferSize - 1; i > 0; i--)
        buffer[i] = buffer[i - 1];
    buffer[0] = val;
}

int CircularBuffer::getLatest() const
{
    return buffer[0];
}

int CircularBuffer::getPrev(const int index) const
{
    int pos = index % bufferSize;
    if(pos < 0) pos += bufferSize;
    return buffer[pos];
}

void CircularBuffer::printBuffer() const
{
    for(int i = 0; i < bufferSize; i++)
        std::cout << buffer[i] << " ";
    std::cout << std::endl;
}

void CircularBuffer::printBufferProperly() const
{
    for(int i = 0; i < bufferSize; i++)
        std::cout << buffer[i] << " ";
    std::cout << std::endl;
}
