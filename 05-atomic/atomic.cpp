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
#include <mutex>
#include <string>
#include <memory>
#include <cstring>
#include <atomic>
#include <thread>


std::atomic<int> num(0);
std::mutex mtx;
int global;

void f() {
    for (int i=0; i<10000000; ++i) {
        {
            std::lock_guard<std::mutex> lock(mtx);
            global += 1;
        }
        {
            num.fetch_add(1, std::__1::memory_order_relaxed);
        }
    }
}

int main() {
    std::thread t1(f);
    std::thread t2(f);

    t1.join();
    t2.join();
 
    //num.fetch_add(1, std::__1::memory_order_acquire);

    std:: cout << global << std::endl;
    std:: cout << num << std::endl;
    
    return 0;
}
