//Header Guard
#ifndef NODE_H
#define NODE_H
#include <iostream>
#include <cstring>

using namespace std;
//Node Class
class Node{
public:
//Variables
int data;
Node* left;
Node* right;
//Constructor
Node(int newData);
//Destructor
~Node();
//Getters and Setters for Nodes
Node* getRight();
void setRight(Node* newRight);
Node* getLeft();
void setLeft(Node* newLeft);
//Getters and setters for Student data
int getData();
void setData(int newData);
};

#endif