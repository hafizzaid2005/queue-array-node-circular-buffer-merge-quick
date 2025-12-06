#include "node.h"

Node::Node() 
{
    data = 0;
    next = NULL;
}

Node::~Node() {}

Node::Node(const int data)
{
    this->data = data;
    this->next = NULL;
}

int Node::getData()
{
    return data;
}

Node* Node::getNext()
{
    return next;
}

void Node::setData(const int data)
{
    this->data = data;
}

void Node::setNext(Node* next)
{
    this->next = next;
}
