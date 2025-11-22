#include <iostream>
#include <algorithm>
using namespace std;
class Node {
public:
    int data;
    Node* right;
    Node *left;
    int height;
    Node(int val) : data(val), right(nullptr), left(nullptr), height(1) {}
};
class AVLTree {
    private:
    Node* root;
    int height(Node* N) {
        if (N == nullptr)
            return 0;
        int left = height(N->left);
        int right = height(N->right);
        return max(left, right) + 1;
    }
    int getBalance(Node* N) {
        if (N == nullptr)
            return 0;
        return height(N->left) - height(N->right);
    }
    Node* rightRotate(Node* y) {
        Node* x = y->left;
        Node* T2 = x->right;
        x->right = y;
        y->left = T2;
        y->height = height(y);
        x->height = height(x);
        return x;
    }
    Node* leftRotate(Node* x) {
        Node* y = x->right;
        Node* T2 = y->left;
        y->left = x;
        x->right = T2;
        x->height = height(x);
        y->height = height(y);
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
        node->height = height(node);
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
    Node* minValueNode(Node* node) {
        Node* current = node;
        while (current->left != nullptr)
            current = current->left;
        return current;
    }
    Node* deleteNode(Node* root, int key) {
        if (root == nullptr)
            return root;
        if (key < root->data)
            root->left = deleteNode(root->left, key);
        else if (key > root->data)
            root->right = deleteNode(root->right, key);
        else {
            if ((root->left == nullptr) || (root->right == nullptr)) {
                Node* temp = root->left ? root->left : root->right;
                if (temp == nullptr) {
                    temp = root;
                    root = nullptr;
                } else
                    *root = *temp;
                delete temp;
            } else {
                Node* temp = minValueNode(root->right);
                root->data = temp->data;
                root->right = deleteNode(root->right, temp->data);
            }
        }
        if (root == nullptr)
            return root;
        root->height = height(root);
        int balance = getBalance(root);
        if (balance > 1 && getBalance(root->left) >= 0)
            return rightRotate(root);
        if (balance > 1 && getBalance(root->left) < 0) {
            root->left = leftRotate(root->left);
            return rightRotate(root);
        }
        if (balance < -1 && getBalance(root->right) <= 0)
            return leftRotate(root);
        if (balance < -1 && getBalance(root->right) > 0) {
            root->right = rightRotate(root->right);
            return leftRotate(root);
        }
        return root;
    }
public:
    AVLTree() : root(nullptr) {}
    void insert(int key) {
        root = insert(root, key);
        cout << "Inserted " << key << endl;
        int h = height(root);
        cout << "Height after insertion: " << h << endl;
        cout << "Rotations (if any) performed to maintain balance." << endl;
        cout << "Balance factor of root after insertion: " << getBalance(root) << endl;
    }
    void deleteKey(int key) {
        root = deleteNode(root, key);
        cout << "Deleted " << key << endl;
        int h = height(root);
        cout << "Height after deletion: " << h << endl;
        cout << "Rotations (if any) performed to maintain balance." << endl;
        if (root != nullptr)
            cout << "Balance factor of root after deletion: " << getBalance(root) << endl;
        else
            cout << "Tree is empty after deletion." << endl;
    }

};

int main() {
    AVLTree rollnoTree;
    rollnoTree.insert(30);
    rollnoTree.insert(20);
    rollnoTree.insert(40);
    rollnoTree.insert(10);
    rollnoTree.deleteKey(20);
    rollnoTree.deleteKey(40);
    rollnoTree.deleteKey(30);
    
    return 0;
}
