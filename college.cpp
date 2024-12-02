#include "college.h"

#include <stdio.h>

#include <algorithm>  // for std::all_of
#include <fstream>
#include <iostream>
#include <map>
#include <sstream>
College::College() {}
College::College(const College &SemesterToCopy) {}
College::~College() {}
void College::print() {}
// order of calulations
// gpa - smester - classes value - credits - glass gpa - grading wieghts -
// assignment grades

// int AssignmentGroup() {
//   string name;
//   double weight;
//   double grade;
//   return 0;
//   // possibly read in assignments from file
//   // map<string, double> assignments = {};
// }

int College::calculateSemGrade(Semester sem) {
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
    SemGPA += sem.classes[i].grade * sem.classes[i].credits;
  }
  if (sem.semCredits == 0) {
    return 0;
  } else {
    return SemGPA / sem.semCredits;
  }
}
double College::getSemGPA() {
  double semGPA = 0.0;
  for (size_t i = 0; i < semesters.size(); i++) {
    semGPA += calculateSemGrade(semesters[i]);
  }
  return semGPA;
}

// void College::addSemester()
// {
//   Semester sem;
//   semesters.push_back(sem);
//   totalCredits += sem.semCredits;
// }

int College::getTotalCredits() { return totalCredits; }
void College::addSemester() {
  cin.clear();   // Clear any error flags
  cin.ignore();  // Ignore leftover input
  string response;
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
  Semester newSem;
  newSem.semName = response;
  newSem.semCredits = 0;
  newSem.semGPA = 0;
  semesters.push_back(newSem);
  cout << endl << "Successfully created semester." << endl;
}
bool College::createFile() {
  while (1) {
    string fileName = "";
    cout << "What file would you like to save your GPA information to?" << endl;
    cout << "Please enter the name a text file (Ex. gpa.txt)\n";
    cin >> fileName;
    ofstream outFile(fileName.c_str());
    if (outFile.fail()) {
      outFile.clear();
      continue;
    }
    outFile << "This is your GPA calculator file." << endl << endl;
    outFile << "Total GPA: " << totalGPA << endl;
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
        outFile << "          Grade:     " << semesters[i].classes[j].grade
                << endl;
        if (semesters[i].classes[j].major) {
          outFile << "          Major Req: true" << endl;
        } else {
          outFile << "          Major Req: false" << endl;
        }
        outFile << "        <------------------------->" << endl;
      }
      outFile << "------------------------------------------------" << endl;
    }
    outFile.close();
    break;
  }
  return true;
}
void College::readFile() {
  while (1) {
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
      newSemester.semGPA = stoi(inputLine.substr(startPos));
      getline(inFile, inputLine);
      while (true) {
        MyClass newClass;
        getline(inFile, inputLine);
        getline(inFile, inputLine);
        if (inputLine == "------------------------------------------------") {
          break;
        }
        startPos = inputLine.find(": ") + 2;
        string name = inputLine.substr(startPos + 2);
        newClass.name = name;

        getline(inFile, inputLine);
        startPos = inputLine.find(": ") + 2;
        newClass.credits = stoi(inputLine.substr(startPos));
        getline(inFile, inputLine);
        startPos = inputLine.find(": ") + 2;
        newClass.grade = stod(inputLine.substr(startPos));
        newSemester.classes.push_back(newClass);
        getline(inFile, inputLine);
        startPos = inputLine.find(": ") + 2;
        if (inputLine.substr(startPos) == "true") {
          newClass.major = true;
        } else {
          newClass.major = false;
        }
        newSemester.classes.push_back(newClass);
      }
      semesters.push_back(newSemester);
    }
    break;
    cout << "\nFile has been successfully read in." << endl;
  }
}
void College::addClass() {
  cin.clear();   // Clear any error flags
  cin.ignore();  // Ignore leftover input
  string response;
  size_t resp;
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
      cin.clear();   // Clear any error flags
      cin.ignore();  // Ignore leftover input
    }
  }
  cin.clear();   // Clear any error flags
  cin.ignore();  // Ignore leftover input
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
  int creditHours = 0;
  double grade = 0;
  char major = 'n';
  while (true) {
    cout << "How many credit hours is the class worth?" << endl;
    if (cin >> creditHours && creditHours < 6 && creditHours > 0) {
    } else {
      cin.clear();   // Clear any error flags
      cin.ignore();  // Ignore leftover input
      continue;
    }

    cout << endl
         << "What is your current grade in the class?(Ex. 94.35)" << endl;
    if (cin >> grade && grade > 0) {
    } else {
      cin.clear();   // Clear any error flags
      cin.ignore();  // Ignore leftover input
      continue;
    }
    cout << endl << "Is this class required for your major?(y/n)" << endl;
    if (cin >> major && (major == 'y' || major == 'n')) {
      break;
    }

    cin.clear();   // Clear any error flags
    cin.ignore();  // Ignore leftover input
  }
  MyClass newClass;
  newClass.name = response;
  newClass.grade = grade;
  newClass.credits = creditHours;
  if (major == 'y') {
    newClass.major = true;
  }

  semesters[resp].classes.push_back(newClass);
  semesters[resp].semCredits += creditHours;
  cout << "\nClass successfully added." << endl;
}

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
      cin.clear();   // Clear any error flags
      cin.ignore();  // Ignore leftover input
    }
  }
  resp--;
  cout << endl << "---------------------------------->" << endl;

  cout << semesters[resp].semName << endl;
  cout << "Credits: " << semesters[resp].semCredits << endl;
  cout << "Total GPA: " << semesters[resp].semGPA << endl;

  cout << endl << "        <------------------------->" << endl;
  for (size_t j = 0; j < semesters[resp].classes.size(); j++) {
    cout << "        Name:    " << semesters[resp].classes[j].name << endl;
    cout << "        Credits: " << semesters[resp].classes[j].credits << endl;
    cout << "        Grade:   " << semesters[resp].classes[j].grade << endl;
    cout << "        <------------------------->" << endl;
  }

  cout << endl << "---------------------------------->" << endl;
  return;
}
void College::changeClass() {
  cin.clear();   // Clear any error flags
  cin.ignore();  // Ignore leftover input
  size_t resp;

  // Select semester
  while (true) {
    cout << "\nWhat semester is the class you would like to change in? (Enter "
            "the number of the semester)\n";
    for (size_t i = 0; i < semesters.size(); i++) {
      cout << i + 1 << ": " << semesters[i].semName << endl;
    }
    cout << endl;

    if (cin >> resp && resp > 0 && resp <= semesters.size()) {
      resp--;  // Adjust for zero-based indexing
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
        double grade;
        if (cin >> grade) {
          semesters[resp].classes[num].grade = grade;
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
  cin.clear();   // Clear any error flags
  cin.ignore();  // Ignore leftover input
  size_t resp;

  // Select semester
  while (true) {
    cout << "\nWhat semester is the class you would like to delete in? (Enter "
            "the number of the semester)\n";
    for (size_t i = 0; i < semesters.size(); i++) {
      cout << i + 1 << ": " << semesters[i].semName << endl;
    }
    cout << endl;

    if (cin >> resp && resp > 0 && resp <= semesters.size()) {
      resp--;  // Adjust for zero-based indexing
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

      if (num >= 0 && num < semesters[resp].classes.size()) {
        vector<MyClass> tempClasses;
        for (size_t j = 0; j < semesters[resp].classes.size(); j++) {
          if (j == num) {
            continue;
          }
          tempClasses.push_back(semesters[resp].classes[j]);
        }
        cout << "\nThe class " << semesters[resp].classes[num].name
             << " has successfully been deleted.\n";
        semesters[resp].classes = tempClasses;
        return;

      } else {
        cout << "Invalid class number. Please enter a valid number.\n";
      }
    } else {
      cout
          << "Invalid input. Please enter a valid number or '-q' to go back.\n";
    }
  }
  cout << "\nClass successfully deleted." << endl;
}

void College::deleteSem() {
  cin.clear();   // Clear any error flags
  cin.ignore();  // Ignore leftover input
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

    if (num >= 0 && num < semesters.size()) {
      vector<Semester> tempSem;
      for (size_t j = 0; j < semesters.size(); j++) {
        if (j == num) {
          continue;
        }
        tempSem.push_back(semesters[j]);
      }
      cout << "\nThe semester " << semesters[num].semName
           << " has successfully been deleted.\n";
      semesters = tempSem;
      return;

    } else {
      cout << "Invalid class number. Please enter a valid number.\n";
    }
  } else {
    cout << "Invalid input. Please enter a valid number or '-q' to go back.\n";
  }
  cout << endl << "Semester successfully deleted." << endl;
}