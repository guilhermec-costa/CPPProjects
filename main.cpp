// pre-processor directives
// runs before any code by a pre-processor
#include "Machine.h"
#include "Pointers.h"
#include "functions.h"
#include <climits>
#include <iomanip>
#include <ios>
#include <iostream>
#include <ostream>
#include <sstream>
#include <string>
using namespace std;

int main() {
  Pointers::init();
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
  for (int i = 0; i < sizeof(iValues) / sizeof(typeof(iValues[0])); i++) {
    cout << iValues[i] << endl;
  }

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
