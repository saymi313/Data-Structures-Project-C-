#pragma once
#include<iostream>
using namespace std;

class Node {
public :
	long int data;
	int index;
	Node* left;
	Node* right;
	Node();
	Node(int value, int index);
	Node(int value);
};

Node* createNode();
void printTree(Node*);
Node* addNode(Node*, long int, int);
Node* getData(const string fileName);
void saveData(string, Node*);
void savePreorder(Node* root, ofstream& file); // function store that in preorder 
int getFirstOccurrence(long int, Node*);
void searchFirstOccurence(Node* node, long int element, int& index); // function to seach the first duplicate data
int getLastOccurrence(long int, Node*);
void searchLastOccurence(Node* node, long int element, int& index); // Function to find last accourence of duplicate data
void getAllOccurrences(long int element, Node* root, int* occurrences, int* numOccurrences);
void findAllOccurrences(Node* node, long int element, int* occurrences, int* numOccurrences); // Function to find all occurnece 
bool validateTree(Node* root);


// Stack Class to Validate BST tree 
struct StackNode {
    Node* data; 
    StackNode* next;
};

class Stack {
private:
    StackNode* top;
public:
    Stack();
    bool isEmpty();
    void push(Node* value);
    void pop();
    Node* peek(); 
    ~Stack();
};
