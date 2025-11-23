#include <iostream>
#include <algorithm>
using namespace std;

class Node {
public:
    int data;
    int height;
    Node *left, *right;

    Node(int v) {
        data = v;
        height = 1;
        left = right = nullptr;
    }
};

class AVL {
private:
    Node* root;

    int h(Node* n) { return n ? n->height : 0; }

    int balance(Node* n) { return n ? h(n->left) - h(n->right) : 0; }

    Node* rotateRight(Node* y, string &rot) {
        rot = "LL";
        Node* x = y->left;
        Node* T = x->right;

        x->right = y;
        y->left = T;

        y->height = max(h(y->left), h(y->right)) + 1;
        x->height = max(h(x->left), h(x->right)) + 1;

        return x;
    }

    Node* rotateLeft(Node* x, string &rot) {
        rot = "RR";
        Node* y = x->right;
        Node* T = y->left;

        y->left = x;
        x->right = T;

        x->height = max(h(x->left), h(x->right)) + 1;
        y->height = max(h(y->left), h(y->right)) + 1;

        return y;
    }

    Node* insert(Node* n, int key, string &rot) {
        if (!n) return new Node(key);

        if (key < n->data)
            n->left = insert(n->left, key, rot);
        else if (key > n->data)
            n->right = insert(n->right, key, rot);
        else
            return n;

        n->height = max(h(n->left), h(n->right)) + 1;
        int b = balance(n);

        if (b > 1 && key < n->left->data)
            return rotateRight(n, rot);
        if (b < -1 && key > n->right->data)
            return rotateLeft(n, rot);

        if (b > 1 && key > n->left->data) {
            rot = "LR";
            n->left = rotateLeft(n->left, rot);
            return rotateRight(n, rot);
        }
        if (b < -1 && key < n->right->data) {
            rot = "RL";
            n->right = rotateRight(n->right, rot);
            return rotateLeft(n, rot);
        }
        return n;
    }

    Node* minNode(Node* n) {
        while (n->left) n = n->left;
        return n;
    }

    Node* deleteNode(Node* n, int key, string &rot) {
        if (!n) return n;

        if (key < n->data)
            n->left = deleteNode(n->left, key, rot);
        else if (key > n->data)
            n->right = deleteNode(n->right, key, rot);
        else {
            if (!n->left || !n->right) {
                Node* temp = n->left ? n->left : n->right;
                if (!temp) {
                    temp = n;
                    n = nullptr;
                } else
                    *n = *temp;
                delete temp;
            } else {
                Node* temp = minNode(n->right);
                n->data = temp->data;
                n->right = deleteNode(n->right, temp->data, rot);
            }
        }

        if (!n) return n;

        n->height = max(h(n->left), h(n->right)) + 1;
        int b = balance(n);

        if (b > 1 && balance(n->left) >= 0)
            return rotateRight(n, rot);
        if (b > 1 && balance(n->left) < 0) {
            rot = "LR";
            n->left = rotateLeft(n->left, rot);
            return rotateRight(n, rot);
        }
        if (b < -1 && balance(n->right) <= 0)
            return rotateLeft(n, rot);
        if (b < -1 && balance(n->right) > 0) {
            rot = "RL";
            n->right = rotateRight(n->right, rot);
            return rotateLeft(n, rot);
        }

        return n;
    }

    int maxVal(Node* n) {
        if (!n) return -1;
        while (n->right) n = n->right;
        return n->data;
    }

public:
    AVL() { root = nullptr; }

    void insert(int v) {
        string rot = "NONE";
        root = insert(root, v, rot);
        cout << "H=" << h(root) << " R=" << rot << " MAX=" << maxVal(root) << endl;
    }

    void remove(int v) {
        string rot = "NONE";
        root = deleteNode(root, v, rot);
        cout << "H=" << h(root) << " R=" << rot << " MAX=" << maxVal(root) << endl;
    }
};

int main() {
    AVL T;
    T.insert(50);
    T.insert(30);
    T.insert(70);
    T.insert(60);
    T.insert(80);
    T.remove(70);
    return 0;
}
