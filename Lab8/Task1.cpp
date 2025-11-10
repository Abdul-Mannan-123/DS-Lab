#include <iostream>
#include <queue>
using namespace std;

class Node {
public:
    string name;
    Node* left;  
    Node* right; 

    Node(string n) {
        name = n;
        left = right = nullptr;
    }
};

class Family {
private:
    Node* root; 

public:
    Family() {
        root = nullptr;
    }

    Node* createMember(string name) {
        return new Node(name);
    }
    void setRoot(string name) {
        root = new Node(name);
    }
    void addParents(Node* child, string parent1, string parent2) {
        child->left = new Node(parent1);
        child->right = new Node(parent2);
    }
    Node* getRoot() {
        return root;
    }
    void printLeafNodes(Node* node) {
        if (!node) return;

        if (!node->left && !node->right) {
            cout << node->name << " ";
            return;
        }

        printLeafNodes(node->left);
        printLeafNodes(node->right);
    }

    int height(Node* node) {
        if (!node) return 0;
        return 1 + max(height(node->left), height(node->right));
    }
    void printLevels(Node* node) {
        if (!node) return;

        queue<pair<Node*, int>> q;
        q.push({node, 1});

        while (!q.empty()) {
            auto current = q.front();
            q.pop();

            cout << current.first->name << " is at level " << current.second << endl;

            if (current.first->left)
                q.push({current.first->left, current.second + 1});
            if (current.first->right)
                q.push({current.first->right, current.second + 1});
        }
    }
};

int main() {
    Family f;

    f.setRoot("You");
    Node* child = f.getRoot();
    f.addParents(child, "Father", "Mother");
    f.addParents(child->left, "Grandfather (P)", "Grandmother (P)");
    f.addParents(child->right, "Grandfather (M)", "Grandmother (M)");
    cout << "Root (Youngest): " << f.getRoot()->name << endl;
    cout << "Leaf Nodes (Oldest Ancestors): ";
    f.printLeafNodes(f.getRoot());
    cout << endl;
    cout << "Height of Tree: " << f.height(f.getRoot()) << endl;
    cout << "\nLevel of Each Member:\n";
    f.printLevels(f.getRoot());

    return 0;
}
