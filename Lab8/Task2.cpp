#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = right = nullptr;
    }
};

class BST {
private:
    Node* root;

    Node* insert(Node* n, int val) {
        if (n == nullptr)
            return new Node(val);

        if (val < n->data)
            n->left = insert(n->left, val);
        else if (val > n->data)
            n->right = insert(n->right, val);

        return n;
    }

    void inorder(Node* n) {
        if (n == nullptr) return;
        inorder(n->left);
        cout << n->data << " ";
        inorder(n->right);
    }


    void postorder(Node* n) {
        if (n == nullptr) return;
        postorder(n->left);
        postorder(n->right);
        cout << n->data << " ";
    }

    bool search(Node* n, int key) {
        if (n == nullptr)
            return false;
        else if (n->data == key)
            return true;
        else if (key < n->data)
            return search(n->left, key);
        else
            return search(n->right, key);
    }

    Node* findMin(Node* n) {
        while (n && n->left != nullptr)
            n = n->left;
        return n;
    }

    Node* deleteNode(Node* n, int key) {
        if (n == nullptr)
            return n;

        if (key < n->data)
            n->left = deleteNode(n->left, key);
        else if (key > n->data)
            n->right = deleteNode(n->right, key);
        else {

            if (n->left == nullptr) {
                Node* temp = n->right;
                delete n;
                return temp;
            }
            else if (n->right == nullptr) {
                Node* temp = n->left;
                delete n;
                return temp;
            }

            Node* temp = findMin(n->right);
            n->data = temp->data;
            n->right = deleteNode(n->right, temp->data);
        }

        return n;
    }

public:
    BST() {
        root = nullptr;
    }

    void insertNode(int val) {
        root = insert(root, val);
    }

    void inorder() {
        inorder(root);
        cout << endl;
    }

    void postorder() {
        postorder(root);
        cout << endl;
    }

    bool searchNode(int key) {
        return search(root, key);
    }

    void deleteNodeValue(int key) {
        root = deleteNode(root, key);
    }
};





int main() {
    BST music;

    music.insertNode(30);
    music.insertNode(10);
    music.insertNode(50);
    music.insertNode(20);
    music.insertNode(40);
    cout << "Inorder (Least → Most played): ";
    music.inorder();
    cout << "Postorder (Reverse removal order): ";
    music.postorder();
    cout << "Searching play count 20: ";
    cout << (music.searchNode(20) ? "Found" : "Not found") << endl;
    music.deleteNodeValue(30);
    cout << "After deleting 30: ";
    music.inorder();

    return 0;
}

