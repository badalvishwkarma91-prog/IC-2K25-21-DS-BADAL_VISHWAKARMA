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

class LinkedList {
public:
    Node* head;

    LinkedList() {
        head = NULL;
    }

    // Find starting node of cycle
    Node* findStartingNode() {
        Node* slow = head;
        Node* fast = head;

        // Detect cycle
        while (fast != NULL && fast->next != NULL) {
            slow = slow->next;
            fast = fast->next->next;

            if (slow == fast) {
                slow = head;

                // Find starting node
                while (slow != fast) {
                    slow = slow->next;
                    fast = fast->next;
                }

                return slow;
            }
        }

        return NULL;
    }
};

int main() {
    LinkedList list;

    Node* first = new Node(10);
    Node* second = new Node(20);
    Node* third = new Node(30);
    Node* fourth = new Node(40);
    Node* fifth = new Node(50);

    list.head = first;

    first->next = second;
    second->next = third;
    third->next = fourth;
    fourth->next = fifth;

    // Creating a cycle
    fifth->next = third;

    Node* result = list.findStartingNode();

    if (result != NULL) {
        cout << "Starting node of cycle is: " << result->data;
    } else {
        cout << "No cycle found";
    }

    return 0;
}
