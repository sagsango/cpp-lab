#include <iostream>
#include <thread>
#include <mutex>
#include <condition_variable>


int sum;

std::mutex mtx;
std::condition_variable cnd;

bool start;

int tf(int a, int b) {
    {
        std::unique_lock<std::mutex> lock(mtx);
        while (!start) {
            cnd.wait(lock);
        }
        sum += a;
        sum += b;
    }
    std::cout << (a + b) << std::endl;
    return a + b;
}


int main() {
    std::thread t1(tf, 10, 20);
    std::thread t2(tf, 10, 20);
    {
        std::unique_lock<std::mutex> lock(mtx); 
        start = true;
        cnd.notify_all();
    }
    t1.join();
    t2.join();


}