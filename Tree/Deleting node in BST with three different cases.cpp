
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

    // Insert node
    Node* insert(Node* root, int value) {
        if (root == NULL)
            return new Node(value);

        if (value < root->data)
            root->left = insert(root->left, value);

        else if (value > root->data)
            root->right = insert(root->right, value);

        return root;
    }

    // Find minimum value
    Node* findMin(Node* root) {
        while (root->left != NULL) {
            root = root->left;
        }
        return root;
    }

    // Delete node
    Node* deleteNode(Node* root, int value) {

        if (root == NULL)
            return root;

        if (value < root->data) {
            root->left = deleteNode(root->left, value);
        }

        else if (value > root->data) {
            root->right = deleteNode(root->right, value);
        }

        else {
            // Case 1: No child
            if (root->left == NULL &&
                root->right == NULL) {
                delete root;
                return NULL;
            }

            // Case 2: One child
            else if (root->left == NULL) {
                Node* temp = root->right;
                delete root;
                return temp;
            }

            else if (root->right == NULL) {
                Node* temp = root->left;
                delete root;
                return temp;
            }

            // Case 3: Two children
            Node* temp = findMin(root->right);

            root->data = temp->data;

            root->right = deleteNode(root->right, temp->data);
        }

        return root;
    }

    // Display (Inorder)
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

    cout << "Before deletion: ";
    tree.display(tree.root);

    tree.root = tree.deleteNode(tree.root, 50);

    cout << "\nAfter deletion: ";
    tree.display(tree.root);

    return 0;
}
