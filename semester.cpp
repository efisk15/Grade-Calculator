#include "semester.h"

#include <stdio.h>

Semester::Semester() {}

Semester::Semester(const Semester &SemesterToCopy) {}

Semester::~Semester() {}

void Semester::print() {
}
// order of calulations
// gpa - smester - classes value - credits - glass gpa - grading wieghts -
// assignment grades
int AssignmentGroup() {
  string name;
  double weight;
  double grade;
  // possibly read in assignments from file
  map<string, double> assignments = {};
}
// int MyClass.grade = 0;
// int MyClass.credits = 0

int Semester::calculateGrade() {
  // int MyClass.grade = 0;
  // int MyClass.credits = 0;

  map<string, double> gradepoints;
  gradepoints["A"] = 4.00;
  gradepoints["A-"] = 3.67;
  gradepoints["B+"] = 3.33;
  gradepoints["B"] = 3.00;
  gradepoints["B-"] = 2.67;
  gradepoints["C+"] = 2.33;
  gradepoints["C"] = 2.00;
  gradepoints["C-"] = 1.67;
  gradepoints["D+"] = 1.33;
  gradepoints["D"] = 1.00;
  gradepoints["D-"] = 0.67;
  gradepoints["F"] = 0.00;

  double SemGPA = 0.0;

  // take the amount of grade points and multiply it by the amount of credits
  // the class is worth

  for (size_t i = 0; i < classes.size(); i++) {
    // calculate the grade points
    SemGPA += classes[i].grade * classes[i].credits;
  }

  return 0;
}

double Semester::getSemGPA() { double semGPA;}
int Semester::getTotalCredits() { return totalCredits;}