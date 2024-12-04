/*
Capstone Project: Grade Calculator
Names: Eli Fisk, Judah Benjamin.

File: college.cpp
Description: Implementation of the College class for managing
semester and class data, including GPA calculation, file handling,
and user interaction. This file includes methods to add, modify,
delete, and print semesters and classes, as well as read/write data
to files and calculate GPA metrics.

Citations:
I used geekforgeeks to find the all_of function.
https://www.geeksforgeeks.org/stdall_of-in-cpp/

I used geekforgeeks to learn how to us ofstream.
https://www.geeksforgeeks.org/file-handling-c-classes/
*/

#include "college.h"

#include <stdio.h>

#include <algorithm>
#include <cstdlib>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <map>
#include <sstream>
#include <string>
College::College() {
  totalCredits = 0;
  totalGPA = 0;
  semesters.resize(0);
}
College::College(const College& SemesterToCopy)
    : totalGPA(SemesterToCopy.totalGPA),
      totalCredits(SemesterToCopy.totalCredits),
      semesters(SemesterToCopy.semesters) {}

College::~College() {}

bool College::validGrade(string grade) {
  if (grade == "A" || grade == "A-" || grade == "B+" || grade == "B-" ||
      grade == "B" || grade == "C+" || grade == "C" || grade == "C-" ||
      grade == "D+" || grade == "D" || grade == "D-" || grade == "F") {
    return true;
  } else {
    return false;
  }
}

void College::calculateSemGrade(Semester& sem) {
  map<string, double> gradepoints;
  gradepoints["A"] = 4.00;
  gradepoints["A-"] = 3.67;
  gradepoints["B+"] = 3.33;
  gradepoints["B"] = 3.00;
  gradepoints["B-"] = 2.67;
  gradepoints["C+"] = 2.33;
  gradepoints["C"] = 2.00;
  gradepoints["C-"] = 1.67;
  gradepoints["D+"] = 1.33;
  gradepoints["D"] = 1.00;
  gradepoints["D-"] = 0.67;
  gradepoints["F"] = 0.00;
  double SemGPA = 0.0;
  // take the amount of grade points and multiply it by the amount of credits
  // the class is worth
  for (size_t i = 0; i < sem.classes.size(); i++) {
    // calculate the grade points
    const string& grade = sem.classes[i].grade;
    const double credits = sem.classes[i].credits;
    SemGPA += gradepoints[grade] * credits;
  }
  if (sem.semCredits == 0) {
    sem.semGPA = 0;
    return;
  }
  sem.semGPA = SemGPA / sem.semCredits;
}
void College::calculateTotalGPA() {
  double semGPA = 0.0;

  // Get the weighted grade for each semester to then divide it by the total
  // credit hours.
  for (size_t i = 0; i < semesters.size(); i++) {
    semGPA += semesters[i].semCredits * semesters[i].semGPA;
  }
  if (totalCredits == 0) {
    totalGPA = semGPA / 1;
  } else {
    totalGPA = semGPA / totalCredits;
  }
}

