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
  map<string, double> assignments;
};

class Semester {
 public:
  Semester();
  Semester(const Semester&);
  ~Semester();

 private:
  int semGrade;
  double overallGPA;
  string semester;
  int totalCredits;
  vector<MyClass> classes;
  vector<double> GPAs;
};

#endif