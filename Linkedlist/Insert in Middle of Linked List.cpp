#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int value) {
        data = value;
        next = nullptr;
    }
};

class LinkedList {
public:
    Node* head;

    LinkedList() {
        head = nullptr;
    }

    void insertAtEnd(int value) {
        Node* newNode = new Node(value);

        if (head == nullptr) {
            head = newNode;
            return;
        }

        Node* current = head;

        while (current->next != nullptr) {
            current = current->next;
        }

        current->next = newNode;
    }

    void insertAtMiddle(int value, int position) {
        if (position < 0) {
            cout << "Invalid position" << endl;
            return;
        }

        if (position == 0) {
            Node* newNode = new Node(value);
            newNode->next = head;
            head = newNode;
            return;
        }

        Node* current = head;

        for (int i = 0; i < position - 1; i++) {
            if (current == nullptr) {
                cout << "Invalid position" << endl;
                return;
            }

            current = current->next;
        }

        if (current == nullptr) {
            cout << "Invalid position" << endl;
            return;
        }

        Node* newNode = new Node(value);
        newNode->next = current->next;
        current->next = newNode;
    }

    void display() {
        Node* current = head;

        while (current != nullptr) {
            cout << current->data << " -> ";
            current = current->next;
        }

        cout << "NULL" << endl;
    }
};

int main() {
    LinkedList list;

    list.insertAtEnd(10);
    list.insertAtEnd(20);
    list.insertAtEnd(30);
    list.insertAtEnd(40);

    cout << "Original Linked List: ";
    list.display();

    list.insertAtMiddle(99, 2);

    cout << "After Insertion: ";
    list.display();

    return 0;
}