void College::addSemester() {
  cin.clear();
  cin.ignore();
  string response;
  // Prompt the user for the name of a semester. If there are already semesters,
  // list them so that the user does not accidentally duplicate semesters.
  cout << endl
       << "What is the name of the semester that you would like to add?"
       << endl;
  cout << "(Recommended Ex. Spring 2024)" << endl;
  if (semesters.size() > 0) {
    cout << "Current Semesters added: " << endl;
    for (size_t i = 0; i < semesters.size(); i++) {
      cout << semesters[i].semName << endl;
    }
    cout << endl;
    cout << "If you already see your semester listed, enter -q to go back."
         << endl;
  }
  std::getline(cin, response);
  if (response == "-q") {
    return;
  }
  // Add the new semester.
  Semester newSem;
  newSem.semName = response;
  newSem.semCredits = 0;
  newSem.semGPA = 0;
  semesters.push_back(newSem);
  cout << endl << "Successfully created semester." << endl;
}
void College::createFile() {
  calculateTotalGPA();
  while (1) {
    // Prompt the user for a file name. If the file name is not good, re-prompt
    // for a new name until they enter a valid one or they hit -q.
    string fileName = "";
    cout << "What file would you like to save your GPA information to?" << endl;
    cout << "Please enter the name a text file (Ex. gpa.txt)\n";
    cin >> fileName;
    if (fileName == "-q") {
      return;
    }
    ofstream outFile(fileName.c_str());
    if (outFile.fail()) {
      outFile.clear();
      continue;
    }

    // Print to the file with a specific format.
    outFile << "This is your GPA calculator file." << endl << endl;
    outFile << "Total GPA: " << fixed << setprecision(2) << totalGPA << endl;
    outFile << "Total Credits: " << totalCredits << endl << endl;
    outFile << "------------------------------------------------" << endl;
    for (size_t i = 0; i < semesters.size(); i++) {
      outFile << semesters[i].semName << endl;
      outFile << "Credits: " << semesters[i].semCredits << endl;
      outFile << "Semester GPA: " << semesters[i].semGPA << endl << endl;
      outFile << "        <------------------------->" << endl;
      for (size_t j = 0; j < semesters[i].classes.size(); j++) {
        outFile << "          Class:     " << semesters[i].classes[j].name
                << endl;
        outFile << "          Credits:   " << semesters[i].classes[j].credits
                << endl;
        outFile << "          Grade:     " << fixed << setprecision(2)
                << semesters[i].classes[j].grade << endl;
        outFile << "        <------------------------->" << endl;
      }
      outFile << "------------------------------------------------" << endl;
    }
    outFile.close();
    break;
  }
  return;
}
void College::readFile() {
  while (1) {
    // Prompt the user for a file name to read from, if it is not a valid file,
    // re-prompt until it is valid.
    string fileName = "";
    cout << "What file would you like to pull your GPA information from?"
         << endl;
    cout << "Please enter the name a text file (Ex. gpa.txt)\n";
    cin >> fileName;
    if (fileName == "-q") {
      return;
    }
    ifstream inFile(fileName.c_str());
    if (inFile.fail()) {
      inFile.clear();
      cout << "That file does not exist. Please try again or enter -q to go "
              "back."
           << endl;
      continue;
    }
    string inputLine;
    getline(inFile, inputLine);
    if (inputLine != "This is your GPA calculator file.") {
      inFile.close();
      cout << "That is an invalid file. Please try again with a file specific "
              "for the use of this program or enter -q to return."
           << endl;
      continue;
    }
    // File is now valid so go line by line getting data for semesters and
    // classes.
    getline(inFile, inputLine);
    getline(inFile, inputLine);
    size_t startPos = inputLine.find(": ") + 2;
    totalGPA = stod(inputLine.substr(startPos));
    getline(inFile, inputLine);
    startPos = inputLine.find(": ") + 2;
    totalCredits = stoi(inputLine.substr(startPos));
    getline(inFile, inputLine);
    getline(inFile, inputLine);
    while (true) {
      getline(inFile, inputLine);
      if (inputLine == "") {
        break;
      }
      Semester newSemester;
      newSemester.semName = inputLine;
      getline(inFile, inputLine);
      startPos = inputLine.find(": ") + 2;
      newSemester.semCredits = stoi(inputLine.substr(startPos));
      getline(inFile, inputLine);
      startPos = inputLine.find(": ") + 2;
      newSemester.semGPA = stod(inputLine.substr(startPos));
      getline(inFile, inputLine);
      while (true) {
        MyClass newClass;
        getline(inFile, inputLine);
        getline(inFile, inputLine);
        if (inputLine == "------------------------------------------------") {
          break;
        }
        startPos = inputLine.find(": ") + 2;
        string name = inputLine.substr(startPos + 4);
        newClass.name = name;

        getline(inFile, inputLine);
        startPos = inputLine.find(": ") + 2;
        newClass.credits = stoi(inputLine.substr(startPos));
        getline(inFile, inputLine);
        startPos = inputLine.find(": ") + 2;
        newClass.grade = inputLine.substr(startPos + 4);
        newSemester.classes.push_back(newClass);
      }
      semesters.push_back(newSemester);
    }
    inFile.close();
    break;
  }
  cout << "\nFile has been successfully read in." << endl;
}
void College::addClass() {
  cin.clear();
  cin.ignore();
  string response;
  size_t resp;

  // Prompt the user to enter the number corresponding to the semester they
  // would like to add their class to. If there are no semesters, alert them
  // that they will need to create a semester before adding a class.
  if (semesters.size() > 0) {
    while (true) {
      cout << endl
           << "What semester would you like to add your class to?(Enter the "
              "number of the semester)"
           << endl;
      for (size_t i = 0; i < semesters.size(); i++) {
        cout << i + 1 << ": " << semesters[i].semName << endl;
      }
      cout << endl;
      if (cin >> resp) {
        if (resp <= semesters.size() && resp > 0) {
          break;
        }
      } else {
        cin.clear();
        cin.ignore();
      }
    }
    cin.clear();
    cin.ignore();
    resp--;
    cout << endl
         << "What is the name of the class that you would like to add?" << endl;
    cout << "(Recommended Ex. COSC 202)" << endl;
    if (semesters[resp].classes.size() > 0) {
      cout << "Current classes added: " << endl;
      for (size_t i = 0; i < semesters[resp].classes.size(); i++) {
        cout << semesters[resp].classes[i].name << endl;
      }
      cout << endl;
      cout << "If you already see your class listed, enter -q to go back."
           << endl;
    }
    std::getline(cin, response);
    if (response == "-q") {
      return;
    }

    // Get the other necessary information for the class.
    int creditHours = 0;
    string grade = "";
    while (true) {
      cout << "How many credit hours is the class worth?" << endl;
      if (cin >> creditHours && creditHours < 6 && creditHours > 0) {
        break;
      }
      cout << "Not a valid number of credit hours.(1-5)" << endl;
      cin.clear();
      cin.ignore();
    }
    while (true) {
      cout << endl
           << "What is your current grade in the class?(Ex. A-)" << endl;
      if (cin >> grade && validGrade(grade)) {
        break;
      }
      cout << "Not a valid Grade.(A-F)" << endl;

      cin.clear();   // Clear any error flags
      cin.ignore();  // Ignore leftover input
    }
    MyClass newClass;
    newClass.name = response;
    newClass.grade = grade;
    newClass.credits = creditHours;

    semesters[resp].classes.push_back(newClass);
    semesters[resp].semCredits += creditHours;
    calculateSemGrade(semesters[resp]);
    totalCredits += creditHours;
    cout << "\nClass successfully added." << endl;
  } else {
    cout << "There are not any semesters created yet. Use the -as command to "
            "add a semester before adding a class."
         << endl;
  }
}

