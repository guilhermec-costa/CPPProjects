// pre-processor directives
// runs before any code by a pre-processor
#include "particle/main.h"
#include "sdlAPI/main.h"
#include "agame/main.h"
#include "Cat.h"
#include "Machine.h"
#include "NS.h"
#include "functions.h"
#include <climits>
#include <cstddef>
#include <cstring>
#include <iomanip>
#include <ios>
#include <iostream>
#include <ostream>
#include <sstream>
#include <string>
// build process:
// preprocessing -> the compiler runs the preprocessor
// compilation(translation) proccess(.o) -> Compiler: converts .cpp files (translation unity) into .o files (machine code)
//  -> tokenizing
//  -> abstract syntax tree
//  -> after makes the tree, than it generates machine code
// linking(links all .o, including .o from libraries) and produces executable
//
//
// it is not always possible to associate a translation unity to a single cpp file
// translation unity is any cpp file that is compiled and translated to a object file. But a cpp file can include another cpp file
// in this case, there is only one translation unity for two cpp files, because only object file will be generated
//
//
// DYNAMIC LIBRARIES: code that the program finds during runtime, not during
// linking
//      -> unix: libcode.so
//      -> windows: code.dll
// STATIC LIBRAIES: code compiled into a binary file, and linked during build
//      -> unix: libcode.a
//      -> windows: code.lib
//      -> can instruct to load code from dynamic library
//
//  header files + static library file to link with + dinamic library files to
//  execute at runtime called by the static library
//
// header files are not compiled. Only when they are include via preprocessor
//  every cpp file is compiled individually into a object file ( transforms cpp code into machine code)
//  linker: links all .o files and creates a executable
//
//
//  function declaration == function prototype
//  function definition == function prototype + function body
//
//  any function can be used anywhere, even if its DEFINITION is typed in another file
//  the compiler only needs to see the DECLARATION of the function in the file that is going to be used
//  and it is going to trust that the DEFINITON is declared elsewhere
//
//  now, the LINKER finds all the definitions of the functions, and matches them against its declarations
//  via the .o files
//
//  FILES have no MEANING for the c++ compiler. It is just a data source that feeds the compiler to produce .o files
//
//
//  #pragma once -> header guard: prevents from multiple includes of the same header file a single translation unity


#define CALL(y) std::cout << y << std::endl;
extern int variable_from_translation_unit1;
void function() {

}

using namespace std;
// it is necessary to include the .h where the namespace is defined
using namespace gmcc;
using namespace sdlgame;
using namespace sdlAPI;

void Log(const char*);

struct Anything {};



// recomendation: use structs for POD (plain old data). No behavior. Only methods that manipulates interval variables from the struct
// used for data structures that atre not too much complex. No inheritance
struct Player {
  int x;
  int y;
  int speed;

  Player() {}

  void Move(int x, int y) {
    this->x += x * speed;
    this->y += y * speed;
  }
};

int main() {
  /* Log("hello world"); */
  /* sdlAPI::main(); */
  /* preprocessor_statements(); */
  CALL(5);
  // a not valid pointer. It is fine. It has the memory address of 0. It is either not possible to read from or write to  
  // points to nowhere, and has no value
  //
  //
  // types for pointers are kind of meaningless, if you do not need to write to the memory via the pointer
  int var = 8;
  void* ptr = &var;

  // pointer to the beggining of the block of memory
  #ifndef CHURROS
    std::cout << "Churros not defined" << std::endl;
  #endif
  char* buffer = new char[9];
  int i = 0;
  memset(buffer,'B',9);
  //*ptr = 10;  error here
  
  // pointer to a pointer (double pointer)
  char** ptr_to_char_ptr = &buffer;

   
  std::cout << &buffer << std::endl;
  std::cout << *ptr_to_char_ptr << std::endl;
  delete[] buffer;


  // a reference to a value has the same memory address as the value
  // it is an alias
  int a = 10;
  int* ptr_a = &a;
  int& b = a;
  b = 20;
  std::cout << &b << " " << &a << std::endl;
  
  
  // deferrencing a pointer returns a reference to the memory address that it refers to
  receive_reference(*ptr_a);
  std::cout << a << std::endl;


  Player player;

  std::cout << variable_from_translation_unit1 << std::endl;
  return 0;
}

