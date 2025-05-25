

#include <iostream>

int main() {
    std::shared_ptr<int> ptr(new int(10));
    std::cout << *ptr << std::endl;


    std::shared_ptr<int> ptr2 = ptr;

    std::cout << *ptr <<" "<< *ptr2 << std::endl;

    std::cout << "Refcount:" << ptr.use_count() << std::endl;
}