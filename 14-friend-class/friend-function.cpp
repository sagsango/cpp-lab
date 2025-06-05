#include <iostream>
using namespace std;

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
    friend void friendFunction(base& obj);
};


// friend function definition
void friendFunction(base& obj) {
    cout << "Private Variable: " 
         << obj.private_variable << endl;
    cout << "Protected Variable: " 
         << obj.protected_variable << endl;
}

int main() {
    base object1;
    friendFunction(object1);
    return 0;
}
