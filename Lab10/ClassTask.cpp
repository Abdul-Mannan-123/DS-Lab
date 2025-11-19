#include <iostream>
using namespace std;

class Node {
public:
    int severity;
    int patientID;
    Node* next;

    Node(int val, int pri) {
        patientID = val;
        severity = pri;
        next = nullptr;
    }
};

class PriorityQueue {
private:
    Node* first;

public:
    PriorityQueue() {
        first = nullptr;
    }

    void addpatient(int val, int pr) {
        Node* n = new Node(val, pr);
        if (!first || pr > first->severity || (pr == first->severity && val < first->patientID)) {
            n->next = first;
            first = n;
            return;
        }

        Node* curr = first;
        while (curr->next && (curr->next->severity > pr || (curr->next->severity == pr && curr->next->patientID < val))) {
            curr = curr->next;
        }
        n->next = curr->next;
        curr->next = n;
    }

    void remove() {
        if (!first) {
            cout << "Queue is empty!" << endl;
            return;
        }
        Node* temp = first;
        first = first->next;
        delete temp;
    }

    int next_patient() {
        if (!first) {
            cout << "Queue is empty!" << endl;
            return -1; 
        }
        return first->patientID;
    }

    void printQueue() {
        if (!first) {
            cout << "Queue is empty!" << endl;
            return;
        }
        Node* current = first;
        while (current) {
            cout << "Patient ID: " << current->patientID << ", Severity: " << current->severity << endl;
            current = current->next;
        }
    }
};

int main() {
    PriorityQueue pq;
    pq.addpatient(101, 7);
    pq.addpatient(102, 9);
    pq.addpatient(103, 6);
    pq.addpatient(104, 9);

    cout << "Next patient to treat: " << pq.next_patient() << endl;
    
    pq.printQueue();

    pq.remove();
    cout << "\nAfter removing the highest priority patient:" << endl;
    pq.printQueue();

    return 0;
}
