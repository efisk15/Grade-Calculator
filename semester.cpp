#include "semester.h"
#include <stdio.h>

Semester::Semester() {}

Semester::Semester(const Semester &SemesterToCopy) {}

Semester::~Semester() {}

void Semester::print()
{
  printf("Credit hours:%-5d GPA:%-5f\n", totalCredits, semGrade);
  for (size_t i = 0; i < classes.size(); i++)
  {
    printf("%s:\nTotal Grade: %f\nAssignments:\n", classes[i].name.c_str(),
           classes[i].grade);
    for (size_t j = 0; j < classes[i].groups.size(); j++)
    {
      printf("%-10s: %-10f Grade: %-10f", classes[i].groups[j].name.c_str(),
             classes[i].groups[j].weight, classes[i].groups[j].grade);
      if (j % 3)
      {
        cout << endl;
      }
    }
    cout << endl;
  }
}
// order of calulations
// gpa - smester - classes value - credits - glass gpa - grading wieghts - assignment grades
int AssignmentGroup()
{
  string name;
  double weight;
  double grade;
  // possibly read in assignments from file
  map<string, double> assignments = {};
}
// int MyClass.grade = 0;
// int MyClass.credits = 0

int Semester::calculateGrade()
{
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

  // take the amount of grade points and multiply it by the amount of credits the class is worth

  for (size_t i = 0; i < classes.size(); i++)
  {
    // calculate the grade points
    SemGPA += classes[i].grade * classes[i].credits;
  }

  return 0;
}