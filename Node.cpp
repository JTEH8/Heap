#include "Node.h"
#include <cstring>
//Constructor
Node::Node(int newData){
data = newData;
next = NULL;
}

//Getters and Setters for Next Nodes and Student data
Node* Node:: getNext(){
    return next;
}

void Node::setNext(Node* newNext){
    next = newNext;
}

int Node:: getData(){
    return data;
}

void Node::setData(int newData){
    data = newData;
}
//Destructor
Node::~Node(){

}