#include <iostream>
using namespace std;

class Node {
    public:
        int data;
        Node* next;
        
        Node(int data) {
            this->data = data;
            this->next = nullptr;
        }
};

// Define a LinkedList class
// Write code here to define the linked list member variables and constructor(s)
//

    // Function to insert an element into first position
    void insertFirst(int val) {
        Node* newNode = new Node(val);
        newNode->next = head;
        head = newNode;
        this->length++;
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
        this->length--;
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

    LinkedList* myLinkedList = new LinkedList(5);
    LinkedList* myLinkyList = new LinkedList();
    cout << myLinkedList->length << endl;
    cout << myLinkyList->length << endl;

    // Insert some elements
    myList.insertFirst(3);
    myList.insertFirst(7);
    myList.insertFirst(11);
    myList.insertFirst(5);

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
