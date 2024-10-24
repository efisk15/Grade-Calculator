#include <iostream>
#include "semester.h"
#include <stdio.h>

using namespace std;
/*
sources:
geeks4geeks: how to write map
*/

Semester::Semester() {}

Semester::Semester(const Semester& SemesterToCopy) {}

Semester::~Semester() {}

void Semester::print() {
  printf("Credit hours:%-5d GPA:%-5f\n", totalCredits, semGrade);
  for (size_t i = 0; i < classes.size(); i++) {
    printf("%s:\nTotal Grade: %f\nAssignments:\n", classes[i].name.c_str(),
           classes[i].grade);
    for (size_t j = 0; j < classes[i].groups.size(); j++) {
      printf("%-10s: %-10f Grade: %-10f", classes[i].groups[j].name.c_str(),
             classes[i].groups[j].weight, classes[i].groups[j].grade);
      if (j % 3) {
        cout << endl;
      }
    }
    cout << endl;
  }
}

int Semester::calculateGrade()
{
    // int MyClass.grade = 0;
    // int MyClass.credits = 0;

    map<string, double> gradepoints = {
        {"A", 4.00}, {"A-", 3.67}, {"B+", 3.33}, {"B", 3.00}, {"B-", 2.67}, {"C+", 2.33}, {"C", 2.00}, {"C-", 1.67}, {"D+", 1.33}, {"D", 1.00}, {"D-", 0.67}, {"F", 0.00}};

    for (int i = 0; i < classes; i++)
    {
        // calculate the grade points ( leaving blank for now)
        gradepoints += classes[i].grade * classes[i].credits;
    }

    return 0;
}

int main()
{
    return 0;
}
