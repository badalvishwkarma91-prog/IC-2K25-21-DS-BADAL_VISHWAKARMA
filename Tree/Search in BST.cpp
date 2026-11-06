
#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int value) {
        data = value;
        left = NULL;
        right = NULL;
    }
};

class BST {
public:
    Node* root;

    BST() {
        root = NULL;
    }

    // Insert Node
    Node* insert(Node* root, int value) {
        if (root == NULL)
            return new Node(value);

        if (value < root->data)
            root->left = insert(root->left, value);

        else if (value > root->data)
            root->right = insert(root->right, value);

        return root;
    }

    // Search Node
    bool search(Node* root, int key) {

        if (root == NULL)
            return false;

        if (root->data == key)
            return true;

        if (key < root->data)
            return search(root->left, key);

        else
            return search(root->right, key);
    }
};

int main() {
    BST tree;

    tree.root = tree.insert(tree.root, 50);
    tree.root = tree.insert(tree.root, 30);
    tree.root = tree.insert(tree.root, 70);
    tree.root = tree.insert(tree.root, 20);
    tree.root = tree.insert(tree.root, 40);
    tree.root = tree.insert(tree.root, 60);
    tree.root = tree.insert(tree.root, 80);

    int key = 40;

    if (tree.search(tree.root, key))
        cout << "Element Found";
    else
        cout << "Element Not Found";

    return 0;
}
