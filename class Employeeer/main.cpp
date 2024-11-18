//
//  main.cpp
//  class Employeeer
//
//  Created by Valeria  Bukova on 18.11.2024.
//

#include <iostream>
using namespace std;

class Employer {
public:
    virtual void Print() const = 0;
    virtual ~Employer() {}
};

// Клас President
class President : public Employer {
private:
    char* name;
    char* department;
public:
    President(const char* name, const char* department) {
        this->name = new char[strlen(name) + 1];
        strcpy(this->name, name);
        this->department = new char[strlen(department) + 1];
        strcpy(this->department, department);
    }

    void Print() const override {
        cout << "President:\n";
        cout << "Name: " << name << "\nDepartment: " << department << endl;
    }

    ~President() {
        delete[] name;
        delete[] department;
    }
};


class Manager : public Employer {
private:
    char* name;
    int teamSize;
public:
    Manager(const char* name, int teamSize) {
        this->name = new char[strlen(name) + 1];
        strcpy(this->name, name);
        this->teamSize = teamSize;
    }

    void Print() const override {
        cout << "Manager:\n";
        cout << "Name: " << name << "\nTeam Size: " << teamSize << endl;
    }

    ~Manager() {
        delete[] name;
    }
};


class Worker : public Employer {
private:
    char* name;
    char* jobTitle;
public:
    Worker(const char* name, const char* jobTitle) {
        this->name = new char[strlen(name) + 1];
        strcpy(this->name, name);
        this->jobTitle = new char[strlen(jobTitle) + 1];
        strcpy(this->jobTitle, jobTitle);
    }

    void Print() const override {
        cout << "Worker:\n";
        cout << "Name: " << name << "\nJob Title: " << jobTitle << endl;
    }

    ~Worker() {
        delete[] name;
        delete[] jobTitle;
    }
};

int main() {
    
    Employer* employees[3];

    
    employees[0] = new President("John Doe", "Corporate");
    employees[1] = new Manager("Jane Smith", 12);
    employees[2] = new Worker("Jack Brown", "Technician");

    
    for (int i = 0; i < 3; i++) {
        employees[i]->Print();
        cout << endl;
    }

   
    for (int i = 0; i < 3; i++) {
        delete employees[i];
    }

    return 0;
}
