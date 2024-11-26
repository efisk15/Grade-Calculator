#include <fstream>
#include <iostream>
#include <map>
#include <sstream>

#include "semester.h"
using namespace std;

bool createFile(string fileName, int totalGPA, vector<Semester*> semesters) {
  int totalCredits = 0;
  for (size_t i = 0; i < semesters.size(); i++) {
    totalCredits += semesters[i]->getTotalCredits();
  }
  ofstream outFile(fileName);
  outFile << "This is your GPA calculator file." << endl << endl;
  outFile << "Total GPA: " << endl;
  outFile << "Total Credits: " << totalCredits << endl << endl;

  for (size_t i = 0; i < semesters.size(); i++) {
    totalCredits += semesters[i]->getTotalCredits();
  }
}

int main() {
  cout << "Welcome to GPA Calculator!!" << endl;
  cout << "To get started, enter '-cds' to see the possible commands." << endl;
  cout << "If you have a file with previous GPA information, enter '-if' to "
          "get the GPA data from the file."
       << endl;

  vector<Semester*> semesters;

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
      // Add semester
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
      string fileName;
      cout << "What file would you like to save your GPA information to?"
           << endl;
      cout << "Please enter the name a text file (Ex. gpa.txt)";
      cin >> fileName;

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