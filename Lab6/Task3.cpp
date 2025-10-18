#include <iostream>
using namespace std;

class Queue {
    int arr[100];
    int front, rear;
public:
    Queue() { front = rear = 0; }

    void enqueue(int x) {
        if (rear == 100) cout << "Queue Full\n";
        else arr[rear++] = x;
    }

    void dequeue() {
        if (front == rear) cout << "Queue Empty\n";
        else cout << "Dequeued: " << arr[front++] << "\n";
    }

    void display() {
        if (front == rear) cout << "Queue Empty\n";
        else {
            cout << "Queue (front → rear): ";
            for (int i = front; i < rear; i++) cout << arr[i] << " ";
            cout << "\n";
        }
    }
};

int main() {
    Queue q;
    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    q.display();
    q.dequeue();
    q.display();
}
