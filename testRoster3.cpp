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
  std::istringstream iss(testRosterSource);
  r.addStudentsFromStream(iss);
  
  ASSERT_EQUALS(5,r.getNumStudents());
  ASSERT_EQUALS(8888888,r.getStudentAt(3).getPerm());
  ASSERT_EQUALS(1111111,r.getStudentAt(4).getPerm());  
  ASSERT_EQUALS(3,r.indexOfMaxPermAmongFirstKStudents(5));

  r.sortByPermHelper(5); // should put max perm of 0..4 in position 4

  // They should have swapped places

  ASSERT_EQUALS(4,r.indexOfMaxPermAmongFirstKStudents(5));

  ASSERT_EQUALS(1,r.indexOfMaxPermAmongFirstKStudents(4));
  ASSERT_EQUALS(5555555,r.getStudentAt(1).getPerm());
  ASSERT_EQUALS(1111111,r.getStudentAt(3).getPerm());

  r.sortByPermHelper(4); // should put max perm from 0..3 in position 3

  ASSERT_EQUALS(3,r.indexOfMaxPermAmongFirstKStudents(4));
  ASSERT_EQUALS(1111111,r.getStudentAt(1).getPerm());
  ASSERT_EQUALS(5555555,r.getStudentAt(3).getPerm());

  // NOW, sort by perm number completely

  r.sortByPerm();
  std::string expectedToStringResult = std::string("") +
    "{\n" +
    "[1111111,Laux,Hunter],\n" +
    "[1234567,Smith,Malory Logan],\n" +
    "[2222222,Conrad,Phillip Todd],\n" +
    "[5555555,Perez,Juana],\n" +
    "[8888888,Preble,Ethan Awesome]\n" +
    "}\n";
  ASSERT_EQUALS(expectedToStringResult,r.toString());

  return 0;
}