void variables() {
  /*
  endl: new line(\n) in the output stream buffer + flushes the output stream
  buffer
  */
  int numberX = 3;
  int numberY = 5;
  string dogFirstname = "churros ";
  string dogLastname = "augusto";
  int *pNumberX = &numberX;
  numberX += 2;

  cout << "Hello world!" << endl;
  cout << numberX + numberY << endl;
  cout << *pNumberX << endl;
  cout << dogFirstname + dogLastname << endl;
}

void inputText() {
  cout << "Tell me your name: " << flush;
  string input1;
  string input2;
  cin >> input1;
  cin >> input2;
  cout << "Input 1: " << input1 << endl;
  cout << "Input 2: " << input2 << endl;
}

void integers() {
  int value = 2147483647;
  long longValue = 29464836438;
  short int shortValue = 256;
  cout << sizeof(value) << endl;
  cout << sizeof(shortValue) << endl;
  cout << INT_MAX << endl;
}

void floats() {
  float value = 76.53856385355;
  double dValue = 76.53856385355;
  cout << setprecision(20) << fixed << value << endl;
  cout << setprecision(20) << fixed << dValue << endl;
}

void booleans() {
  bool condition1 = true;
  bool condition2 = false;
  char oneByte1 = '7';
  cout << condition1 << endl;
  cout << condition2 << endl;
  cout << "------" << endl;
  cout << (int)oneByte1 << endl;
  cout << (char)55 << endl;
}

void conditions() {
  float vFloat = 5.5;
  float v2Float = 5.6;

  if (vFloat == v2Float) {
    cout << "equals" << endl;
  } else {
    cout << "not equals" << endl;
  }
  cout << setw(20) << "test" << endl;

  int value1 = 7;
  int value2 = 8;

  if ((value2 != 8 && value1 == 10) || value1 < 10) {
    cout << "Condition: true" << endl;
  } else {
    cout << "Condition: false" << endl;
  }
}

void whileLoops() {
  int i = 0;
  while (i < 10) {
    // cout << i << " " << flush;
    i++;
  }

  int y = 0;
  int j = 0;
  do {
    j = ++y;
    cout << "y: " << y << " | j: " << j << endl;
  } while (y < 10);

  const string password = "hello";
  string input;

  do {
    cout << "Type the password > " << flush;
    cin >> input;

    if (input != password)
      cout << "Invalid password. Try again." << endl;
  } while (input != password);

  cout << "Logged in!" << endl;
}

void forLoops() {
  for (int i = 0; i < 10; ++i) {
    if (i == 5) {
      continue;
    }
    cout << i << endl;
  }
}

void arithmetic() {
  int nValue1 = 6 / 3;
  int nValue2 = 7.0;      // implicit cast
  int nValue3 = (int)7.0; // explicit cast
  double nValue4 = 7 / (double)2;
  int nValue5 = 7 / 3.5; // implicit cast

  cout << nValue4 << endl;
  cout << sizeof(int) << endl;

  for (int i = 1; i <= 10000; i++) {
    cout << "." << flush;
    if (i % 100 == 0 && i > 0) {
      cout << endl;
    }
  }
}

void arrays() {
  int values[5];
  values[0] = 1;
  values[1] = 2;
  cout << values[0] << endl;
  cout << values[1] << endl;
  cout << values[2] << endl;

  // an array is a reference to the memory address of the first element
  int iValues[3] = {1, 2, 3};
  /* for (int i = 0; i < sizeof(iValues) / sizeof(typeof(iValues[0])); i++) {
    cout << iValues[i] << endl;
  } */

  cout << &iValues << endl;
  cout << &iValues[0] << endl;
  cout << *iValues << " | " << iValues[0] << endl;
  cout << "-------" << endl;
  // each element is initialize as 0
  int valuesX[6] = {};
  cout << valuesX[3] << valuesX[5] << endl;

  string names1[] = {"churros", "shoyou"};
  string names2[3];
  string names3[2] = {};
  string names4[1] = {"churros"};
}

