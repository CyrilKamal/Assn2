#include <iostream>
#include <thread>
#include <chrono>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
using namespace std;

#define PRERELEASE

struct STUDENT_DATA {             // Structure declaration
    string firstName;         // Member (string variable)
    string lastName;   // Member (string variable)

#ifdef PRERELEASE
    string email;
#endif // PRERELEASE


};       // Structure variable


int main() {
#ifdef PRERELEASE
    cout << "Regular code running -- PreRelease Version" << endl;
    ifstream myfile("StudentData_Emails.txt");
#else
    cout << "Regular code running" << endl;
    ifstream myfile("StudentData.txt");
#endif // 
    vector <STUDENT_DATA> collected;
    string line;

    while (getline(myfile, line))
    {
        stringstream ss(line);

        STUDENT_DATA temp;

        string fname, lname, email;
        getline(ss, fname, ',');
        temp.firstName = fname;
        getline(ss, lname, ',');
        temp.lastName = lname;
#ifdef PRERELEASE
        getline(ss, email, ',');
        temp.email = email;
#endif // PRERELEASE

        collected.push_back(temp);
    }
#ifdef _DEBUG
    for (int i = 0; i < collected.size(); i++)
    {
        cout << collected[i].firstName << " " << collected[i].lastName << endl;
    }
#endif // DEBUG

}