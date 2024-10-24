#include <iostream>
#include <map>
#include <sstream>

#include "semester.h"
using namespace std;

int main() {
  cout << "Welcome to GPA Calculator!!" << endl;
  cout << "To get started, enter '-cds' to see the possible commands." << endl;

  string input = "";
  while (true) {
    cin >> input;
    if (input == "-ac") {
      // Add class
    } else if (input == "-as") {
      // Add semester
    } else if (input == "-aa") {
      // Add assignment
    } else if (input == "-gpa") {
      // Print GPA
    } else if (input == "-pc") {
      cout << "Print classes" << endl;
      // Print classes
    } else if (input == "-ps") {
      cout << "Print semester" << endl;
      // Print semester
    } else if (input == "-q") {
      break;
    } else if (input == "-cds") {
      // Print commands
      cout << "Add class:       -ac" << endl;
      cout << "Add semester:    -as" << endl;
      cout << "Add assignment:  -aa" << endl;
      cout << "Print GPA:       -gpa" << endl;
      cout << "Print classes:   -pc" << endl;
      cout << "Print semesters: -ps" << endl;
      cout << "" << endl;
      cout << "Print commands:  -cds" << endl;
      cout << "Quit:            -q" << endl;
    } else {
      cout << "That is an invalid command!" << endl;
    }
  }
}