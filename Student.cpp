//name: Shuang Li
//Perm: A2K6Y57
#include "Student.h"
#include <sstream>
#include <string>

Student::Student(int perm, 
		 std::string lastName, 
		 std::string firstAndMiddleNames)
     :perm(perm),lastName(lastName),firstAndMiddleNames(firstAndMiddleNames){
  
}

// construct a Student object from a single line of
// comma separated text, e.g. "1234567,Smith,Mary Kay"

Student::Student (std::string csvString) {

  std::istringstream iss(csvString);

  // This version of getline takes an input string (istream), a string, 
  // and a delimiter character (in this case, comma).
  // We read from the stream until the delimiter is encountered 
  
  std::string permAsString;
  getline(iss, permAsString, ',');
  this->perm = std::stoi(permAsString); // stoi converts std::string to int

  getline(iss, this->lastName, ',');

  getline(iss, this->firstAndMiddleNames, '\n');
}


int Student::getPerm() const { 
  return this->perm;
}

std::string Student::getLastName() const { 
  return this->lastName;
}

std::string Student::getFirstAndMiddleNames() const {
  return this->firstAndMiddleNames;
}

std::string Student::getFullName() const { 
  return this->firstAndMiddleNames + " " + this->lastName;
}

std::string Student::toString() const { 
  // e.g. [12345,Smith,Malory Logan]
  std::ostringstream oss;
  
  oss << "[" 
      << this->getPerm() << ","
      << this->getLastName() << ","
      << this->getFirstAndMiddleNames() << "]";
  return oss.str();
} 

