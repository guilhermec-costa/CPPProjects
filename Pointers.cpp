#include "Pointers.h"
#include <iostream>
using namespace std;

void Pointers::init() {
  // A pointer stores a memory address of another variable
  // so, the value of a pointer is a memory address
  // The pointer itself has its own memory address as well
  Pointers::pointersArithmetic();
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

void Pointers::pointersAndArrays() {
  int values[] = {1, 2, 3, 4};
  // arrays are pretty similar to pointers
  // the only difference basically is that arrays knows how much data it
  // contains. Pointers don't
  // pNames = names = &names[0]

  const int ARRAY_SIZE = sizeof(values) / sizeof(int);
  int *pValues = values;

  cout << "iterating with the array itself" << endl;
  for (int i = 0; i < ARRAY_SIZE; i++) {
    cout << "name: " << values[i] << " | memory address: " << &values[i]
         << endl;
  }

  cout << "---------" << endl;
  cout << "iterating with the pointer" << endl;
  cout << pValues << endl;
  for (int i = 0; i < ARRAY_SIZE; i++, pValues++) {
    cout << "name: " << *pValues << " | memory address: " << pValues << endl;
    // increments the pointer position in memory in "x * bytes",
    // depending on the type of the array
  }
  cout << "---------" << endl;

  // it is also possible to access indexes in pointers, as if it was with arrays
  // it will get the value on that index of the array, but via the pointer
  // than, to access the memory address of that position: &pointer
  int *pValuesNew = pValues - ARRAY_SIZE;
  for (int i = 0; i < ARRAY_SIZE; i++) {
    cout << "name: " << pValuesNew[i] << " | memory address: " << &pValuesNew[i]
         << endl;
  }

  cout << "---------" << endl;
  int *pFirstPosition = values;
  int *pLastPosition = &values[ARRAY_SIZE - 1];
  while (pFirstPosition <= pLastPosition) {
    cout << "name: " << pFirstPosition << " | memory address: " << pFirstPosition << endl;
    pFirstPosition++;
  }
  return;
}

void Pointers::pointersArithmetic() {
  string words[] = { 
    "one", 
    "two", 
    "three", 
    "four",  
    "five"
  };
  const int ARRAY_LENGTH = sizeof(words) / sizeof(string);
  const string *pWordsEnd = &words[ARRAY_LENGTH - 1];
  for(int i=0; i < ARRAY_LENGTH; i++, pWordsEnd--) {
    cout << *pWordsEnd << endl;
  }
  pWordsEnd = &words[ARRAY_LENGTH];
  string *pWordsStart = words;
  cout << (long)(pWordsEnd - pWordsStart) << endl;
  pWordsStart+=ARRAY_LENGTH/2;
  cout << *pWordsStart << endl;
}
