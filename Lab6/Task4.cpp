#include <iostream>
using namespace std;

class CircularQueue {
    int arr[5];
    int front, rear, size;
public:
    CircularQueue() { front = rear = size = 0; }

    void enqueue(int x) {
        if (size == 5) cout << "Queue Full\n";
        else {
            arr[rear] = x;
            rear = (rear + 1) % 5;
            size++;
        }
    }

    void dequeue() {
        if (size == 0) cout << "Queue Empty\n";
        else {
            cout << "Dequeued: " << arr[front] << "\n";
            front = (front + 1) % 5;
            size--;
        }
    }

    void display() {
        if (size == 0) cout << "Queue Empty\n";
        else {
            cout << "Circular Queue: ";
            int i = front;
            for (int c = 0; c < size; c++) {
                cout << arr[i] << " ";
                i = (i + 1) % 5;
            }
            cout << "\n";
        }
    }
};

int main() {
    CircularQueue cq;
    cq.enqueue(10);
    cq.enqueue(20);
    cq.enqueue(30);
    cq.enqueue(40);
    cq.enqueue(50);
    cq.display();
    cq.dequeue();
    cq.enqueue(60);
    cq.display();
}
