#include <iostream>
#include <ostream>
#include <string>
using namespace std;

void variables();
void inputText();

int main() {
  inputText();
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
