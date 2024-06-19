// more pre-processor directives
// defines the prototypes only once, if they are not defined
// so that they can be included in cpp files without recreating the same
// prototypes
#ifndef FUNCTIONS_H_
#define FUNCTIONS_H_
#include <iostream>
#include <sstream>
#include <string>

void variables();
void inputText();
void integers();
void floats();
void booleans();
void conditions();
void whileLoops();
void forLoops();
void arrays();
void multidimensionalArrays();
void switchCase();
int factorial(int value);
void passingValues(int valueAsValue, int &valueAsReference);
void stringStreams();
void arithmetic();
void charArrays();
void reversingString();
void copyConstructors();
void newOperator();
void returningObjects();
void allocatingMemory();
void arraysAndFunctions();
void namespaces();
void inheritance();
void encapsulation();
void constructorInheritance();

class GoingToBeInherited {
private:
  int random_member;
public:
  GoingToBeInherited(): random_member(0) {
    std::cout << "no-argument constructor from \"GoingToBeInherited\"" << std::endl;
  };
  void do_something() { std::cout << "doing something" << std::endl; };
  int get_random_member() const { return this->random_member; };
  std::string describe() const {
    std::stringstream description;
    description << "random member: " << this->random_member << std::endl;
    return description.str();
  }
};

class GoingToInherit : public GoingToBeInherited {
public:
  GoingToInherit() {
    std::cout << "no-argument constructor from \"GoingToInherit\"" << std::endl;
  };
};

#endif
