#include <iostream>
using namespace std;

// Implment the node class for a doubly linked list.
class Node {
    public:
        int value;
        Node* next;
        Node* prev;

        Node(int value) {
            this->value = value;
            this->next = nullptr;
            this->prev = nullptr;
        }
};

class DoublyLinkedList {
    public:
        Node* head;
        Node* tail;
        int length;

    public:
        DoublyLinkedList(int value) {
            Node* newNode = new Node(value);
            head = newNode;
            tail = newNode;
            length = 1;
        }

    void printList() {
        Node* current = head;
        while (current != nullptr) {
            cout << current->value << endl;
            current = current->next;
        }
    }

    // Append an item to the end of the DLL
    void append(int value) {

        // first create the new node
        Node* newNode = new Node(value);

        // if the list is empty just point the head and tail at the new node and you're done
        if (length == 0) {
            head = newNode;
            tail = newNode; 

        // otherwise point the tail's node at the new node, and point new node's prev to tail, finally setting tail to point to new node.
        } else {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
        length++;
    }

    // Delete the last element of the DLL
    void deleteLast() {

        // if the length of the list is 0 then nothing to delete just return
        if (length == 0) {
            return;

        // else assign a temp pointer to current tail node
        } else if (length == 1) {
            delete head;
            head = nullptr;
            tail = nullptr;
        }
        
        else {
            Node* temp = tail;

            // set tail to move back one node
            tail = tail->prev;

            // set the new tail's next to null - disconnecting the last node
            tail->next = nullptr;

            // delete the last node;
            delete temp;
        }
        length--;
    }

    // Add a new node to the front of the DLL
    void prepend(int value) {
        Node* newNode = new Node(value);
        if (length == 0) {
            head = newNode;
            tail = newNode;
        } else {
            head->prev = newNode;
            newNode->next = head;
            head = newNode;
        }
        length++;
    }

    // implement the algorithm to delete the first element of the linked list
    void deleteFirst() {
        Node* temp = head;
        if (length == 0) {
            return;
        } else if (length == 1) {
            temp = head;
            head = nullptr;
            tail = nullptr;
        } else {
            head = head->next;
            head->prev = nullptr;
        }
        delete temp;
        length--;
    }

    // typical implementation of 'get' which also works for SLL
    Node* get(int index) {
        Node* target = head;
        if (length == 0) {
            return nullptr;
        } else if (index > length || index < 0) {
            return nullptr;
        } else {
            for (size_t i {0}; i < index; i++) {
                target = target->next;
            }
        }
        return target;
    }

    Node* improvedGet(int index) {
        Node* target {nullptr};
        if (length == 0) {
            return nullptr;
        } else if (index > length - 1 || index < 0) {
            return nullptr;
        } else if (index > (length / 2)) {
            target = tail;
            for (int i {1}; i < length - index; i++) {
                target = target->prev;
            }
        } else {
            target = head;
            for (size_t i {0}; i < index; i++) {
                target = target->next;
            }
        }
        return target;
    }
};

int main() {
    DoublyLinkedList* myDLL = new DoublyLinkedList(10);
    myDLL->append(12);
    myDLL->append(13);
    myDLL->append(14);
    myDLL->append(15);
    myDLL->printList();

    Node *target = myDLL-> improvedGet(3);
    cout << target->value << endl;

    return 0;
}

