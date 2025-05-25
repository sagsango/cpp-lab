

#include <iostream>

int main() {
    std::unique_ptr<int> ptr(new int(10));
    std::cout << *ptr << std::endl;
}