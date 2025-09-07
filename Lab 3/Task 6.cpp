#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node* child;

    Node(int val) {
        data = val;
        next = NULL;
        child = NULL;
    }
};

Node* flatten(Node* head) {
    if (!head) return NULL;

    Node* curr = head;
    while (curr) {
        if (curr->child) {
            Node* tempNext = curr->next;
            curr->next = curr->child;

            Node* tail = curr->child;
            while (tail->next) tail = tail->next;

            tail->next = tempNext;
            curr->child = NULL;
        }
        curr = curr->next;
    }
    return head;
}

void printList(Node* head) {
    while (head) {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

int main() {
    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);

    head->next->child = new Node(4);
    head->next->child->next = new Node(5);

    cout << "Flattened list: ";
    head = flatten(head);
    printList(head);

    return 0;
}
