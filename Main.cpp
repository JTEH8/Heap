#include <iostream>
#include <cstring>
#include "Node.h"

using namespace std;

void addHeap(Node* newNode, Node* & head, Node* array[], int & sizeCount);
void printHeap(Node* head, int space);
void printPostfix(Node* current);
void deleteTree(Node* treeHead);
int main(){
Node* heap[100];
int size = 1;
Node* treeHead = NULL;
int input = 0;
bool running = true;
char input2[100];
while(running == true){
    cout << "Enter an input: (ADD to add, QUIT to quit, and PRINT to print)." << endl;
    cin >> input2;
    if(strcmp(input2, "ADD") == 0){
        cout << "Insert some numbers. If you want to add more than one just type the ADD COMMAND again once you enter a number." << endl;
        cin >> input;
        Node* newNode = new Node(input);
        addHeap(newNode, treeHead, heap, size);
    }
    else if(strcmp(input2, "QUIT") == 0){
        cout << "Thanks for using heap!" << endl;
        running == false;
        return 0;
    }
    else if(strcmp(input2, "PRINT") == 0){
        printHeap(treeHead, 0);
    }
    else{
        cout << "Please enter a valid command." << endl;
    }
}
}

void addHeap(Node* newNode, Node* & head, Node* array[], int & sizeCount){
    if(head == NULL){
        head = newNode;
        array[sizeCount-1] = head;
        sizeCount++;
    }
    else{
        int parentIndex = sizeCount/2;
        Node* parent = array[parentIndex-1];
        Node* current = newNode;
        if(parent->getLeft() == NULL){
            parent->setLeft(newNode);
            array[sizeCount-1] = newNode;
            sizeCount++;
        }
        else{
            parent->setRight(newNode);
            array[sizeCount-1] = newNode;
            sizeCount++;
        }

    while(array[parentIndex-1]->getData() < current->getData()){
        int newData = current->getData();
        current->setData(array[parentIndex-1]->getData());
        array[parentIndex-1]->setData(newData);
        current = array[parentIndex-1];
        if(parentIndex == 1){
            break;
        }
        else{
            parentIndex = parentIndex/2;
        }
    } 
    }
}

void printHeap(Node* head, int space){
    if(head == NULL){
        return;
    }
    //This creates space between levels of the tree
    space = space + 3;

    //Start from the right
    printHeap(head->getRight(), space);

    //Print the current node after a new line
    cout << endl;
    for(int i = 0; i < space; i++){
        cout << " ";
    }
    cout << head->getData() << '\n';
    //Onto the left
    printHeap(head->getLeft(), space);
}

void printPostfix(Node* current){
    if(current == NULL){
        return;
    }
    else{
        cout << current->getData() << endl;
        printPostfix(current->getLeft());
        printPostfix(current->getRight());
    }
}

void deleteTree(Node* treeHead){
    if(treeHead == NULL){
        cout << "NULL!";
        return;
    }
    else{
        Node* current = treeHead;
        while(current != NULL){
            if(current->getRight() != NULL){
                current = current->getRight();
            }
            else if(current->getLeft() != NULL){
                current = current->getLeft();
            }
            else{
                break;
            }
        }
        cout << current->getData() << endl;
        int temp = treeHead->getData();
        treeHead->setData(current->getData());
        delete current;
    }
}