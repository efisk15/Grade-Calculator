#include <fstream>
#include <iostream>
#include <map>
#include <sstream>
#include "college.h"
using namespace std;

int main() {
  cout << "Welcome to GPA Calculator!!" << endl;
  cout << "To get started, enter '-cds' to see the possible commands." << endl;
  cout << "If you have a file with previous GPA information, enter '-if' to "
          "get the GPA data from the file."
       << endl;
  College *MyGPA = new College();
  string input = "";
  while (true) {
    cin >> input;
    if (input == "-ac") {
      // Add class
    } else if (input == "-if") {
      // Get past input
      cout << "What file would you like to copy information from?" << endl;
      string inputFile;
      if (cin >> inputFile) {
      };
    } else if (input == "-as") {
      MyGPA->addSemester();
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
    } else if (input == "-stf") {
      MyGPA->createFile();
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
