/*
This file demonstrate the use of string class in C++.
which includes:
1. length()
2. size()
3. capacity()
4. resize()
5. clear()
6. empty()
7. C++ string to C string
8. C string to C++ string
*/  

#include <iostream>
#include <string>
#include <memory>
#include <cstring>

using namespace std;

void test_basic_string() {
    std::string str = "Hello World";
    std::cout << "String: " << str << std::endl;
    std::cout << "Length: " << str.length() << std::endl;
    std::cout << "Size: " << str.size() << std::endl;
    std::cout << "Capacity: " << str.capacity() << std::endl;
    str.resize(5);
    std::cout << "After Resize: " << str << std::endl;
    str.clear();
    std::cout << "After Clear: " << str << std::endl;
    std::cout << "Is Empty: " << (str.empty() ? "Yes" : "No") << std::endl;
}


void test_c_and_cpp_string() {
    std::string cpp_str = "Hello World";
    const char* c_str = cpp_str.c_str();
    std::cout << "C++ String: " << cpp_str << std::endl;
    std::cout << "C String: " << c_str << std::endl;
    std::string new_cpp_str = c_str;
    std::cout << "New C++ String: " << new_cpp_str << std::endl;

    // printf
    printf("C++ String: %s\n", cpp_str.c_str());
    printf("C String: %s\n", c_str);
    printf("New C++ String: %s\n", new_cpp_str.c_str());
}

/*
find
*/
void test_find() {
    // Searching
    string str = "C++ Programming";
    size_t position = str.find("Programming");
    if (position != string::npos) {
        cout << "Found at position " << position << endl;
    }
    else {
        cout << "Not found" << endl;
    }
    cout << "value_of(string::npos) = " << string::npos << " or "<< (int)string::npos << endl;
}

/*
substr
    (strat_index, length)
    (strat_inex)
*/
void substr_test() {
     // Substrings
     string text = "Hello, World!";
     cout << text << endl;
     string sub = text.substr(7, 5);
     cout << sub << endl;
     sub = text.substr(7);
     cout << sub << endl;
}



int main() {
    test_basic_string();
    test_c_and_cpp_string();

    substr_test();
    test_find();
   
    return 0;
}
