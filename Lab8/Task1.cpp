#include <iostream>
using namespace std;

class Node {
    public:
        int data;
        Node * right;
        Node * left;

        Node(int val) {
            data = val;
            right = nullptr;
            left =  nullptr;
        }
};
class Family{
    public:
        Node * child;
        Family (){
            child = nullptr;
        }
        void insert(int val) {
            if (child == nullptr && val == 1) {
                child = new Node(val);
                return;
            }
            else{
                cout << "child already exist" << endl;
                return;
            }
        }

        void insert_parent(int val) {
            if (val >= 10 && val != 1 ) {
                Node * temp = child;
                while (temp -> right != nullptr) {
                    temp = temp -> right;
                }
                temp -> right = new Node(val);
                cout << "inserted father" << endl;
                return;
            }
            else if (val < 10 && val != 1){
                Node * temp = child;
                while (temp -> left != nullptr) {
                    temp = temp -> left;
                }
                temp -> left = new Node(val);
                cout << "inserted mother" << endl;
                return;
            }
        }

};
