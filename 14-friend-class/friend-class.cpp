/*
 * XXX:
 *  1. Friend class can access all the private/public/protect members
 *  2. Remember one thing, Friendship is not mutual. 
 *      If class A is a friend of B, then B doesn't become a friend of A automatically.
 *  3. source: https://www.geeksforgeeks.org/friend-class-function-cpp/
 *
 *
 */
#include <iostream>
using namespace std;

class Geeks {
private:
    int private_variable;

protected:
    int protected_variable;

public:
    Geeks() {
        private_variable = 10;
        protected_variable = 99;
    }

    // friend class declaration
    friend class GFG;
};

// class GFG is declared as a friend
// inside class Geeks, therefore
// Class GFG can access private members
// of class Geeks.
class GFG {
public:
    void display(Geeks& t) {
        cout << "The value of Private Variable = "
             << t.private_variable << endl;
        cout << "The value of Protected Variable = "
             << t.protected_variable << endl;
    }
};

int main() {
    Geeks g;
    GFG fri;
    fri.display(g);
    return 0;
}
