#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int value) {
        data = value;
        next = NULL;
    }
};

class Linked_list {
public:
    Node* head;
    Node* tail;

    Linked_list() {
        head = NULL;
        tail = NULL;
    }
    void insert_at_end(int value) {
        Node* n = new Node(value);
        if (head == NULL) {
            head = n;
            tail = n;
            return;
        }
        tail->next = n;
        tail = n;
    }
    void print_list() {
	    Node* temp = head;
	    while (temp != NULL) {
	        cout << temp->data;
	        if (temp->next != NULL) {
	            cout << " ";
	        }
	        temp = temp->next;
	    }
	    cout << endl;
	}


    Node* reverse_in_size_util(Node* node, int k) {
        Node* curr = node;
        Node* prev = NULL;
        Node* next = NULL;
        int count = 0;

        while (curr != NULL && count < k) {
            next = curr->next;   
            curr->next = prev;
            prev = curr;
            curr = next;
            count++;   
        }
        if (next != NULL) {
            node->next = reverse_in_size_util(next, k);
        }
        return prev;
    }
    void reverse_in_size(int k) {
        head = reverse_in_size_util(head, k);
    }
};
int main() {
    Linked_list list;
    for (int i = 1; i <= 8; i++) {
        list.insert_at_end(i);
    }
    cout << "Original List:" << endl;
    list.print_list();
    int k = 3;
    list.reverse_in_size(k);
    cout << "\nReversed in groups:"<< endl;
    list.print_list();    

    return 0;
}
