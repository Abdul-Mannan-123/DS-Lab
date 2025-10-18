#include <iostream>
using namespace std;

class Process {
public:
    int id, priority;
    Process() { id = priority = 0; }
    Process(int i, int p) { id = i; priority = p; }
};

class JobSystem {
    Process queue[100];
    Process stack[100];
    int qFront, qRear, sTop;
public:
    JobSystem() { qFront = qRear = 0; sTop = -1; }

    void addProcess(int id, int priority) {
        queue[qRear++] = Process(id, priority);
        cout << "Process " << id << " added with priority " << priority << "\n";
    }

    void execute() {
        for (int i = qFront; i < qRear; i++)
            if (queue[i].priority > 5)
                stack[++sTop] = queue[i];
        cout << "Executing high priority tasks (LIFO):\n";
        while (sTop >= 0)
            cout << "Process ID " << stack[sTop--].id << " executed\n";
        cout << "Remaining processes (FIFO):\n";
        for (int i = qFront; i < qRear; i++)
            if (queue[i].priority <= 5)
                cout << "Process ID " << queue[i].id << " executed\n";
    }
};

int main() {
    JobSystem js;
    js.addProcess(1, 3);
    js.addProcess(2, 8);
    js.addProcess(3, 6);
    js.addProcess(4, 2);
    js.execute();
}
