#include <iostream>
#include <thread>
#include <chrono>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
using namespace std;

struct STUDENT_DATA {             // Structure declaration
    string firstName;         // Member (string variable)
    string lastName;   // Member (string variable)
};       // Structure variable

int main() {
    vector <STUDENT_DATA> collected;
    string line;
    ifstream myfile("StudentData.txt");

    while (getline(myfile, line))
    {
        stringstream ss(line);

        STUDENT_DATA temp;

        string fname, lname;
        getline(ss, fname, ',');
        temp.firstName = fname;
        getline(ss, lname, ',');
        temp.lastName = lname;
        collected.push_back(temp);
    }

}