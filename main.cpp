#include <climits>
#include <iomanip>
#include <ios>
#include <iostream>
#include <ostream>
#include <string>
using namespace std;

void variables();
void inputText();
void integers();
void floats();
void booleans();
void conditions();
void whileLoops();
void forLoops();

int main() {
  forLoops();
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
