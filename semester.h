#ifndef _SEMESTER_H_
#define _SEMESTER_H_

#include <iostream>
#include <map>
#include <vector>

using namespace std;

struct AssignmentGroup {
  string name;
  double weight;
  double grade;
  map<string, double> assignments;
};
struct MyClass {
  string name;
  int grade;
  int credits;
  vector<AssignmentGroup> groups;
};


class Semester {
 public:
  Semester();
  Semester(const Semester&);
  ~Semester();
  void print();
  int calculateGrade();
 private:
  double semGrade;
  int totalCredits;
  vector<MyClass> classes;
};

#endif


