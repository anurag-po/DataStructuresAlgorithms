#include <iostream>
using namespace std;

struct Node {
    int data;
    Node *left, *right;
    Node(int x) : data(x), left(0), right(0) {}
};

Node* insert(Node* root, int x) {
    if (!root) return new Node(x);
    if (x < root->data) root->left = insert(root->left, x);
    else root->right = insert(root->right, x);
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

int main() {
    Node* root = 0;
    int values[] = {50, 30, 70, 20, 40, 60, 80};

    for (int x : values) root = insert(root, x);

    cout << "Preorder: "; preorder(root);
    cout << "\nInorder: "; inorder(root);
    cout << "\nPostorder: "; postorder(root);
}
