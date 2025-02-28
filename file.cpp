#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <unordered_map>
#include <vector>
#include <algorithm>

using namespace std;

std::unordered_map<std::string, std::string> args;

void parse_cmdline_args(int argc, char * argv[]) {
    for (int i = 1; i < argc; ++i) {
        std::string arg = argv[i];
        size_t pos = arg.find('=');
        if (pos != std::string::npos && arg.substr(0, 2) == "--") {
            std::string key = arg.substr(2, pos - 2); // Remove "--"
            std::string value = arg.substr(pos + 1);  // Extract value
            args[key] = value;
        }
    }
}

void test_basic_in_out() {
    ofstream fout("example_out.txt", ios::out| ios::app);
    ifstream fin("example_in.txt", ios::in);
    if (!fout || !fin) {
        cerr << "File could not be opened!" << endl;
        exit(1);
    }

#ifdef STR_
    string str;
    while (fin >> str) {
        cout << str << endl;
    }
#else
    string line;
    while (getline(fin, line)) {
        cout <<"Line:" << line << endl;
        stringstream sin(line);
        string str;
        while (sin >> str) {
            //const char * ptr = str.c_str();
            //printf("c_str:%s\n", ptr);
            cout << str << endl;
        }
    }
#endif // STR_
    fout << "Hello World" << endl;
    fin.close();
    fout.close();
}

/*
getline:
    istream& getline(istream& is, string& str, char delim);
*/
void test_getline() {
    struct Student {
        int id;
        std::string name;
        int marks;
    };

    std::ifstream file("students.csv");
    std::string line;
    std::vector<Student> students;
    int totalMarks = 0, count = 0, maxMarks = -1;
    std::string topStudent;

    while (std::getline(file, line)) {
        std::stringstream ss(line);
        std::string id, name, marks;

        std::getline(ss, id, ',');
        std::getline(ss, name, ',');
        std::getline(ss, marks, ',');

        int marksInt = std::stoi(marks);
        students.push_back({std::stoi(id), name, marksInt});

        totalMarks += marksInt;
        count++;

        if (marksInt > maxMarks) {
            maxMarks = marksInt;
            topStudent = name;
        }
    }
    file.close();

    for (const Student s:students) {
        cout << s.id <<" "<< s.name <<" " << s.marks << endl;
    }

    // Sort students by marks (descending)
    std::sort(students.begin(), students.end(), [](const Student& a, const Student& b) {
        return a.marks > b.marks;
    });

    std::ofstream outFile("sorted_students.csv");
    for (const auto& student : students) {
        outFile << student.id << "," << student.name << "," << student.marks << "\n";
    }
    outFile.close();

    std::cout << "Sorted data written to sorted_students.csv\n";
}

int main(int argc, char * argv[]) {
    parse_cmdline_args(argc,argv);
    test_basic_in_out();
    test_getline();
}

