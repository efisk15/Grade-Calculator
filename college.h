/*
Capstone Project: Grade Calculator
Names: Eli Fisk, Judah Benjamin.

File: college.h
Description: 
This header file defines the `College` class and related data structures used 
to manage and calculate academic data such as semesters, classes, grades, 
and GPA for a college student. It includes functionality to add, modify, 
and delete academic records, as well as to calculate GPAs and manage data 
through file I/O.
*/

#ifndef _COLLEGE_H_
#define _COLLEGE_H_
#include <iostream>
#include <map>
#include <vector>
using namespace std;

// Struct for classes within semesters.
struct MyClass {
  string name;
  string grade;
  int credits;
};

// Struct for semesters.
struct Semester {
  string semName;
  double semGPA;
  int semCredits;
  vector<MyClass> classes;
};

class College {
 public:
  College();

  // We do not need a copy or deconstructor because pointers are not being used.
  College(const College&);
  ~College();

  bool validGrade(string);              // Check if a given grade is valid.
  double calculateSemGrade(Semester);   // Return a semester's grade based on its classes's grades.
  void calculateTotalGPA();             // Solve for the total GPA based on each semester's gpa and credit hours.
  void createFile();                    // Print data to a given file.
  void addSemester();                   // Add a semester to the vector of semesters.
  void addClass();                      // Add a class to a selected semester.
  void printSem();                      // Print a selected semester.
  void changeClass();                   // Change the grade of a class.
  void deleteClass();                   // Delete a class in a given semester.
  void deleteSem();                     // Delete a semester and all the classes in the semester.
  void readFile();                      // Read gpa data from a file.
  void printGPA();                      // Print your total gpa.
 private:
  double totalGPA;
  int totalCredits;
  vector<Semester> semesters;
};
#endif