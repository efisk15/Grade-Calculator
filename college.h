#ifndef _COLLEGE_H_
#define _COLLEGE_H_
#include <iostream>
#include <map>
#include <vector>
using namespace std;
struct MyClass {
  string name;
  double grade;
  int credits;
  bool major;
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
  int calculateSemGrade(Semester);
  double getSemGPA();
  int getTotalCredits();
  bool createFile();
  void addSemester();
  void addClass();
  void printSem();
  void changeClass();
  void deleteClass();
  void deleteSem();
  void readFile();
 private:
  double totalGPA;
  int totalCredits;
  vector<Semester> semesters;
};
#endif