#include "Pointers.h"
#include <functional>
#include <iostream>
#include <unordered_map>
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
void Pointers::changeValueViaPointer(int *value, int _new) {
  // here, the compiler manipulates directly the variables,
  // because what is passed is a reference to the original value
  // in some memory address.
  // In this case, no extra memory is allocated, because no copy is created
  *value = _new;
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

void Pointers::reverseString() {
  char text[] = "guilherme";
  const int nChars = sizeof(text) - 1;
  char* pStart = text;
  char* pEnd = &text[nChars - 1];

  while(pStart < pEnd) {
    char checkpoint = *pStart;
    //swaps the memory address value
    *pStart = *pEnd;
    *pEnd = checkpoint;

    pStart++;
    pEnd--;
  }
  cout << text << endl;
}

void Pointers::references() {
  int value1 = 123;
  int& value2 = value1;
  cout << "value 1: " << value1 << " value 2: " << value2 << endl;
  value2 = 700;
  cout << "value 1: " << value1 << " value 2: " << value2 << endl;
  // value2 is a reference to value 1, they are the same thing
  // no new variable is created

  int value3 = 123;
  int *pValue3 = &value3;
  
  changeValueViaReference(value2, 500);
  changeValueViaPointer(pValue3, 700);

  cout << value1 << endl;
  cout << value3 << endl;

}

void Pointers::changeValueViaReference(int &cur, int _new) {
  cur = _new;
}


void Pointers::constness() {
  int valueX = 10;
  int valueY = 9;
  int valueZ = 8;
  int valueA = 7;
  int *pValueX = &valueX;
  *pValueX = 6;
  pValueX = &valueY;

  // pointer to an int that is constant
  // can not change the int value via the pointer
  const int *pValueY = &valueY;
  
  // constant pointer to an int
  // can not change the pointer address
  int *const pValueZ = &valueZ;
  
  // constant pointer to a constant int
  // can not change both int value via the pointer and the pointer address
  const int *const pValueA = &valueA;
}

