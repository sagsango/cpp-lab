/*
 This file demonstrates the need of virtual destructor in base class
 when we have a pointer of base class pointing to derived class object
 and we delete the pointer of base class.
 If we don't make the destructor of base class virtual, then the destructor
 of derived class will not be called and it will lead to memory leak.
 To avoid this, we should make the destructor of base class virtual.
 This is called as "Virtual Destructor".


 Where there is a virual function; then class have vtable or virtual-table
 table points to correct function to be called, (in case of override)
*/


/*
XXX: Output

07-virtual ❱❱❱ ./virtual-destructor
Bad Use
Base Constructor
Derived Constructor
hello from base!
Base Destructor
Correct Use
Base Constructor
Derived Constructor
hello from drived!
Derived Destructor
Base Destructor
07-virtual ❱❱❱

*/

#include <iostream>
using namespace std;
namespace bad_use {
    class Base {
    public:
        Base() {
            std::cout << "Base Constructor" << std::endl;
        }
        void print() {
            cout << "hello from base!" << endl;
        }
        ~Base() {
            std::cout << "Base Destructor" << std::endl;
        }
    };

    class Derived : public Base {
    public:
        Derived() {
            std::cout << "Derived Constructor" << std::endl;
        }
        void print() {
            cout << "hello from drived!" << endl;
        }
        ~Derived() {
            std::cout << "Derived Destructor" << std::endl;
        }
    };

    void test() {
        Base* b = new Derived();
        b->print();
        delete b;
    }
}

namespace correct_use {
    class Base {
    public:
        Base() {
            std::cout << "Base Constructor" << std::endl;
        }
        virtual void print() {
            cout << "hello from base!" << endl;
        }
        virtual ~Base() {
            std::cout << "Base Destructor" << std::endl;
        }
    };

    class Derived : public Base {
    public:
        Derived() {
            std::cout << "Derived Constructor" << std::endl;
        }
        void print() {
            cout << "hello from drived!" << endl;
        }
        ~Derived() {
            std::cout << "Derived Destructor" << std::endl;
        }
    };

    void test() {
        Base* b = new Derived();
        b->print();
        delete b;
    }
}

int main() {
    std::cout << "Bad Use" << std::endl;
    bad_use::test();
    std::cout << "Correct Use" << std::endl;
    correct_use::test();
    return 0;
}
