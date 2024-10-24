#include "semester.h"

Semester::Semester() {}

Semester::Semester(const Semester& SemesterToCopy) {}

Semester::~Semester() {}

void Semester::print() {
  printf("Credit hours:%-5d GPA:%-5f\n", totalCredits, semGrade);
  for (size_t i = 0; i < classes.size(); i++) {
    printf("%s:\nTotal Grade: %f\nAssignments:\n", classes[i].name.c_str(),
           classes[i].grade);
    for (size_t j = 0; j < classes[i].groups.size(); j++) {
      printf("%-10s: %-10f Grade: %-10f", classes[i].groups[j].name.c_str(),
             classes[i].groups[j].weight, classes[i].groups[j].grade);
      if (j % 3) {
        cout << endl;
      }
    }
    cout << endl;
  }
}