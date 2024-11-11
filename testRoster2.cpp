#include "Student.h"
#include "Roster.h"
#include <iostream>
#include <sstream>
#include "tddFuncs.h"
using namespace std;

int main() {
  cout << "Testing class Roster..." << endl;

  std::string testRosterSource = std::string("") +
    "perm,lname,fname\n" +
    "1234567,Smith,Malory Logan\n" +    // [0]
    "5555555,Perez,Juana\n" +           // [1]
    "2222222,Conrad,Phillip Todd\n" +   // [2]
    "8888888,Preble,Ethan Awesome\n" +  // [3]
    "1111111,Laux,Hunter\n";            // [4]

  Roster r;
  std::istringstream iss(testRosterSource);
  r.addStudentsFromStream(iss);
  
  ASSERT_EQUALS(5,r.getNumStudents());
  ASSERT_EQUALS(3,r.indexOfMaxPermAmongFirstKStudents(5));
  ASSERT_EQUALS(3,r.indexOfMaxPermAmongFirstKStudents(4));
  ASSERT_EQUALS(1,r.indexOfMaxPermAmongFirstKStudents(3));
  ASSERT_EQUALS(1,r.indexOfMaxPermAmongFirstKStudents(2));
  ASSERT_EQUALS(0,r.indexOfMaxPermAmongFirstKStudents(1));

  return 0;
}
