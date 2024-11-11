#ifndef STUDENT_H
#define STUDENT_H 

#include <string>

class Student {

 public:
  Student(int perm, 
	  std::string lastName, 
	  std::string firstAndMiddleNames);

  // initialize one student from a comma separated string,
  //    e.g. 1234567,Smith,Mary Kay
  Student(std::string csvString);

  int getPerm() const;

  std::string getLastName() const;
  std::string getFirstAndMiddleNames() const;
  std::string getFullName() const;
  std::string toString() const; // e.g. [12345,Smith,Malory Logan]

 private:
  int perm;
  std::string lastName;
  std::string firstAndMiddleNames;
};


#endif
