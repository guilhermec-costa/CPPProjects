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
void bit_shifiting();
void bitwise_and();
void preprocessor_statements();
void receive_pointer(void* ptr_to_int);
void receive_reference(int& ref_to_int);
void enums();
void virtual_funcs();
void interfaces();
void heap_stack();
void operator_overloading();
void smart_pointers();
void copy();
void vectors();
void local_static();
void multiple_returns();
void cherno_arrays();
void cherno_strings();
void templates();
void stack_vs_heap();
void macros();
void auto_keyword();
void std_array();
void function_pointers();
void lambdas();
void namespace_std();
namespace Namespaces {
  void namespaces();
};
void reverse_string();
static void static_function();
void threads();
void timing();

class GoingToBeInherited {
private:
  int random_member;
  static int n_members;
public:
  // it is shared across all the objects
  static int const MAX_N_MEMBERS = 10;
  GoingToBeInherited(): random_member(0) {
    std::cout << "no-argument constructor from \"GoingToBeInherited\" called" << std::endl;
    n_members++;
  };
  GoingToBeInherited(int n) {
    this->random_member = n; 
    std::cout << "with-argument constructor from \"GoingToBeInherited\" called" << std::endl;
    n_members++;
  };
  void do_something() { std::cout << "doing something" << std::endl; };
  int get_random_member() const { return this->random_member; };
  std::string describe() const {
    std::stringstream description;
    description << "random member: " << this->random_member;
    return description.str();
  }

  static int get_n_members() { return n_members; }
};


class GoingToInherit : public GoingToBeInherited {
public:
  GoingToInherit() {
    std::cout << "no-argument constructor from \"GoingToInherit\" called" << std::endl;
  };
  
  // constructor inheritance called intentionally
  // it is not possible to call indirect super class constructors. Only direct constructors
  GoingToInherit(int n): GoingToBeInherited(n) {
    if(n > GoingToBeInherited::MAX_N_MEMBERS) {
      std::cout << "Creation of the instance would exceed limit" << std::endl;
      delete this;
      return;
    }
    std::cout << "with-argument constructor from \"GoingToInherit\" called" << std::endl;
  }
};

#endif
