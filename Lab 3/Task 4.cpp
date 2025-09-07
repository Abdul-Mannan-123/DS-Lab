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

class circular {
	public:
	Node * head;
	Node * tail;
	
	circular () {
		head = NULL;
		tail = NULL;
	}
	void insert_at_end(int val) {
		Node * n = new Node(val);
		if (head == NULL) {
			head = n;
			tail = n;
			tail -> next = head;
			return;
		}
		tail -> next = n;
		n -> next = head;
		tail = n;
	}
	void insert_at_head (int val) {
		Node * n = new Node(val);
		if (head == NULL) {
			head = n;
			tail = n;
			tail -> next = head;
			return;
		}
		n -> next = head;
		tail -> next = head;
		head = n;
	}
	int josephus(int k) {
	    if (head == NULL) return -1;        
	    if (k <= 0) return -1;        
	
	    Node* curr = head;
	    Node* prev = tail;            
	    while (curr->next != curr) {
	        for (int i = 1; i < k; ++i) {
	            prev = curr;
	            curr = curr->next;
	        }
	       cout << "Eliminated: " << curr->data << endl;
	        prev->next = curr->next;
	        if (curr == head) head = curr->next;
	        if (curr == tail) tail = prev;
	        delete curr;
	        curr = prev->next;
	    }
	    	return curr->data;
	}

};

int main() {
    int k = 3;
    circular cl;
    for (int i = 1; i < 7; i++) {
        cl.insert_at_end(i);
    }
    int survivor = cl.josephus(k);
    cout << "Survivor: " << survivor << endl;
}
