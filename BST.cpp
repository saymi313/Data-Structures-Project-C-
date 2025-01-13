#include<iostream>
using namespace std;
#include "search_lib_BST.h"

int main() {
    int choice = 0;
    Node* root = createNode();
    int element, firstIndex, lastIndex;
    int occurrences[100];
    int numOccurrences = 0;

    while (true) {
        cout << "Please Select the Following Option " << endl;
        cout << "[1] Read From File " << endl;
        cout << "[2] Write into the File " << endl;
        cout << "[3] Print the File " << endl;
        cout << "[4] Check First Occurrence " << endl;
        cout << "[5] Check Last Occurrence " << endl;
        cout << "[6] Check All Occurence " << endl;
        cout << "[7] Validate Tree" << endl;
        cout << "[8] Clear Screen" << endl;
        cout << "[9] Exit" << endl;
        cin >> choice;

        switch (choice) {
        case 1:

            root = getData("myData_CS2001.csv");
            break;

        case 2:

            if (root == NULL) {
                cout << "Tree is Empty. Can not write to the file " << endl;
                break;
            }
            saveData("output.csv", root);
            cout << "BST data saved to output.csv" << endl;
            break;

        case 3:

            cout << "BST elements in preorder traversal:" << endl;
            printTree(root);
            cout << endl;
            break;

        case 4:

            cout << "Enter Element " << endl;
            cin >> element;
            firstIndex = getFirstOccurrence(element, root);
            if (firstIndex != -1) {
                cout << "First occurrence of " << element << " at index: " << firstIndex << endl;
            }
            else {
                cout << "Element " << element << " not found in the BST." << endl;
            }
            break;

        case 5:

            cout << "Enter Element " << endl;
            cin >> element;
            lastIndex = getLastOccurrence(element, root);
            if (lastIndex != -1) {
                cout << "Last occurrence of " << element << " at index: " << lastIndex << endl;
            }
            else {
                cout << "Element " << element << " not found in the BST." << endl;
            }
            break;

        case 6:
           
            cout << "Enter Element " << endl;
            cin >> element;
            getAllOccurrences(element, root, occurrences, &numOccurrences);

            if (numOccurrences > 0) {
                cout << "All occurrences of " << element << ":" << endl;
                for (int i = 0; i < numOccurrences; ++i) {
                    cout << "Index " << occurrences[i] << endl;
                }
            }
            else {
                cout << "Element " << element << " not found in the BST." << endl;
            }
            break;

        case 7:

            if (validateTree(root)) {
                cout << "The tree is a valid BST." << endl;
            }
            else {
                cout << "The tree is not a valid BST." << endl;
            }
            break;

        case 8:

            system("cls");
            break;

        case 9:

            cout << "Exiting......";
            exit(0);

        default:

            cout << "Invalid Option. Enter Again " << endl;
            break;

        }
    }

    return 0;
}



/*saveData("output.csv", root);
    cout << "BST data saved to output.csv" << endl;

    long int searchElement = 232;
    int firstIndex = getFirstOccurrence(searchElement, root);
    int lastIndex = getLastOccurrence(searchElement, root);

    if (firstIndex != -1) {
        cout << "First occurrence of " << searchElement << " at index: " << firstIndex << endl;
    }
    else {
        cout << "Element " << searchElement << " not found in the BST." << endl;
    }

    if (lastIndex != -1) {
        cout << "Last occurrence of " << searchElement << " at index: " << lastIndex << endl;
    }
    else {
        cout << "Element " << searchElement << " not found in the BST." << endl;
    }

    int occurrences[100];
    int numOccurrences = 0;
    getAllOccurrences(searchElement, root, occurrences, &numOccurrences);

    if (numOccurrences > 0) {
        cout << "All occurrences of " << searchElement << ":" << endl;
        for (int i = 0; i < numOccurrences; ++i) {
            cout << "Index " << occurrences[i] << endl;
        }
    }
    else {
        cout << "Element " << searchElement << " not found in the BST." << endl;
    }

    if (validateTree(root)) {
        cout << "The tree is a valid BST." << endl;
    }
    else {
        cout << "The tree is not a valid BST." << endl;
    }*/