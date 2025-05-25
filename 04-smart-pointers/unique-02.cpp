

#include <iostream>


void f(std::unique_ptr<int> ptr) {
    std::cout << *ptr << std::endl;
}
int main() {
    std::unique_ptr<int> ptr(new int(10));
    /*
     * Without move semantic we cant pass unique ptr
     */
    f(std::move(ptr));
}