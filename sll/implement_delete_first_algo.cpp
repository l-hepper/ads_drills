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
class LinkedList {
public:
    Node* head;

    LinkedList() : head(NULL) {}

    // Function to insert an element into first position
    void insertFirst(int val) {
        Node* newNode = new Node(val);
        newNode->next = head;
        head = newNode;
    }

    // TODO - implement the 'deleteFirst' algorithm which should delete the first element in the linked list - bonus: what is the time complexity of this algorithm?
    // write code below
    //
    //

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
