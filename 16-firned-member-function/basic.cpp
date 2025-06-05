#include <iostream>
using namespace std;

// Forward Declaration needed
class base;

// Another class in which function is declared
class GFG {
public:
    void GFG_Function(base& obj);
};

// Base class declare a frined
// function of another class
class base {
private:
    int private_variable;

protected:
    int protected_variable;

public:
    base() {
        private_variable = 10;
        protected_variable = 99;
    }

    // Friend function declaration
    friend void GFG::GFG_Function(base&);
};

// Friend function definition
void GFG::GFG_Function(base& obj) {
    cout << "Private Variable: " << 
             obj.private_variable
         << endl;
    cout << "Protected Variable: " << 
             obj.protected_variable << endl;
}

int main() {
    base object1;
    GFG object2;
    object2.GFG_Function(object1);

    return 0;
}
