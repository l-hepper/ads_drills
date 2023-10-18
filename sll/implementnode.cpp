#include <iostream>
using namespace std;

// TODO - Construct a Node class which the SLL class can use for its operations
// class Node goes here

// Define a LinkedList class
class LinkedList {
public:
    Node* head;

    LinkedList() : head(NULL) {}

    // Function to insert a node at the beginning of the list
    void insert(int val) {
        Node* newNode = new Node(val);
        newNode->next = head;
        head = newNode;
    }

    // Function to delete the first element
    void deleteFirst() {
        if (head == NULL) {
            cout << "List is empty. Nothing to delete." << endl;
            return;
        }

        Node* temp = head; // store the current node - pointed to by 'head' - to temp so that it can be deleted after head is set to the current 2nd node.
        head = head->next;
        delete temp;
    }

    // Function to print the elements of the list
    void printList() {
        Node* current = head;
        while (current != NULL) {
            cout << current->data << " ";
            current = current->next;
        }
        cout << endl;
    }
};

int main() {
    LinkedList myList;

    // Insert some elements
    myList.insert(3);
    myList.insert(7);
    myList.insert(11);
    myList.insert(5);

    // Print the original list
    cout << "Original List: ";
    myList.printList();

    // Delete the first element
    myList.deleteFirst();

    // Print the updated list
    cout << "List after deletion: ";
    myList.printList();

    return 0;
}
