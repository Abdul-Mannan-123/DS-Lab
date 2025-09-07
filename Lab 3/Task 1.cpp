#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node(int val){
    	data= val;
		next = nullptr;
    	
	}
};

class LinkedList{
	private:
	    Node* head;
	    
	    Node* reverse(Node* node) {
	        Node* prev = nullptr;
	        Node* curr = node;
	        Node* next = nullptr;
	        while (curr) {
	            next = curr->next;
	            curr->next = prev;
	            prev = curr;
	            curr = next;
	        }
	        return prev;
	    }
	
	public:
	    LinkedList(){
	    	 head = nullptr;
		} 
	
	    void append(int val) {
	        if (!head) {
	            head = new Node(val);
	            return;
	        }
	        Node* temp = head;
	        while (temp->next) temp = temp->next;
	        temp->next = new Node(val);
	    }
	
	    bool isPalindrome() {
	        if (!head || !head->next){
	        	return true;
			} 
	        Node* slow = head;
	        Node* fast = head;
	        while (fast->next && fast->next->next) {
	            slow = slow->next;
	            fast = fast->next->next;
	        }
	
	        Node* secondHalf = reverse(slow->next);
	
	        Node* p1 = head;
	        Node* p2 = secondHalf;
	        while (p2) {
	            if (p1->data != p2->data){
					return false;
			}
	            p1 = p1->next;
	            p2 = p2->next;
	        }
	
	        return true;
	    }
};

int main() {
    LinkedList list;
    list.append(1);
    list.append(2);
    list.append(3);
    list.append(2);
    list.append(1);

    cout << (list.isPalindrome() ? "true" : "false") << endl;
    return 0;
}
