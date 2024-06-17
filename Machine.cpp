#include "Machine.h"
#include <iostream>
using namespace std;

// member operator
void Machine::start() {
  isOn = true;
  cout << "Machine is on" << endl;
}

bool Machine::getState() { return isOn; }
Machine::Machine(string cpu) { this->cpu = cpu; }
std::string Machine::getCpu() { return cpu; }
