CXX=clang++
# CXX=g++

# We have -Wno-unused-parameter so that the compiler
# doesn't complain too much about our stubs.

CXXFLAGS = -std=c++17 -Wall -Wextra -Wno-unused-parameter -Wno-unused-private-field

# Change to this before final submission:

#CXXFLAGS = -std=c++17 -Wall -Wextra -Werror

BINARIES=testStudent testRoster1 testRoster2 testRoster3

all: ${BINARIES}

testStudent: testStudent.o Student.o tddFuncs.o
	${CXX} $^ -o $@

testRoster1: testRoster1.o Roster.o Student.o tddFuncs.o
	${CXX} $^ -o $@

testRoster2: testRoster2.o Roster.o Student.o tddFuncs.o
	${CXX} $^ -o $@

testRoster3: testRoster3.o Roster.o Student.o tddFuncs.o
	${CXX} $^ -o $@

tests: ${BINARIES}
	./testStudent
	./testRoster1
	./testRoster2
	./testRoster3

clean:
	/bin/rm -f ${BINARIES} *.o
