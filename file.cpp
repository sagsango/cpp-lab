#include <iostream>
#include <string>

using namespace std;

int main() {
    fstream file("example.txt", ios::in | ios::out | ios::app);
    if (!file) {
        cerr << "File could not be opened!" << endl;
        return 1;
    }
    string line;
    while (getline(file, line)) {
        cout << line << endl;
    }
    file.close();
    return 0;

}