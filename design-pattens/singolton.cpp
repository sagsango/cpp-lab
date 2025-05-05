#include <iostream>
using namespace std;


class Singleton {
    private:
    static Singleton * instance;
    Singleton() {
        cout << "Constructor called" << endl;
    }
    ~Singleton() {
        cout << "Destructor called" << endl;
    }
    Singleton(const Singleton &) = delete;
    Singleton & operator=(const Singleton &) = delete;
    public:
    static Singleton * getInstance() {
        if (instance == nullptr) {
            instance = new Singleton();
        }
        return instance;
    }
    void showMessage() {
        cout << "Hello World!" << endl;
    }
};

Singleton * Singleton::instance = nullptr;


int main() {
    Singleton * s = Singleton::getInstance();
    s->showMessage();
    return 0;
}