void multidimensionalArrays() {
  int values[2][3] = {{1, 2, 3}, {4, 5, 6}};
  for (int i = 0; i < 2; i++) {
    for (int j = 0; j < 3; j++) {
      cout << values[i][j] << endl;
    }
    cout << "-------" << endl;
  }

  int multiplicationFactor;
  cout << "Type a number to see multiplication table > " << flush;
  cin >> multiplicationFactor;

  for (int i = 0; i < 10; i++) {
    cout << multiplicationFactor << " x " << i + 1 << " = "
         << multiplicationFactor * (i + 1) << endl;
  }

  // totalSize = type size * 2 * 2
  // 32 * 2 * 2
  cout << "-------" << endl;
  string names[][2] = {{"churros", "shoyou"}, {"gui", "isa"}};
  for (int i = 0; i < sizeof(names) / sizeof(names[0]); i++) {
    for (int j = 0; j < sizeof(names[0]) / sizeof(string); j++) {
      cout << names[i][j] << " " << flush;
    }
    cout << endl;
  }
}

void switchCase() {
  int value = 1;
  switch (value) {
  case 1: {
    cout << "it is 1" << endl;
    break;
  }
  case 4:
  case 5:
    cout << "it is correct" << endl;
    break;
  default:
    cout << "none of them" << endl;
  }
}

int factorial(int value) {
  if (value == 1 || value == 0)
    return 1;

  return value * factorial(value - 1);
}

void passingValues(int valueAsValue, int &valueAsReference) {
  cout << &valueAsValue << endl;
  cout << &valueAsReference << endl;
}

void stringStreams() {
  int age = 32;
  string dog = "Churros";
  stringstream info;
  info << "name: " << dog << "; age: " << age << endl;
  cout << info.str() << endl;
}

void charArrays() {
  // null string terminator
  // it is a virtual character that indicates where the strings terminates
  char words[] = "churros";
  char *pWords = words;
  for (int i = 0; i < sizeof(words); i++) {
    cout << i << ": " << words[i] << endl;
  }
}

void copyConstructors() {
  Machine machine1("ryzen7700x");

  // copy constructor called implicitly
  Machine machine2 = machine1;
  cout << "--------" << endl;
  cout << "machine 1 address out of method: " << &machine1 << endl;
  cout << &machine2 << endl;
  Machine::withCopy(machine1);
  cout << "machine2 cpu: " << machine2.getCpu() << endl;
}

void newOperator() {
  // new: allocates memory mannualy on the heap
  Machine *machine = new Machine();
  // memory allocated with new, MUST BE deallocated mannually as well
  machine->setCpu("Intel Corei9 9900");
  std::string cpu = machine->getCpu();
  cout << "cpu: " << cpu << endl;
  // dot operator has higher precedence then the star operator
  // this is why "pointerVariable.method" does not work
  // so, (*pointerVariable).method == pointerVariable->method
  cout << "cpu: " << (*machine).getCpu() << endl;
  delete machine; // in this case, call the destructor

  // pointing to nowhere
  Machine *machine2 = NULL;
  // dont call delete on null pointer. CRASH WARNING
  cout << machine2 << endl;
}

void returningObjects() {
  Machine *machine = Machine::createWithPointer();
  machine->setCpu("ryzen7700x");
  cout << machine->getCpu() << endl;
  delete machine;
}

void allocatingMemory() {
  int *pInt = new int;
  delete pInt;

  Machine *pMachine = new Machine[7];
  pMachine[4].setCpu("Ryzen4400x");
  cout << pMachine[4].getCpu() << endl;
  delete[] pMachine;

  char *pChar = new char[100];
  delete[] pChar;

  string name(10, 'a');
  cout << name << endl;
  cout << (char)97 << endl;
}

void show(string words[], int size) {
  // losts the array size. Get only pointer size
  for (int i = 0; i < size; i++) {
    cout << words[i] << endl;
  }
}

void showViaPointer(string *words, int size) {
  // losts the array size. Get only pointer size
  for (int i = 0; i < size; i++) {
    cout << words[i] << endl;
  }
}

void showViaArray(string (&words)[3]) {
  for (int i = 0; i < (sizeof(words) / sizeof(string)); i++) {
    cout << words[i] << endl;
  }
}

string *getArray() {
  string *numbers = new string[3]{"one", "two", "three"};
  // new allocates memory. So, this memory is not going to be diallocated until
  // do it manually
  return numbers;
}

