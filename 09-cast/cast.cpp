#include <iostream>

using namespace std;

class Base {
    public:
    Base() {
        cout << "Base()" << endl;
    }
    virtual void print() {
        cout << "Hello from Base" << endl;
    }
    ~Base() {
        cout << "~Base()" << endl;
    }
};

class Derived: public Base {
    public:
    Derived() {
        cout << "Derived()" << endl;
    }
    void print() {
        cout << "Hello from Drived" << endl;
    }
    ~Derived() {
        cout << "~Derived()" << endl;
    }
};

int main() {
    Base * ptr = static_cast<Base*>(new Derived());
    ptr->print();

    /* Runtime check for the typecst is a valid or not*/
    Base * ptr2 = dynamic_cast<Base*>(new Derived());
    ptr2->print();
}