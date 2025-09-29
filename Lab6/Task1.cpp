#include <iostream>
using namespace std;
int const MAX = 5;
class stack {
	private:
		int top;
	public:	
		int a[MAX];
		stack() {
			top = -1;
		}
		bool push (int x) {
			if (top >= (MAX	-1))
	 		{
	 			cout << "stack overflow"<< endl;
	 			return false;
			}
			else {
				a[++top] = x;
				cout << x << " pushed into stack"<< endl;
				return true;
			}
		}
		int pop () {
			if (top < 0) {
				cout << "stack underflow" << endl;
				return 0;
			}
			else {
				int x =  a[top--];
				return x;
			}
		}
		int peek () {
			if (top < 0) {
				cout << "stack empty" << endl;
				return 0;
			}
			else {
				int x = a[top];
				return x;
			}
		}
		bool isEmpty (){
			if (top < 0) {
				return true;
			}
			else {
				return false;
			}
		}
		void display() {
			if (top < 0) {
				cout << "stack is empty" << endl;
				return;
			}
			for (int i = 0; i <= top; i++) {
				cout << a[i] << " ";
			}
			cout << "\n" << endl;
		}
};

int main () {
	stack Stack;
	bool a;
	for (int i = 0; i < MAX; i++) {
		a = Stack.push(i);
	}
	Stack.display();
	Stack.pop();
	cout << "is Stack empty? " << Stack.isEmpty() << endl;
	cout << "At top of stack: " << Stack.peek() <<endl;
	Stack.display();
	return 0;
}
