#include <iostream>
using namespace std;

class SNode {
public:
    int data;
    SNode* next;

    SNode(int val) {
        data = val;
        next = NULL;
    }
};

class SinglyList {
public:
    SNode* head;
    SNode* tail;

    SinglyList() {
        head = NULL;
        tail = NULL;
    }

    void insert_at_end(int val) {
        SNode* n = new SNode(val);
        if (!head) {
            head = tail = n;
        } else {
            tail->next = n;
            tail = n;
        }
    }

    void display() {
        SNode* temp = head;
        while (temp) {
            cout << temp->data << " ";
            temp = temp->next;
        }
    }
};


class DNode {
public:
    int data;
    DNode* next;
    DNode* prev;

    DNode(int val) {
        data = val;
        next = prev = NULL;
    }
};

class DoublyList {
public:
    DNode* head;
    DNode* tail;

    DoublyList() {
        head = tail = NULL;
    }

    void insert_at_end(int val) {
        DNode* n = new DNode(val);
        if (!head) {
            head = tail = n;
        } else {
            tail->next = n;
            n->prev = tail;
            tail = n;
        }
    }

    void display_forward() {
        DNode* temp = head;
        while (temp) {
            cout << temp->data << " ";
            temp = temp->next;
        }
    }
};

class CircularList {
public:
    SNode* head;

    CircularList() {
        head = NULL;
    }

    void insert_at_end(int val) {
        SNode* n = new SNode(val);
        if (!head) {
            head = n;
            head->next = head;
        } else {
            SNode* temp = head;
            while (temp->next != head) {
                temp = temp->next;
            }
            temp->next = n;
            n->next = head;
        }
    }

    void display(int count) {
        if (!head) return;
        SNode* temp = head;
        for (int i = 0; i < count; i++) { 
            cout << temp->data << " -> ";
            temp = temp->next;
        }
        cout << "... (circular)\n";
    }
};

DoublyList convertToDoubly(SinglyList& s) {
    DoublyList d;
    SNode* temp = s.head;
    while (temp) {
        d.insert_at_end(temp->data);
        temp = temp->next;
    }
    return d;
}
CircularList convertToCircular(SinglyList& s) {
    CircularList c;
    SNode* temp = s.head;
    while (temp) {
        c.insert_at_end(temp->data);
        temp = temp->next;
    }
    return c;
}

int main() {
    SinglyList s;
    s.insert_at_end(10);
    s.insert_at_end(20);
    s.insert_at_end(30);
    s.insert_at_end(40);

    cout << "Original Singly Linked List:\n";
    s.display();
    DoublyList d = convertToDoubly(s);
    cout << "\nConverted to Doubly Linked List:\n";
    d.display_forward();
    CircularList c = convertToCircular(s);
    cout << "\nConverted to Circular Linked List:\n";
    c.display(10);

    return 0;
}
