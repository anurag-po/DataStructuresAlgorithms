#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* children[10];
    int childCount;

    Node(int value) {
        data = value;
        childCount = 0;
    }

    void addChild(Node* child) {
        children[childCount] = child;
        childCount++;
    }
};

void dfs(Node* node) {
    cout << node->data << " ";

    for (int i = 0; i < node->childCount; i++) {
        dfs(node->children[i]);
    }
}

int main() {
    Node* root = new Node(0);

    Node* n1 = new Node(1);
    Node* n2 = new Node(2);
    Node* n3 = new Node(3);
    Node* n4 = new Node(4);
    Node* n5 = new Node(5);

    root->addChild(n1);
    root->addChild(n2);
    root->addChild(n3);

    n1->addChild(n4);
    n1->addChild(n5);

    dfs(root);

    return 0;
}