void arraysAndFunctions() {
  string fruits[] = {"apple", "banana", "pineapple"};
  show(fruits, sizeof(fruits) / sizeof(string));
  cout << "-----" << endl;
  showViaPointer(fruits, sizeof(fruits) / sizeof(string));
  cout << "-----" << endl;
  showViaArray(fruits);
  cout << "-----" << endl;
  string *array = getArray();
  delete[] array;
}

void namespaces() {
  gmcc::Cat *const pCatGmcc = new gmcc::Cat();
  gcc::Cat *const pCatGcc = new gcc::Cat();
  pCatGmcc->speak();
  pCatGcc->speak();

  cout << gcc::global_something << endl;
  delete pCatGmcc;
  delete pCatGcc;
};

void inheritance() {
  GoingToInherit *p_rand_class = new GoingToInherit();
  p_rand_class->do_something();
}

void encapsulation() {
  Machine *const pMachine = new Machine();
  delete pMachine;
}

void constructorInheritance() {
  // in C++, constructors are not inherited
  // in other words: it is not possible to call a super class constructor when
  // instanciating a subclass but, in the moment of the creation of the
  // instance, c++ will automatically calls super constructors. it is also
  // possible to specify which direct super constructor to call for each
  // subclass
  //

  GoingToInherit *const p_g_inherit1 = new GoingToInherit();
  // all the constructor hierarquy is called
  std::string description = p_g_inherit1->describe();
  cout << description << endl;
  cout << "------------" << endl;
  GoingToInherit *const p_g_inherit2 = new GoingToInherit(10);
  std::string description2 = p_g_inherit2->describe();
  cout << description2 << endl;
  cout << "------------" << endl;
  // it is already deleted
  GoingToInherit *const p_g_inherit6 = new GoingToInherit(11);
  GoingToInherit *const p_g_inherit7 = new GoingToInherit();
  GoingToInherit *const p_g_inherit8 = new GoingToInherit();
  GoingToInherit *const p_g_inherit9 = new GoingToInherit();
  GoingToInherit *const p_g_inherit10 = new GoingToInherit();
  GoingToInherit *const p_g_inherit11 = new GoingToInherit();
  cout << GoingToInherit::get_n_members() << endl;
}

void bit_shifiting() {
  // 0xFF123456
  unsigned char alpha = 0xff;
  unsigned char _red = 0x12;
  unsigned char _green = 0x34;
  unsigned char _blue = 0x56;
  unsigned int _color = alpha;

  // move 1 byte to the left
  _color <<= 8;
  _color += _red;
  _color <<= 8;
  _color += _green;
  _color <<= 8;
  _color += _blue;
  cout << setfill('0') << setw(8) << hex << _color << endl;
}

void bitwise_and() {
  int color = 0x123456;
  unsigned char red = (color & 0xFF0000) >> 16;
  unsigned char green = (color & 0x00FF00) >> 8;
  unsigned char blue = (color & 0x0000FF);
  // &: compares each bit of both values
  // color= 000100100011010001010110
  // 0xFF = 111111110000000000000000 (mask)
  //result= 000100100000000000000000 
  // 1 && 1 = 1
  // 0 && 0 = 0
  // 1 && 0 = 0

  // gets the red value
  std::cout << hex << (int)red << std::endl;
  std::cout << hex << (int)green << std::endl;
  std::cout << hex << (int)blue << std::endl;
  unsigned char red_again = color >> 16;
  std::cout << hex << (int)red << std::endl;

  // bitwise or: | (if one of them is one, so the result is one)
  // bitwise and: & (if both of them are one, so the result is one)
  // bitwise xor: & (if both are equal, so the result is 0, otherwise, is 1)
}

void preprocessor_statements() {
  #ifdef CHURROS
    const CHURROS number = 7;
    std::cout << "churros symbol representing the number " << number << std::endl;
  #endif
}

void receive_pointer(void* ptr_to_int) {
  // A pointer is just an integer that stores a memory address
  // so, the value of a pointer is a memory address
  // The pointer itself has its own memory address as well
  //
  //
  // pointers and references are basically the same thing
  // semantically speaking they are different
  std::cout << ptr_to_int << std::endl;
}

void receive_reference(int& ref_to_int) {
  // references are sintax sugar on top of pointers
  // references needs to reference an already existing variable
  std::cout << ref_to_int << std::endl;
  std::cout << &ref_to_int << std::endl;
  ref_to_int++;
}
