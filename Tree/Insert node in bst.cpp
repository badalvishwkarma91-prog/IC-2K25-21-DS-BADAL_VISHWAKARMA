
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

    Node* insert(Node* root, int value) {

        // If tree is empty
        if (root == NULL) {
            return new Node(value);
        }

        // Insert in left side
        if (value < root->data) {
            root->left = insert(root->left, value);
        }

        // Insert in right side
        else if (value > root->data) {
            root->right = insert(root->right, value);
        }

        return root;
    }

    void display(Node* root) {
        if (root == NULL)
            return;

        display(root->left);
        cout << root->data << " ";
        display(root->right);
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

    cout << "BST elements: ";
    tree.display(tree.root);

    return 0;
}
