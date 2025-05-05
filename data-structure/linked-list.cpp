/* We wrote exact same code yestaer in Nutanix interview (13 March, 2025)*/
#include <iostream>
#include <memory>

using namespace std;

class Node {
    public :
        Node * next;
        int data;
        Node(int data) {
            this->data = data;
            this->next = nullptr;
        }
};

class LinkedList{
    private:
        Node * head, * tail;
    public:
        LinkedList() {
            head = tail = nullptr;
        }
        bool add(int data) { // O(1)
            Node * node = new Node(data);
            if (node == nullptr) {
                return false;
            }

            if (tail) {
                tail->next = node;
            } else {
                head = node;
            }
            tail = node;
            return true;
        }
        void print() { // O(n)
            Node * cur = head;
            while (cur) {
                cout << cur->data <<" ";
                cur = cur->next;
            }
            cout << endl;
        }
        void reverse() { // O(n)
            Node * new_head, *new_tail, *cur = head, *prv = nullptr;
            new_tail = head;
            while (cur) {
                Node * next = cur->next;
                cur->next = prv;
                prv = cur;
                cur = next;
            }
            new_head = prv;

            head = new_head;
            tail = new_tail;
        }
};

int main() {
    LinkedList l;
    for (int i=0; i<3; ++i) {
        l.add(i);
    }
    l.print();
    l.reverse();
    l.print();
    for (int i=3; i<6; ++i) {
        l.add(i);
    }
    l.print();
}