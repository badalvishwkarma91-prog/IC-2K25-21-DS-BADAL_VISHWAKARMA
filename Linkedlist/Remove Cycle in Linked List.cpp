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

    void removeCycle() {
        if (head == nullptr) {
            return;
        }

        Node* slow = head;
        Node* fast = head;

        // Detect cycle
        while (fast != nullptr && fast->next != nullptr) {
            slow = slow->next;
            fast = fast->next->next;

            if (slow == fast) {
                break;
            }
        }

        // No cycle found
        if (fast == nullptr || fast->next == nullptr) {
            cout << "No cycle found" << endl;
            return;
        }

        // Find the starting point of the cycle
        slow = head;

        if (slow == fast) {
            while (fast->next != slow) {
                fast = fast->next;
            }
        } else {
            while (slow->next != fast->next) {
                slow = slow->next;
                fast = fast->next;
            }
        }

        // Remove cycle
        fast->next = nullptr;

        cout << "Cycle removed successfully" << endl;
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
    list.insertAtEnd(50);

    // Create a cycle: 50 points back to 30
    list.head->next->next->next->next->next =
        list.head->next->next;

    list.removeCycle();

    cout << "Linked List after removing cycle: ";
    list.display();

    return 0;
}
