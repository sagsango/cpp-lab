#include <cstdlib>
#include <fstream>
#include <iostream>
#include <string>

#define FILE_NAME "example.txt"
int main() {
    std::ifstream fin(FILE_NAME);
    if (!fin) {
        exit(EXIT_FAILURE);
    } 
    std::string s;
    while (fin >> s) {
        std::cout << s << std::endl;
    }

    fin.close();

}
