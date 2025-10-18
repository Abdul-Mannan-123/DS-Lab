#include <iostream>
#include <cstring>
using namespace std;

class Node {
public:
    char url[100];
    Node* next;
    Node(const char* u) {
        strcpy(url, u);
        next = NULL;
    }
};

class BrowserHistory {
    Node* top;
public:
    BrowserHistory() { top = NULL; }

    void visit(const char* u) {
        Node* n = new Node(u);
        n->next = top;
        top = n;
        cout << "Visited: " << u << "\n";
    }

    void back() {
        if (!top) cout << "No history\n";
        else {
            cout << "Going back from: " << top->url << "\n";
            Node* t = top;
            top = top->next;
            delete t;
        }
    }

    void showHistory() {
        if (!top) cout << "History empty\n";
        else {
            cout << "History: ";
            Node* p = top;
            while (p) {
                cout << p->url;
                if (p->next) cout << " <- ";
                p = p->next;
            }
            cout << "\n";
        }
    }
};

int main() {
    BrowserHistory h;
    h.visit("google.com");
    h.visit("youtube.com");
    h.visit("github.com");
    h.showHistory();
    h.back();
    h.showHistory();
}
