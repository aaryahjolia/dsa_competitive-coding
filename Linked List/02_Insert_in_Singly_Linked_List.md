To insert a node in a singly linked list in C++, you can follow the procedures:
 inserting at the beginning, inserting at the end, and inserting at a specific position. Here are the implementations for each scenario:

1. Insert at the Beginning
To insert a node at the beginning of a singly linked list:

#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node(int data) : data(data), next(nullptr) {}
};

class LinkedList {
public:
    Node* head;
    LinkedList() : head(nullptr) {}

    void insertAtBeginning(int data) {
        Node* newNode = new Node(data);
        newNode->next = head;
        head = newNode;
    }

    void printList() {
        Node* current = head;
        while (current) {
            cout << current->data << " -> ";
            current = current->next;
        }
        cout << "None" << endl;
    }
};

// Example usage:
int main() {
    LinkedList ll;
    ll.insertAtBeginning(3);
    ll.insertAtBeginning(2);
    ll.insertAtBeginning(1);
    ll.printList();
    return 0;
}

2. Insert at the End
To insert a node at the end of a singly linked list:


#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node(int data) : data(data), next(nullptr) {}
};

class LinkedList {
public:
    Node* head;
    LinkedList() : head(nullptr) {}

    void insertAtEnd(int data) {
        Node* newNode = new Node(data);
        if (!head) {
            head = newNode;
            return;
        }
        Node* last = head;
        while (last->next) {
            last = last->next;
        }
        last->next = newNode;
    }

    void printList() {
        Node* current = head;
        while (current) {
            cout << current->data << " -> ";
            current = current->next;
        }
        cout << "None" << endl;
    }
};

// Example usage:
int main() {
    LinkedList ll;
    ll.insertAtEnd(1);
    ll.insertAtEnd(2);
    ll.insertAtEnd(3);
    ll.printList();
    return 0;
}
3. Insert at a Specific Position
To insert a node at a specific position in a singly linked list:


#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node(int data) : data(data), next(nullptr) {}
};

class LinkedList {
public:
    Node* head;
    LinkedList() : head(nullptr) {}

    void insertAtPosition(int data, int position) {
        Node* newNode = new Node(data);
        if (position == 0) {
            newNode->next = head;
            head = newNode;
            return;
        }
        Node* current = head;
        for (int i = 0; i < position - 1; ++i) {
            if (!current) {
                throw out_of_range("Position out of bounds");
            }
            current = current->next;
        }
        newNode->next = current->next;
        current->next = newNode;
    }

    void printList() {
        Node* current = head;
        while (current) {
            cout << current->data << " -> ";
            current = current->next;
        }
        cout << "None" << endl;
    }
};

// Example usage:
int main() {
    LinkedList ll;
    ll.insertAtEnd(1);
    ll.insertAtEnd(2);
    ll.insertAtEnd(4);
    ll.insertAtPosition(3, 2);
    ll.printList();
    return 0;
}
In this insertAtPosition function, if the specified position is out of bounds, an out_of_range exception is thrown to handle invalid positions properly. This ensures the robustness of the implementation.