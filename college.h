#ifndef _COLLEGE_H_
#define _COLLEGE_H_
#include <iostream>
#include <map>
#include <vector>
using namespace std;
struct MyClass {
  string name;
  string grade;
  int credits;
};
struct Semester {
  string semName;
  double semGPA;
  int semCredits;
  vector<MyClass> classes;
};

class College {
 public:
  College();
  College(const College&);
  ~College();
  void print();
  double calculateSemGrade(Semester);
  void calculateTotalGPA();
  int getTotalCredits();
  bool createFile();
  void addSemester();
  void addClass();
  void printSem();
  void changeClass();
  void deleteClass();
  void deleteSem();
  void readFile();
  void printGPA();
 private:
  double totalGPA;
  int totalCredits;
  vector<Semester> semesters;
};
#endif