// Print a selected semester to the terminal with formatting.
void College::printSem() {
  size_t resp;
  while (true) {
    cout << endl << "What semester would you like to print?" << endl;
    for (size_t i = 0; i < semesters.size(); i++) {
      cout << i + 1 << ": " << semesters[i].semName << endl;
    }
    cout << endl;
    if (cin >> resp) {
      if (resp <= semesters.size() && resp > 0) {
        break;
      }
    } else {
      cin.clear();
      cin.ignore();
    }
  }
  resp--;
  cout << endl << "---------------------------------->" << endl;

  cout << semesters[resp].semName << endl;
  cout << "Credits: " << semesters[resp].semCredits << endl;
  cout << "Total GPA: " << fixed << setprecision(2) << semesters[resp].semGPA
       << endl;

  cout << endl << "        <------------------------->" << endl;
  for (size_t j = 0; j < semesters[resp].classes.size(); j++) {
    cout << "        Name:    " << semesters[resp].classes[j].name << endl;
    cout << "        Credits: " << semesters[resp].classes[j].credits << endl;
    cout << "        Grade:   " << fixed << setprecision(2)
         << semesters[resp].classes[j].grade << endl;
    cout << "        <------------------------->" << endl;
  }

  cout << endl << "---------------------------------->" << endl;
  return;
}
void College::changeClass() {
  cin.clear();
  cin.ignore();
  size_t resp;

  // Select the semester that has the class. Then select the class you would
  // like to change.
  while (true) {
    cout << "\nWhat semester is the class you would like to change in? (Enter "
            "the number of the semester)\n";
    for (size_t i = 0; i < semesters.size(); i++) {
      cout << i + 1 << ": " << semesters[i].semName << endl;
    }
    cout << endl;

    if (cin >> resp && resp > 0 && resp <= semesters.size()) {
      resp--;
      break;
    } else {
      cout << "Invalid input. Please enter a number between 1 and "
           << semesters.size() << ".\n";
      cin.clear();
      cin.ignore();
    }
  }

  // Select class within the chosen semester
  while (true) {
    if (semesters[resp].classes.empty()) {
      cout << "There are no classes in this semester.\n";
      return;
    }

    cout << "Here are the classes within the semester you selected:\n";
    for (size_t i = 0; i < semesters[resp].classes.size(); i++) {
      cout << i + 1 << ": " << semesters[resp].classes[i].name << endl;
    }
    cout << "\nEnter the number of the class you would like to change.\n";
    cout << "If you do not see the class you wish to change, enter -q to go "
            "back.\n";

    string response;
    cin >> response;

    if (response == "-q") {
      return;
    }

    if (all_of(response.begin(), response.end(), ::isdigit)) {
      size_t num = stoi(response) - 1;  // Adjust for zero-based indexing

      if (num >= 0 && num < semesters[resp].classes.size()) {
        cout << "Current information about "
             << semesters[resp].classes[num].name << ":\n";
        cout << "Total Credits: " << semesters[resp].classes[num].credits
             << endl;
        cout << "Total Grade:   " << semesters[resp].classes[num].grade << endl;

        cout << "\nWhat would you like the new grade to be? ";
        string grade;
        if (cin >> grade && validGrade(grade)) {
          semesters[resp].classes[num].grade = grade;
          calculateSemGrade(semesters[resp]);
          cout << "Grade updated successfully.\n";
          return;
        } else {
          cout << "Invalid grade input. Try again.\n";
          cin.clear();
          cin.ignore();
        }
      } else {
        cout << "Invalid class number. Please enter a valid number.\n";
      }
    } else {
      cout
          << "Invalid input. Please enter a valid number or '-q' to go back.\n";
    }
  }
}
void College::deleteClass() {
  cin.clear();
  cin.ignore();
  size_t resp;

  // Select a semester that has a class that the user wants to delete.
  while (true) {
    cout << "\nWhat semester is the class you would like to delete in? (Enter "
            "the number of the semester)\n";
    for (size_t i = 0; i < semesters.size(); i++) {
      cout << i + 1 << ": " << semesters[i].semName << endl;
    }
    cout << endl;

    if (cin >> resp && resp > 0 && resp <= semesters.size()) {
      resp--;
      break;
    } else {
      cout << "Invalid input. Please enter a number between 1 and "
           << semesters.size() << ".\n";
      cin.clear();   // Clear any error flags
      cin.ignore();  // Ignore leftover input
    }
  }

  // Select class within the chosen semester
  while (true) {
    if (semesters[resp].classes.empty()) {
      cout << "There are no classes in this semester.\n";
      return;
    }

    cout << "Here are the classes within the semester you selected:\n";
    for (size_t i = 0; i < semesters[resp].classes.size(); i++) {
      cout << i + 1 << ": " << semesters[resp].classes[i].name << endl;
    }
    cout << "\nEnter the number of the class you would like to delete.\n";
    cout << "If you do not see the class you wish to delete, enter -q to go "
            "back.\n";

    string response;
    cin >> response;

    if (response == "-q") {
      return;
    }

    if (all_of(response.begin(), response.end(), ::isdigit)) {
      size_t num = stoi(response) - 1;

      // Add all classes other than the one being deleted to a new vector then
      // set semesters = to the temp vector.
      if (num >= 0 && num < semesters[resp].classes.size()) {
        vector<MyClass> tempClasses;
        for (size_t j = 0; j < semesters[resp].classes.size(); j++) {
          if (j == num) {
            totalCredits -= semesters[resp].classes[num].credits;
            semesters[resp].semCredits -= semesters[resp].classes[num].credits;
            if (semesters[resp].semCredits == 0) {
              semesters[resp].semGPA = 0;
            }
            continue;
          }
          tempClasses.push_back(semesters[resp].classes[j]);
        }
        cout << "\nThe class " << semesters[resp].classes[num].name
             << " has successfully been deleted.\n";
        semesters[resp].classes = tempClasses;
        calculateSemGrade(semesters[resp]);
        calculateTotalGPA();
        return;

      } else {
        cout << "Invalid class number. Please enter a valid number.\n";
      }
    } else {
      cout
          << "Invalid input. Please enter a valid number or '-q' to go back.\n";
    }
  }
  calculateTotalGPA();
  cout << "\nClass successfully deleted." << endl;
}

