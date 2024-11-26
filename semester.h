#ifndef _SEMESTER_H_
#define _SEMESTER_H_

#include <iostream>
#include <map>
#include <vector>

using namespace std;

struct MyClass {
  string name;
  int grade;
  int credits;
};


class Semester {
 public:
  Semester();
  Semester(const Semester&);
  ~Semester();
  void print();
  int calculateGrade();
  double getSemGPA();
  int getTotalCredits();
 private:
  double semGPA;
  int totalCredits;
  vector<MyClass> classes;
};

#endif


