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
  int credits;
  vector<AssignmentGroup> groups;
};

struct AssignmentGroup {
  string type;
  double weight;
  map<string, double> assignments;
};

class GPA {
 public:
  GPA();
  GPA(const GPA&);
  ~GPA();

 private:
  int semGrade;
  vector<MyClass> classes;
  double overallGPA;
  vector<double> GPAs;
  int semester;
};

#endif


