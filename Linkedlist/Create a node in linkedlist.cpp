#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

int main() {
    Node* newNode = new Node;

    newNode->data = 10;
    newNode->next = NULL;

    cout << "Node data: " << newNode->data << endl;

    delete newNode;

    return 0;
}
