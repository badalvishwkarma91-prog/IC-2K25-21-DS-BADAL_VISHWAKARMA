#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int value) {
        data = value;
        next = NULL;
    }
};

class CircularLinkedList {
public:
    Node* head;

    CircularLinkedList() {
        head = NULL;
    }

    // Insert at end
    void insert(int value) {
        Node* newNode = new Node(value);

        if (head == NULL) {
            head = newNode;
            newNode->next = head;
            return;
        }

        Node* temp = head;

        while (temp->next != head) {
            temp = temp->next;
        }

        temp->next = newNode;
        newNode->next = head;
    }

    // Display list
    void display() {
        if (head == NULL) {
            cout << "List is empty";
            return;
        }

        Node* temp = head;

        do {
            cout << temp->data << " -> ";
            temp = temp->next;
        } while (temp != head);

        cout << "HEAD";
    }
};

int main() {
    CircularLinkedList list;

    list.insert(10);
    list.insert(20);
    list.insert(30);
    list.insert(40);

    list.display();

    return 0;
}
