/*
Explain the concept of inheritance in C++ using a real-world example of an Employee
Management System. Create a base class Employee and two derived classes Manager and
Developer. Implement functions display_Manager() and display_Developer() to display the
respective details.
*/

#include <iostream>
#include <string>
using namespace std;

class Employee {
protected:
    string name;
    int employeeID;

public:
    Employee(string empName, int id) {
        name = empName;
        employeeID = id;
    }
};

class Manager : public Employee {
private:
    int teamSize;

public:
    Manager(string empName, int id, int size) : Employee(empName, id) {
        teamSize = size;
    }

    void display_Manager() {
        cout << "[Manager] ID: " << employeeID 
                  << " | Name: " << name 
                  << " | Team Size: " << teamSize << "\n";
    }
};

class Developer : public Employee {
private:
    string programmingLanguage;

public:
    Developer(string empName, int id, string lang) : Employee(empName, id) {
        programmingLanguage = lang;
    }

    void display_Developer() {
        cout << "[Developer] ID: " << employeeID 
                  << " | Name: " << name 
                  << " | Core Language: " << programmingLanguage << "\n";
    }
};

int main() {
    cout << "--- Employee Management System ---\n";
    
    Manager mgr("Alice Smith", 101, 15);
    Developer dev("Bob Jones", 102, "C++");

    mgr.display_Manager();
    dev.display_Developer();

    return 0;
}