#include <stdio.h>

#include <fstream>
#include <iostream>
#include <map>
#include <sstream>

#include "college.h"

College::College() {}

College::College(const College &SemesterToCopy) {}

College::~College() {}

void College::print() {}
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

int College::calculateSemGrade(Semester sem) {
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

  for (size_t i = 0; i < sem.classes.size(); i++) {
    // calculate the grade points
    SemGPA += sem.classes[i].grade * sem.classes[i].credits;
  }

  return 0;
}

double College::getSemGPA() { double semGPA; }
int College::getTotalCredits() { return totalCredits; }
bool College::createFile() {
  while (1) {
    string fileName = "";
    cout << "What file would you like to save your GPA information to?" << endl;
    cout << "Please enter the name a text file (Ex. gpa.txt)";
    cin >> fileName;

    ofstream outFile(fileName);
    if(outFile.fail()) {
      outFile.clear();
      continue;
    }
    outFile << "This is your GPA calculator file." << endl << endl;
    outFile << "Total GPA: " << endl;
    outFile << "Total Credits: " << totalCredits << endl << endl;

    outFile << "------------------------------------------------" << endl;
    for (size_t i = 0; i < semesters.size(); i++) {
      outFile << semesters[i].semName << endl;
      outFile << "Credits: " << semesters[i].semCredits << endl << endl;
      outFile << "        <------------------------->" << endl;
      for (size_t j = 0; j < semesters[i].classes.size(); j++) {
        outFile << semesters[i].classes[j].name << endl;
        outFile << semesters[i].classes[j].credits << endl;
        outFile << semesters[i].classes[j].grade << endl;
        outFile << "        <------------------------->" << endl;
      }
      outFile << "------------------------------------------------" << endl;
    }
    outFile.close();
    break;
  }

  return true;
}