#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node *left, *right;

    Node(int x) {
        data = x;
        left = 0;
        right = 0;
    }
};

class BST {
private:
    Node* root;

    Node* insert(Node* root, int x) {
        if (!root)
            return new Node(x);

        if (x < root->data)
            root->left = insert(root->left, x);
        else
            root->right = insert(root->right, x);

        return root;
    }

    void preorder(Node* root) {
        if (root) {
            cout << root->data << " ";
            preorder(root->left);
            preorder(root->right);
        }
    }

    void inorder(Node* root) {
        if (root) {
            inorder(root->left);
            cout << root->data << " ";
            inorder(root->right);
        }
    }

    void postorder(Node* root) {
        if (root) {
            postorder(root->left);
            postorder(root->right);
            cout << root->data << " ";
        }
    }

public:
    BST() {
        root = 0;
    }

    void insert(int x) {
        root = insert(root, x);
    }

    void preorder() {
        preorder(root);
    }

    void inorder() {
        inorder(root);
    }

    void postorder() {
        postorder(root);
    }
};

int main() {
    BST tree;

    int values[] = {50, 30, 70, 20, 40, 60, 80};

    for (int x : values)
        tree.insert(x);

    cout << "Preorder: ";
    tree.preorder();

    cout << "\nInorder: ";
    tree.inorder();

    cout << "\nPostorder: ";
    tree.postorder();

    return 0;
}
