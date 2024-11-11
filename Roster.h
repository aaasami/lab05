#ifndef ROSTER_H
#define ROSTER_H

#include <iostream>
#include <string>
#include "Student.h"

class Roster {

 public:
  Roster();

  static const int ROSTER_MAX = 1024;
  void addStudentsFromStream(std::istream &is);
  void addStudentsFromFile(std::string filename);
  int getNumStudents() const;
  Student getStudentAt(int index) const;
  std::string toString() const; 
  // Format of Roster::toString() 
  //   opening "{\n", 
  //   one Student toString() per line, each followed by ",\n"
  //   closing "}\n"
  //   No comma on last line before closing }
  // Example:
  //   {\n
  //   [1234567,Smith,Mary Kay],\n
  //   [7654321,Perez,Carlos]\n
  //   }\n

  void sortByPerm(); // use Selection Sort

  void resetRoster(); // delete all students from roster
  
  // By rights, these next two helper functions
  // should probably be private.  We expose them as
  // public so they are easily unit testable.

  void sortByPermHelper(int k); // swaps max perm from [0..k-1] with elem [k-1]
  int indexOfMaxPermAmongFirstKStudents(int k) const;

 private:
  // pointers to Students on heap!
  Student *students[ROSTER_MAX]; 
  int numStudents;

};






#endif
