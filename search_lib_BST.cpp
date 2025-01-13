#include<iostream>
#include<fstream>
#include<sstream>

using namespace std;
#include "search_lib_BST.h"

Node :: Node() {
	this->data = 0;
	index = 0;
	left = NULL;
	right = NULL;
}

Node::Node(int value , int index) {
	this->data = value;
	this->index = index;
	left = NULL;
	right = NULL;
}

Node::Node(int value) {
    this->data = value;
    index = 0;
    left = NULL;
    right = NULL;
}

Node* createNode() {
    return NULL; 
}


/*
Function: printTree
Process: Prints the data in preorder traversal.
Input data (parameter):- root: Pointer to the root node of the binary tree.
Output data (parameter): None
Output data (return): None
Dependencies: None
Complexity:
  - Time complexity: O(n)
*/
void printTree(Node* root) {
    if (root == NULL) {
        return;
    }

    cout << root->data << " ";
    printTree(root->left);
    printTree(root->right);
}

/*
Function: addNode
Process: Adds a new node to a binary search tree (BST).
Input data (parameter): root , data ,index
Output data (parameter): None
Output data (return):
  - Pointer to the root node of the modified BST after adding the new node.
Dependencies: None
Complexity:
  - Time complexity: O(log n) for a balanced BST, O(n) in the worst case for an unbalanced BST.
*/

Node* addNode(Node* root, long int data, int index) {
    if (root == NULL) {
        return new Node(data, index);
    }

    if (data <= root->data) { 
        root->left = addNode(root->left, data, index);
    }
    else {
        root->right = addNode(root->right, data, index);
    }

    return root;
}

/*
Function: getData
Process: Reads data from a file and populates a binary search tree (BST) with the data.
Input data (parameter): fileName (string) 
Output data (parameter): None
Output data (return): Node* - pointer to the root of the populated BST
Dependencies: addNode
Complexity: Time complexity O(nlogn) for inserting n elements into a BST
*/
Node* getData(const string fileName) {
    Node* root = NULL;
    ifstream file(fileName);
    if (file.is_open()) {
        string line;
        int index = 1;
        while (getline(file, line)) {
            istringstream iss(line);
            long int value;
            if (iss >> value) {
                if (index == 1) {
                    root = new Node(value, index);
                }
                else {
                    addNode(root, value, index);
                }
                index++;
            }
        }
    }
    else {
        cout << "Failed to open file " << fileName << endl;
        return NULL;
    }
    file.close();
    cout << "Successfully Read From File." << endl;
    return root;
}

/*
Function: saveData
Process: Saves data from a binary search tree (BST) to a file in preorder traversal.
Input data (parameter): fileName (string), root (Node*) 
Output data (parameter): None
Output data (return): None
Dependencies: savePreorder
Complexity: Time complexity O(n) - where n is the number of nodes in the BST
*/
void saveData(const string fileName, Node* root) {
    ofstream file(fileName);
    if (file.is_open()) {
        savePreorder(root, file);
    }
    else {
        cout << "Failed to open file " << fileName << endl;
        return;
    }
    file.close();
}

/*
Function: savePreorder
Process: Saves data from a binary search tree (BST) to a file in preorder traversal.
Input data (parameter): root (Node*), file (ofstream&) 
Output data (parameter): None
Output data (return): None
Dependencies: None
Complexity: Time complexity O(n) - where n is the number of nodes in the BST
*/
void savePreorder(Node* root, ofstream& file) {
    if (root == NULL) {
        return;
    }

    file << root->data << endl;
    savePreorder(root->left, file);
    savePreorder(root->right, file);
}

/*
Function: getFirstOccurrence
Process: Finds the index of the first occurrence of a given element in a binary search tree (BST).
Input data (parameter): element (long int), root (Node*)
Output data (parameter): None
Output data (return): index (int)
Dependencies: searchFirstOccurrence function
Complexity: Time complexity O(log n) in a balanced BST, O(n) in an unbalanced BST
*/
int getFirstOccurrence(long int element, Node* root) {
    if (root == NULL) {
        cout << "Tree is empty." << endl;
        return -1; 
    }

    int index = -1;

    searchFirstOccurence(root, element, index);

    return index;
}

/*
Function: searchFirstOccurrence
Process: Recursively searches for the first occurrence of a given element in a binary search tree (BST).
Input data (parameter): node (Node*), element (long int), index (int&) 
Output data (parameter): index (int&) - updated index if the element is found
Output data (return): None
Dependencies: None
Complexity: Time complexity O(log n) in a balanced BST, O(n) in an unbalanced BST
*/
void searchFirstOccurence(Node* node, long int element, int& index) {
    if (node == NULL) {
        return;
    }

    if (node->data == element) {
        index = node->index;
        return;
    }
    else if (element < node->data) {
        searchFirstOccurence(node->left, element, index);
    }
    else {
        searchFirstOccurence(node->right, element, index);
    }
}

