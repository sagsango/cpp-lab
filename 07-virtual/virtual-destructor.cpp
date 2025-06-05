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
 * XXX: Concept
 * Why there cant be virtual constructor:
1. Virtual Mechanism Requires a Fully Constructed Object
The virtual table (vtable) mechanism used in C++ requires the object to be fully constructed before dynamic dispatch (virtual function calls) can happen.

During the construction of a base class, the derived part of the object does not yet exist.
Therefore, calling a virtual function (including a hypothetical virtual constructor) at that point wouldn't know which class to dispatch to — because the derived class's vtable isn't set up yet.

2. Constructor's Purpose vs Virtual Dispatch
A constructor’s job is to build the object from the ground up — starting from the base class and going toward the most derived class.

Virtual functions are for polymorphism — to allow different behaviors depending on the actual object type.
But before the constructor completes, C++ doesn’t yet know the final "most derived" type, so virtual dispatch doesn’t work reliably.
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
