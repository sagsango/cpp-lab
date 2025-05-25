#include <iostream>
#include <vector>
using namespace std;

/*
1. C++ is very bad at exeption handling most of the things dont throw any
excption, so we have to thow that manually.
Ex:
    try {
        int denominator = 0;
        if (denominator == 0)
            throw runtime_error("Division by zero");
        
        int x = 10 / denominator;
        cout << "x = " << x << endl;
    } catch (const exception & e) {
        cout <<"Ex: " << e.what() << endl;
    }



2. ⚠️ Things that do NOT throw by default (UB = undefined Behavior):
Operation                  | Throws exception?
---------------------------|-------------------------------
int x = 10 / 0             | ❌ No (undefined behavior)
Array access arr[5]        | ❌ No (UB if out-of-bounds)
vector[i]                  | ❌ No (UB if i is invalid)
delete                     | ❌ No
nullptr->method()          | ❌ No (UB, segfault)
*/

int main() {
  try {
    std::vector<int> v = {1, 2};
    int x = v.at(10); 
  } catch (const exception &e) {
    cout << "Ex:" << e.what() << endl;
  }
}
