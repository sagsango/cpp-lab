#include <iostream>

int main() {
    std::function<int(int)> squre = [&](int x) {
        return x * x;
    };

    std:: cout << squre(10) << std::endl;
}
