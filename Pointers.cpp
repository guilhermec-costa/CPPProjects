#include "Pointers.h"
#include <iostream>
using namespace std;

void Pointers::init() {
  int nValue = 10;

  // A pointer stores a memory address of another variable
  // so, the value of a pointer is a memory address
  // The pointer itself has its own memory address as well
  int *pnValue = &nValue;
  cout << pnValue << " | " << &nValue << endl;
  cout << "value via pointer: " << *pnValue << endl;
};

void Pointers::manipulateViaValue(int value) {
  // here, the compiler creates a copy of the "value" variable
  // and manipulates the copy, not the actual variable that was
  // passed as argument. In this case, more memory is allocated to copy the
  // value, which will kept allocated until the scope of the function has gone.
  value = 10;
}
void Pointers::manipulateViaReference(int *value) {
  // here, the compiler manipulates directly the variables,
  // because what is passed is a reference to the original value
  // in some memory address.
  // In this case, no extra memory is allocated, because no copy is created
  *value = 10;
  // value = 10. this would change the memory address of the variable
}
