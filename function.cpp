/*
Test the functions
1. with default parameters
3. function overloading
4. function overriding
5. function templates
6. lambda functions
*/

#include <iostream>
#include <string>
#include <memory>
#include <cstring>
#include <vector>
#include <functional> // Needed for std::function
#include <algorithm>

namespace default_parameters {
    class Test {
    public:
        // Member function with a default parameter
        void print(std::string message = "Hello World") {
            std::cout << message << std::endl;
        }
        // Member function with a default parameter
        void print2(std::string message = "Hello World2");

        void test() {
            print();               // Uses default parameter
            print2();
            print("Hello C++");    // Overrides default parameter
        }
    };
     // Member function with a default parameter
     void Test::print2(std::string message) {
        std::cout << message << std::endl;
    }

    // Nonmember function with a default parameter
    void print(std::string message = "Hello World") {
        std::cout << message << std::endl;
    }

    void test_nonmember_function() {
        print();
        print("Hello C++");
    }

    void test_member_function() {
        Test t;
        t.test();
    }

    // This function calls both the nonmember and member tests
    void test() {
        test_nonmember_function();
        test_member_function();
    }
}


namespace function_overloading {
    // Function overloading
    void print(int x) {
        std::cout << "Integer: " << x << std::endl;
    }

    void print(double x) {
        std::cout << "Double: " << x << std::endl;
    }

    void print(std::string x) {
        std::cout << "String: " << x << std::endl;
    }

    void nonmember_test() {
        print(5);
        print(3.14);
        print("Hello C++");
    }


    class Test {
    public:
        // Member function overloading
        void print(int x) {
            std::cout << "Integer: " << x << std::endl;
        }

        void print(double x) {
            std::cout << "Double: " << x << std::endl;
        }

        void print(std::string x) {
            std::cout << "String: " << x << std::endl;
        }

        void member_test() {
            print(5);
            print(3.14);
            print("Hello C++");
        }
    };

    void member_test() {
        Test t;
        t.member_test();    
    }

    void test() {
        nonmember_test();
        member_test();
    }

}


namespace function_overriding {
    class Base {
    public:
        virtual void print() {
            std::cout << "Base class print function" << std::endl;
        }
    };

    class Derived : public Base {
    public:
        void print() override {
            std::cout << "Derived class print function" << std::endl;
        }
    };

    void test() {
        Base b;
        Derived d;

        b.print();  // Calls Base::print
        d.print();  // Calls Derived::print

        /* Here virtual shines */
        Base * ptr = new Derived();
        ptr->print();
    }
}

namespace lemda_function {
    void test() {
        // Lambda function that takes two integers and returns their sum
        auto add = [](int a, int b) { return a + b; };

        std::cout << add(5, 3) << std::endl;  // Output: 8


        // sort with lemda compare function
        std::vector<int> v = {3, 1, 4, 1, 5, 9};
        std::function<int(int, int)> cmp = [&](int a, int b) {
             return a > b; 
        };
        std::sort(v.begin(), v.end(), cmp);
        for (int i : v) {
            std::cout << i << " ";
        }
        std::cout << std::endl;
    }

}



int main() {
    // A vector of pairs: a function to call and a descriptive name
    std::vector<std::pair<std::function<void()>, std::string>> functions = {
        { default_parameters::test, "Default Parameters" },
        { function_overloading::test, "Function Overloading" },
        { function_overriding::test, "Function Overriding" },
        { lemda_function::test, "Lambda Function" },
    };

    // Loop over the functions and run each test
    for (const auto& [func, name] : functions) {
        std::cout << "############### Running: " << name << std::endl;
        func();
        std::cout << std::endl;
    }

    return 0;
}
