#include <iostream>
#include <thread>
#include <mutex>
#include <condition_variable>


int sum;

std::mutex mtx;
std::condition_variable cnd;

bool start;

int tf(int a, int b) {
    mtx.lock();
    sum += a;
    sum += b;
    mtx.unlock();
    std::cout << (a + b) << std::endl;
    return a + b;
}
int main() {
    std::thread t1(tf, 10, 20);
    std::thread t2(tf, 10, 20);
    t1.join();
    t2.join();


}