#include <cstdlib>
#include <iostream>

using namespace std;

namespace baduse {
    class Base {
        public:
        Base() { cout << "Base()" << endl; }
        virtual void print() { cout << "Hello from Base" << endl; }
        ~Base() { cout << "~Base()" << endl; }
    };

    class Derived : public Base {
        public:
        Derived() { cout << "Derived()" << endl; }
        void print() { cout << "Hello from Drived" << endl; }
        ~Derived() { cout << "~Derived()" << endl; }
    };

    int test() {
        Base *ptr = static_cast<Base *>(new Derived());
        ptr->print();

        /* Runtime check for the typecst is a valid or not*/
        Base *ptr2 = dynamic_cast<Base *>(new Derived());
        ptr2->print();

        delete ptr;
        delete ptr2;
        return EXIT_SUCCESS;
    }
} // namespace baduse



namespace gooduse {
    class Base {
        public:
        Base() { cout << "Base()" << endl; }
        virtual void print() { cout << "Hello from Base" << endl; }
        virtual ~Base() { cout << "~Base()" << endl; }
    };

    class Derived : public Base {
        public:
        Derived() { cout << "Derived()" << endl; }
        void print() override { cout << "Hello from Drived" << endl; }
        ~Derived() { cout << "~Derived()" << endl; }
    };

    int test() {
        Base *ptr = static_cast<Base *>(new Derived());
        ptr->print();

        /* Runtime check for the typecst is a valid or not*/
        Base *ptr2 = dynamic_cast<Base *>(new Derived());
        ptr2->print();

        delete ptr;
        delete ptr2;
        return EXIT_SUCCESS;
    }
} // namespace gooduse



int main() {
  std::cout << "BadUse:" << std::endl;
  baduse::test();
  std::cout << "GoodUse:" << std::endl;
  gooduse::test();
}