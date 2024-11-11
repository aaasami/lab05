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
    "1234567,Smith,Malory Logan\n" +
    "5555555,Perez,Juana\n" +
    "2222222,Conrad,Phillip Todd\n" +
    "8888888,Preble,Ethan Awesome\n" +
    "1111111,Laux,Hunter\n";

  Roster r;

  ASSERT_EQUALS(0,r.getNumStudents());

  // Allows me to test reading from a stream
  //  without relying anything external to the test code
  //  i.e. another file on the file system.
  // That is one of the principles of "unit testing".

  std::istringstream iss(testRosterSource);
  r.addStudentsFromStream(iss);

  ASSERT_EQUALS(5,r.getNumStudents());

  ASSERT_EQUALS(1234567,r.getStudentAt(0).getPerm());
  ASSERT_EQUALS("Perez",r.getStudentAt(1).getLastName());
  ASSERT_EQUALS("Phillip Todd",r.getStudentAt(2).getFirstAndMiddleNames());
    
  std::string expectedToStringResult = std::string("") +
    "{\n" +
    "[1234567,Smith,Malory Logan],\n" +
    "[5555555,Perez,Juana],\n" +
    "[2222222,Conrad,Phillip Todd],\n" +
    "[8888888,Preble,Ethan Awesome],\n" +
    "[1111111,Laux,Hunter]\n" +
    "}\n";

  ASSERT_EQUALS(expectedToStringResult,r.toString());

  return 0;
}
