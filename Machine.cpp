#include "Machine.h"
#include <iostream>
using namespace std;

Machine::Machine() {
  this->isOn = true;
  cout << "Machine created" << endl;
}

// a variable lives the long its scope lives
Machine::~Machine() { cout << "Machine destroyed" << endl; }
Machine::Machine(std::string cpu, std::string gpu, int RAM)
    : cpu(cpu), gpu(gpu), RAM(RAM){};

// member operator
void Machine::start() {
  isOn = true;
  cout << "Machine is on" << endl;
}

bool Machine::getState() { return isOn; }
std::string Machine::getCpu() { return cpu; }
std::string Machine::getGPU() { return this->gpu; }
