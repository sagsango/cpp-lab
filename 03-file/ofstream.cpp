#include <cstdlib>
#include <fstream>
#include <iostream>
#include <string>
#include <vector>

#define FILE_NAME "example-out.txt"
int main() {
    std::ofstream fout(FILE_NAME);
    if (!fout) {
        exit(EXIT_FAILURE);
    } 
    std::vector <std::string> names = {"Hello", "Hi"};
    std::vector <int> ages = {1, 2, 3};

    for (const std::string &name:names) {
        fout << name << std::endl;
    }
    for (const int age: ages) {
        fout << age << std:: endl;
    }
    fout.close();
}
