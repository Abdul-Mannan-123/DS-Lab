#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int val) {
        data = val;
        next = NULL;
    }
};

class list {
public:
    Node* head;
    Node* tail;

    list() {
        head = NULL;
        tail = NULL;
    }

    void append(int val) {
        Node* new_node = new Node(val);
        if (!head) {
            head = new_node;
            tail = new_node;
            return;
        }
        tail->next = new_node;
        tail = new_node;
    }

    void print_list() {
        if (!head) {
            cout << "Nothing" << endl;
            return;
        }
        Node* temp = head;
        while (temp != NULL) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }

    Node* get_middle(Node* h) {
        if (!h) return h;

        Node* slow = h;
        Node* fast = h->next;

        while (fast != NULL && fast->next != NULL) {
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }

    Node* merge_sort_two_list(Node* l1, Node* l2) {
        if (!l1) return l2;
        if (!l2) return l1;

        Node* result;
        if (l1->data <= l2->data) {
            result = l1;
            result->next = merge_sort_two_list(l1->next, l2);
        } else {
            result = l2;
            result->next = merge_sort_two_list(l1, l2->next);
        }
        return result;
    }

    Node* merge_sort(Node* h) {
        if (!h || !h->next) {
            return h;
        }

        Node* middle = get_middle(h);
        Node* right_part = middle->next;
        middle->next = NULL;

        Node* left = merge_sort(h);
        Node* right = merge_sort(right_part);

        return merge_sort_two_list(left, right);
    }

    void sort_list() {
        head = merge_sort(head);
    }
};

int main() {
    list list_1, list_2;

    list_1.append(2);
    list_1.append(3);
    list_1.append(4);

    list_2.append(9);
    list_2.append(0);
    list_2.append(1);
    list_1.print_list();
    list_2.print_list();

    list_1.sort_list();
    list_2.sort_list();

    cout << "sorted:" << endl;
    list_1.print_list();
    list_2.print_list();

    list sorted_merged;
    sorted_merged.head = sorted_merged.merge_sort_two_list(list_1.head, list_2.head);

    cout << "Merged sorted list:" << endl;
    sorted_merged.print_list();

    return 0;
}
