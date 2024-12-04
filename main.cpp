/*
Capstone Project: Grade Calculator
Names: Eli Fisk, Judah Benjamin.

File: main.cpp
Description:
This program provides a command-line interface for managing and calculating
GPA using the `College` class. Users can add, modify, and delete classes
and semesters, calculate GPA, and save or load data from a file. The program
runs in a loop, responding to user commands until they choose to exit.
*/

#include <fstream>
#include <iostream>
#include <map>
#include <sstream>

#include "college.h"
using namespace std;

int main() {
  cout << "\nWelcome to GPA Calculator!!\n" << endl;
  cout << "To get started, enter '-cds' to see the possible commands." << endl;
  cout << "If you have a file with previous GPA information, enter '-if' to "
          "get the GPA data from the file."
       << endl;
  College *MyGPA = new College();
  string input = "";
  while (true) {
    cin >> input;
    if (input == "-ac") {
      MyGPA->addClass();
    } else if (input == "-if") {
      MyGPA->readFile();
    } else if (input == "-as") {
      MyGPA->addSemester();
    } else if (input == "-dc") {
      MyGPA->deleteClass();
    } else if (input == "-ds") {
      MyGPA->deleteSem();
    } else if (input == "-gpa") {
      // Print GPA
      MyGPA->printGPA();
    } else if (input == "-ps") {
      MyGPA->printSem();

    } else if (input == "-cc") {
      MyGPA->changeClass();

    } else if (input == "-q") {
      break;
    } else if (input == "-stf") {
      MyGPA->createFile();
    } else if (input == "-cds") {
      // Print commands
      cout << "Add class:       -ac" << endl;
      cout << "Add semester:    -as" << endl;
      cout << "Delete semester: -ds" << endl;
      cout << "Delete class:    -dc" << endl;
      cout << "Print GPA:       -gpa" << endl;
      cout << "Change class:    -cc" << endl;
      cout << "Print semesters: -ps" << endl;
      cout << "Save to file:    -stf" << endl;
      cout << "Print commands:  -cds" << endl;
      cout << "Quit:            -q" << endl;
    } else {
      cout << "That is an invalid command!" << endl;
    }
  }
}
