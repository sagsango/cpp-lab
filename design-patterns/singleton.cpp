#include <iostream>
#include <string>

using namespace std;

// copilot: ignore

class Singleton {
    private:
        static Singleton * ptr;
        Singleton() {
            cout << "Singleton instance created." << endl;
        }
        Singleton(const Singleton&) = delete;
        Singleton& operator=(const Singleton&) = delete;
    public:
        static Singleton * getInstance() {
            if (ptr == nullptr) {
                ptr = new Singleton();
            }
            return ptr;
        }
        static void destroy() {
            delete ptr; // This will call the distructor
            ptr = nullptr;
        }
        void log(std::string mesg) {
            cout << mesg << endl;
        }
        ~Singleton() {
            cout << "Singleton instance destroyed." << endl;
        }
};


Singleton * Singleton::ptr = nullptr;

#define N 10

int main() {

    for (int i=0; i<N; ++i) {
        Singleton * logger = Singleton::getInstance();
        logger->log("Hello World, " + to_string(i));
    }

    Singleton::destroy();
}

