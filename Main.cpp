/*
Author: Jeffrey Teh
Date Completed: April 3, 2022
This is an implementation of a max heap (A binary tree where each node is larger than it's child)
Users are able to enter numbers either through direct input or via filename
Help for this project came from Jayden Huang - Thanks to him! :)
*/
#include <iostream>
#include <cstring>
#include <fstream>
#include <math.h>
#include "Node.h"

using namespace std;
//Function Prototypes
void addHeap(Node* newNode, Node* & head, Node* array[], int & sizeCount);
void printHeap(Node* head, int space);
void deleteTree(Node* array[], int size);
//Main method
int main(){
//Initiating variables
Node* heap[100];
int size = 1;
Node* treeHead = NULL;
int input = 0;
bool running = true;
char input2[100];
char input3[100];
char input4[100];
while(running == true){
    //Input prompt
    cout << "Enter an input: (ADD to add, QUIT to quit, DELETE to delete, and PRINT to print)." << endl;
    cin >> input2;
    //When the user adds to the heap
    if(strcmp(input2, "ADD") == 0){
        //Asks if they are entering directly or via file name
        cout << "Would you like to add numbers to the heap via direct input (type INPUT) or via file name (type FILE)?" << endl;
        cin >> input3;
        //Adding through direct input
        if(strcmp(input3, "INPUT") == 0){
        cout << "Insert a number. If you want to add more than one just type the ADD COMMAND again once you enter a number." << endl;
        cin >> input;
        Node* newNode = new Node(input);
        addHeap(newNode, treeHead, heap, size);
        }
    //Add through file name
	else if(strcmp(input3, "FILE") == 0){
        int arr[100];
        int temp = 0;
        cout << "Enter a file name: (e.g. filename.txt)" << endl;
        cin >> input4;
        //Opens the file and adds the numbers into an array
	    fstream nums;
        nums.open(input4);
        for(int i = 0; i < 100; i++){
            nums >> temp;
            //Adds the node to the heap
            Node* newNode = new Node(temp);
            addHeap(newNode, treeHead, heap, size);
	        }
	    }
    }
    //When the user quits
    else if(strcmp(input2, "QUIT") == 0){
        cout << "Thanks for using heap!" << endl;
        running == false;
        return 0;
    }
    //Deletes and prints the heap in order
    else if(strcmp(input2, "DELETE") == 0){
        deleteTree(heap, size-2);
        size = 1;
        treeHead = NULL;
    }
    //Prints the heap
    else if(strcmp(input2, "PRINT") == 0){
        printHeap(treeHead, 0);
    }
    else{
        cout << "Please enter a valid command." << endl;
    }
}
}
//Adding a value to the heap
void addHeap(Node* newNode, Node* & head, Node* array[], int & sizeCount){
    //If the heap is empty, add a new node
    if(head == NULL){
        head = newNode;
        array[sizeCount-1] = head;
        sizeCount++;
    }
    else{
        //As each child has two parents, divide the size by two
        int parentIndex = sizeCount/2;
        Node* parent = array[parentIndex-1];
        Node* current = newNode;
        //If the left is empty, put it there
        if(parent->getLeft() == NULL){
            parent->setLeft(newNode);
            array[sizeCount-1] = newNode;
            sizeCount++;
        }
        //Otherwise add it to the right
        else{
            parent->setRight(newNode);
            array[sizeCount-1] = newNode;
            sizeCount++;
        }
    //Sets up the heap as amax heap from least to greatest
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
//Prints the heap
void printHeap(Node* head, int space){
    if(head == NULL){
        return;
    }
    //This creates space between levels of the tree
    space = space + 10;

    //Start from the right
    printHeap(head->getRight(), space);

    //Print the current node after a new line
    cout << endl;
    for(int i = 0; i < space; i++){
        cout << " ";
    }
    cout << head->getData() << '\n';
    //Onto the left
    if(head->getLeft() != NULL){
    printHeap(head->getLeft(), space);
    }
}
//Deletes the tree
void deleteTree(Node* array[], int size){
    //If the tree is empty
    if(array[0] == NULL){
      cout<< "Nothing to delete!" << endl;
        return;
    }
    //If the size is 0, print the one
    else if(size == 0){
        cout << array[0]->getData() << endl;
        delete array[0];
        array[0] = NULL;
    }
    //Swaps the first and last node if the last node is bigger
    else {
        if(array[0]->getData() > array[size]->getData()){
        int temp = array[size]->getData();
        array[size]->setData(array[0]->getData());
        array[0]->setData(temp);
        }
    int temp2 = size + 1;
    int parentIndex = floor(temp2/2);
    if(array[parentIndex-1]->getLeft() == array[size]){
        array[parentIndex-1]->setLeft(NULL);
        cout << array[size]->getData() << endl;
        delete array[size];
    }
    else if(array[parentIndex-1]->getRight() == array[size]){
        array[parentIndex-1]->setRight(NULL);
        cout << array[size]->getData() << endl;
        delete array[size];
    }
    //After the last node is deleted, the heap is put back into order
    Node* current = array[0];
    while(current->getLeft() != NULL || current->getRight() != NULL){
        //Compares the value of data in child nodes
        //If the left node is larger
        if(current->getLeft2() > current->getRight2()){
            int num = current->getData();
            current->setData(current->getLeft()->getData());
            current->getLeft()->setData(num);
            current = current->getLeft();
        }
        //If the right node is larger
        else if(current->getLeft2() < current->getRight2()){
            int num = current->getData();
            current->setData(current->getRight()->getData());
            current->getRight()->setData(num);
            current = current->getRight();
        }
        else{
            //If two child nodes have the same value
            if(current->getLeft2() != -1){
                int num = current->getData();
                current->setData(current->getLeft2());
                current->getLeft()->setData(num);
                current = current->getLeft();
            }
            else{
               return;
            }
        }
    }
    //Calls itself again on a one-size smaller array
            deleteTree(array, size-1);
        }   
    }