void College::deleteSem() {
  cin.clear();
  cin.ignore();

  // Prompt the user for the semester they want to delete.
  if (semesters.size() > 0) {
    cout << "Current Semesters: " << endl;
    for (size_t i = 0; i < semesters.size(); i++) {
      cout << i + 1 << ": " << semesters[i].semName << endl;
    }
    cout << endl
         << "What is the number of the semester that you would like to delete?"
         << endl;
    cout << "If you do not see the semester listed, it does not exist, enter "
            "-q to go back."
         << endl;
  }
  string response;
  cin >> response;

  if (response == "-q") {
    return;
  }

  if (all_of(response.begin(), response.end(), ::isdigit)) {
    size_t num = stoi(response) - 1;
    // Add all semesters to a temp vector except the one the user wants to
    // delete. Set semester = tempvector.
    if (num >= 0 && num < semesters.size()) {
      vector<Semester> tempSem;
      for (size_t j = 0; j < semesters.size(); j++) {
        if (j == num) {
          totalCredits -= semesters[num].semCredits;
          continue;
        }
        tempSem.push_back(semesters[j]);
      }
      cout << "\nThe semester " << semesters[num].semName
           << " has successfully been deleted.\n";
      semesters = tempSem;
      calculateTotalGPA();
      return;

    } else {
      cout << "Invalid class number. Please enter a valid number.\n";
    }
  } else {
    cout << "Invalid input. Please enter a valid number or '-q' to go back.\n";
  }
  cout << endl << "Semester successfully deleted." << endl;
}

// Print the total gpa.
void College::printGPA() {
  calculateTotalGPA();
  cout << "Your total GPA is: " << totalGPA << endl;
}
