#include <iostream>
using namespace std;

int main() {
  /*
  endl: new line(\n) in the output stream buffer + flushes the output stream
  buffer
  */
  cout << "hello" << flush;
  cout << "Hello world!" << endl;
  return 0;
}

void outputText() { cout << "Output text" << endl; }