/*
Function: getLastOccurrence
Process: Finds the last occurrence of a given element in a binary search tree (BST).
Input data (parameter): root (Node*), element (long int)
Output data (parameter): None
Output data (return): index (int) - index of the last occurrence of the element, or -1 if the tree is empty or the element is not found
Dependencies: searchLastOccurrence function
Complexity: Time complexity O(log n) in a balanced BST, O(n) in an unbalanced BST
*/
int getLastOccurrence(long int element, Node* root) {
    if (root == NULL) {
        cout << "Tree is empty." << endl;
        return -1;
    }

    int index = -1;

    searchLastOccurence(root, element, index);

    return index; 
}


/*
Function: searchLastOccurrence
Process: Recursively searches for the last occurrence of a given element in a binary search tree (BST).
Input data (parameter): node (Node*), element (long int), index (int&)
Output data (parameter): index (int&) - updated index of the last occurrence, or -1 if not found
Output data (return): None
Dependencies: None
Complexity: Time complexity O(log n) in a balanced BST, O(n) in an unbalanced BST 
*/
void searchLastOccurence(Node* node, long int element, int& index) {
    if (node == NULL) {
        return;
    }

    searchLastOccurence(node->left, element, index);
    if (node->data == element && index == -1) {
        index = node->index; 
        return; 
    }
    searchLastOccurence(node->right, element, index);
}

/*
Function: getAllOccurrences
Process: Counts and stores all occurrences of a given element in a binary search tree (BST).
Input data (parameter): element (long int) ,root (Node*), (int*) ,(int*)
Output data (parameter): occurrences (int*) - updated array containing indices of occurrences
                        numOccurrences (int*) - updated number of occurrences found
Output data (return): None
Dependencies: findAllOccurrences function
Complexity: Time complexity O(log n) in a balanced BST, O(n) in an unbalanced BST 
*/
void getAllOccurrences(long int element, Node* root, int* occurrences, int* numOccurrences) {
    if (root == NULL) {
        cout << "Tree is empty." << endl;
        return;
    }

    *numOccurrences = 0;
    findAllOccurrences(root, element, occurrences, numOccurrences);
}

/*
Function: findAllOccurrences
Process: Recursively finds all occurrences of a given element in a binary search tree (BST) and stores their indices in an array.
Input data (parameter): node (Node*) - pointer to the current node being processed
                        element (long int), occurrences (int*) ,numOccurrences (int*)
Output data (parameter): occurrences (int*) - updated array containing indices of occurrences
                        numOccurrences (int*) - updated number of occurrences found
Output data (return): None
Dependencies: None
Complexity: Time complexity O(log n) in a balanced BST, O(n) in an unbalanced BST
*/
void findAllOccurrences(Node* node, long int element, int* occurrences, int* numOccurrences) {
    if (node == NULL) {
        return;
    }
    if (node->data == element) {
        occurrences[*numOccurrences] = node->index;
        (*numOccurrences)++;
    }
    findAllOccurrences(node->left, element, occurrences, numOccurrences);
    findAllOccurrences(node->right, element, occurrences, numOccurrences);
}


/*
Function: validateTree
Process: Validates if a binary search tree (BST) is correctly structured
Input data (parameter): root (Node*) 
Output data (parameter): None
Output data (return): bool - true if the BST is valid, false otherwise
Dependencies: Stack class, Node class
Complexity: Time complexity O(n)
*/

bool validateTree(Node* root) {
    if (root == NULL) {
        cout << "Tree is empty. Valid BST." << endl;
        return true; 
    }

    Stack s;
    Node* current = root;
    Node* previous = NULL;

    while (current != NULL || !s.isEmpty()) {
        while (current != NULL) {
            s.push(current);
            current = current->left;
        }

        current = s.peek();

        
        if (previous != NULL && current->data <= previous->data) {
            cout << "BST Violation: " << current->data << " <= " << previous->data << endl;
            return false;
        }
        previous = current;
        if (current != NULL) {
            current = current->right;
        }

        s.pop(); 
    }

    cout << "Valid BST." << endl;
    return true;
}

Stack::Stack() {
    top = nullptr;
}

bool Stack::isEmpty() {
    return top == nullptr;
}

void Stack::push(Node* value) {
    StackNode* newNode = new StackNode;
    newNode->data = value;
    newNode->next = top;
    top = newNode;
}

Node* Stack::peek() {
    if (isEmpty()) {
        cout << "Stack is empty. No top element." << endl;
        return nullptr;
    }
    return top->data;
}

void Stack::pop() {
    if (isEmpty()) {
        cout << "Stack is empty. Cannot pop an element." << endl;
        return;
    }
    StackNode* temp = top;
    top = top->next;
    delete temp;
}

Stack::~Stack() {
    while (!isEmpty()) {
        pop();
    }
}


