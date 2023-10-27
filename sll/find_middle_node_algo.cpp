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
    int length;

    LinkedList() : head(NULL) {}

    LinkedList(int val) {
        this->insertFirst(val);
    }

    // Destructor implementation necessary for a linked list
    ~LinkedList() {
        // First declare a node to store the nodes to be deleted
        Node* current;

        while (head != nullptr) {

            // Assign the current head node to the 'current' node
            current = head;

            // Move head node to the next node
            head = head->next;

            // Delete the current node
            delete current;
        }
    }

    // Implement the function to insert an element at the front of the linked list - bonus: what is the time complexity of this operation?
    void insertFirst(int data) {

        // first the new node is created
        Node* newNode = new Node(data);

        // now the current 'head' address is copied to the newNode's 'next' address
        newNode->next = head;

        // now we point head to the newNode
        head = newNode;

        // increasing length is somewhat optional if the LinkedList has a 'length' variable
        this-length++;
    }

    // Function to delete the first element
        void deleteFirst() {
        if (head == nullptr) {
            cout << "\nThe list is empty" << endl;
            return;
        }

        // Store the address of the current first node in temp to free its memory
        Node* temp = head;

        // Point head to the next node along
        head = head->next;

        // Free the memory of the original first node
        delete temp;

        // Decremement length
        this->length--;
    }

    // Implement the function to 'deleteLast' element in the linked list below
    void deleteLast() {
        if (head == NULL) {
            cout << "The linked list is empty" << endl;
        } else if (head->next == NULL) {
            cout << "There is only one item in the linked list which will now be deleted";
            head = NULL;
        } else {
            Node* current = head;
            Node* pre;
            while (current->next != NULL) {
                pre = current;
                current = current->next;
            }
            delete current;
            pre->next = nullptr;
            length--;
        }
    }

    // Implement the algorithm to return the value at the provided index
    Node* get(int index) {

        // check if the index is out of bounds
        if (index < 0 || index >= length) {
            cout << "Error: Index Out Of Bounds" << endl;
            return nullptr;
        }

        Node* current = head;
        for (int i {0}; i < index; i++) {
            current = current->next;
        }

        return current;

    }

    // Implement the algorithm to set the value at a particular index to the passed value
    bool set(int index, int value) {
        Node* target = get(index);
        if (target != NULL) {
            target->data = value;
            return true;
        }

        return false;
    }

    // Implement the algorithm to set the value at the passed index to the passed value
    bool insert(int index, int value) {
        if (index < 0 || index >= length) {
            cout << "Index is out of bounds" << endl;
            return false;
        }

        Node* newNode = new Node(value);
        Node* current = head;
        Node* pre;
        for (int i {0}; i < index; i++) {
            pre = current;
            current = current->next;
        }

        newNode->next = current;
        pre->next = newNode;
        return true;
    }

    // Implement the algorithm to delete the node at the given index
    bool deleteNode(int index) {
        if (index < 0 || index >= length) {
            cout << "Index is out of bounds" << endl;
            return false;
        }

        Node* pre;
        Node* current = head;
        for (int i {0}; i < index; i++) {
            pre = current;
            current = current->next;
        }

        pre->next = current->next;
        delete current;
        return true;
    }

    // Implement the algorithm to reverse a linked list
    void reverse() {

        // // store the original head node in a temp variable;
        Node* temp = head;

        // // First, point the head at the last node in the linked list.
        Node* current = head;
        while (current->next != NULL) {
            current = current->next;
        }
        head = current;

        Node* before = nullptr;
        Node* middle = temp;
        Node* after = current->next;
        
        for (int i {0}; i < length; i++) {
            after = middle->next;
            middle->next = before;
            before = middle;
            middle = after;
        }

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

   void append(int value) {
        Node* newNode = new Node(value);

        // If the list is empty, set the new node as the head
        if (head == nullptr) {
            head = newNode;
            return;
        }

        // Iterate over the linked list until the last node is reached
        Node* current = head;
        while (current->next != nullptr) {
            current = current->next;
        }

        // Assign the last node's 'next' variable to the new node
        current->next = newNode;

        // Optionally increase the length variable to reflect the append
        this->length++;
    }

    // Find the middle node of a linked list (using the tortoise and hare algorithm)
    //
    //
    
};

int main() {
    LinkedList myList;

    LinkedList* myLinkedList = new LinkedList(5);
    LinkedList* myLinkyList = new LinkedList();
    cout << myLinkedList->length << endl;
    cout << myLinkyList->length << endl;

    // Insert some elements
    myList.insertFirst(1);
    myList.insertFirst(2);
    myList.insertFirst(3);
    myList.insertFirst(4);
    myList.insertFirst(5);
    myList.insertFirst(6);

    // Print the original list
    cout << "Original List: ";
    myList.printList();

    myList.reverse();

    cout << "Reverse List: ";
    myList.printList();

    return 0;
}
