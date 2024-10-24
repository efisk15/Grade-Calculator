#ifndef _SEMESTER_H_
#define _SEMESTER_H_

#include <iostream>
#include <map>
#include <vector>

using namespace std;

// Node struct.
struct MyClass {
  string name;
  int grade;
  int credit;
  vector<AssignmentGroup> groups;
};

struct AssignmentGroup {
  string name;
  double weight;
  double grade;
  map<string, double> assignments;
};

class Semester {
 public:
  Semester();
  Semester(const Semester&);
  ~Semester();
  void print();

 private:
  double semGrade;
  int totalCredits;
  vector<MyClass> classes;
};

#endif