#include <iostream>
#include <algorithm>
using namespace std;

class Node {
public:
    int data;
    int height;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        height = 1;
        left = right = nullptr;
    }
};

class AVLTree {
private:
    Node* root;

    int height(Node* n) {
        if (n == nullptr) return 0;
        return n->height;
    }

    int getBalance(Node* n) {
        if (n == nullptr) return 0;
        return height(n->left) - height(n->right);
    }

    Node* rightRotate(Node* y) {
        Node* x = y->left;
        Node* T2 = x->right;

        x->right = y;
        y->left = T2;

        y->height = max(height(y->left), height(y->right)) + 1;
        x->height = max(height(x->left), height(x->right)) + 1;

        return x;
    }

    Node* leftRotate(Node* x) {
        Node* y = x->right;
        Node* T2 = y->left;

        y->left = x;
        x->right = T2;

        x->height = max(height(x->left), height(x->right)) + 1;
        y->height = max(height(y->left), height(y->right)) + 1;

        return y;
    }

    Node* insert(Node* node, int key) {
        if (node == nullptr)
            return new Node(key);

        if (key < node->data)
            node->left = insert(node->left, key);
        else if (key > node->data)
            node->right = insert(node->right, key);
        else
            return node; 

        node->height = max(height(node->left), height(node->right)) + 1;

        int balance = getBalance(node);

        if (balance > 1 && key < node->left->data)
            return rightRotate(node);

        if (balance < -1 && key > node->right->data)
            return leftRotate(node);

        if (balance > 1 && key > node->left->data) {
            node->left = leftRotate(node->left);
            return rightRotate(node);
        }

        if (balance < -1 && key < node->right->data) {
            node->right = rightRotate(node->right);
            return leftRotate(node);
        }

        return node;
    }

    void rangeQuery(Node* node, int X, int Y) {
        if (node == nullptr) return;

        if (node->data > X)
            rangeQuery(node->left, X, Y);

        if (node->data >= X && node->data <= Y)
            cout << node->data << " ";

        if (node->data < Y)
            rangeQuery(node->right, X, Y);
    }

public:
    AVLTree() { root = nullptr; }

    void insert(int val) {
        root = insert(root, val);
    }

    void rangeQuery(int X, int Y) {
        
        rangeQuery(root, X, Y);
    }
};

int main() {
    AVLTree tree;
    tree.insert(50);
    tree.insert(30);
    tree.insert(70);
    tree.insert(60);
    tree.insert(80);
    tree.insert(40);
    tree.insert(20);

    int X, Y;
    cout << "Enter range X Y: ";
    cin >> X >> Y;

    tree.rangeQuery(X, Y);

    return 0;
}
