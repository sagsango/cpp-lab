

#include <iostream>

void f(std::shared_ptr<int> ptr) {
   std::cout << "In f: Refcount:" << ptr.use_count() << std::endl; 
   std::cout << *ptr << std::endl;
}
int main() {
    std::shared_ptr<int> ptr(new int(10));
    std::cout << *ptr << std::endl;


    std::shared_ptr<int> ptr2 = ptr;

    std::cout << *ptr <<" "<< *ptr2 << std::endl;

    std::cout << "In main: Refcount:" << ptr.use_count() << std::endl;

    f(ptr);

    std::cout << "In main: Refcount:" << ptr.use_count() << std::endl;
}