#include <iostream>
#include <semester.h>

#include <MyClass.h>
#include <AssignmentGroup.h>

using namespace std;
/*
sources:
geeks4geeks: how to write map
*/
GPA::GPA()
{
    vector<double> GPAs;
}
GPA::GPA(const GPA &) {
};
GPA::~GPA()
{
}

int calculateGPA()
{
    int MyClass.grade = 0;
    int MyClass.credits = 0;

    map<string, double> gradepoints = {
        {"A", 4.00}, {"A-", 3.67}, {"B+", 3.33}, {"B", 3.00}, {"B-", 2.67}, {"C+", 2.33}, {"C", 2.00}, {"C-", 1.67}, {"D+", 1.33}, {"D", 1.00}, {"D-", 0.67}, {"F", 0.00}};

    for (int i = 0; i < classes; i++)
    {
        // calculate the grade points ( leaving blank for now)
        gradepoints += classes[i].grade * classes[i].credits;
    }

    return 0;
}

int main(argc, argv[])
{


    // cout << "Welcome to the GPA calculator!" << endl;
    // cout << "Please enter the number of classes you are taking this semester: ";
    // cin >> classes;
    // cout << "Please enter the number of credits you are taking this semester: ";
    // cin >> credits;
    // cout << "Please enter the grade you received for each class: ";
    // cin >> grade;
    // cout << "Please enter the number of credits each class is worth: ";
    // cin >> credit;
    // cout << "Please enter the number of assignments you have for each class: ";
    // cin >> assignments;
    // cout << "Please enter the weight of each assignment: ";
    // cin >> weight;
    // cout << "Please enter the grade you received for each assignment: ";
    // cin >> assignmentgrade;
    // cout << "Please enter the number of credits each assignment is worth: ";
    // cin >> assignmentcredit;
    // cout << "Please enter the type of each assignment: ";
    // cin >> assignmenttype;
    // cout << "Please enter the number of assignment groups you have for each class: ";
    // cin


cout << "total GPA: " << calculateGPA() << endl;
cout << "total classes taken: " << classes << endl;
cout << total credits taken: << credits << endl;
    GPA gpa;
    return 0;
}
