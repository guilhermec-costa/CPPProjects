#include "Machine.h"
#include <iostream>
using namespace std;

Machine::Machine() {
  cout << "Machine created" << endl;
  this->start();
}

// a variable lives the long its scope lives
Machine::~Machine() { cout << "Machine destroyed" << endl; }
Machine::Machine(std::string cpu, std::string gpu, int RAM)
    : cpu(cpu), gpu(gpu), RAM(RAM){};

Machine& Machine::create() {
  Machine machine;
  return machine;
  // RETURN REFERENCES OF LOCAL VARIABLES IS A HORRIBLE IDEA
  // this method would return a reference that no longer exists
  // after the scope of this method. So, where it would receive this reference, it would actually receive nothing
}

Machine Machine::createWithCopyContructor() {
  // this is no performative
  Machine machine; // here, the constructor is called
  return machine; // here, it would create a temporary copy of machine, to match the type
}

Machine* Machine::createWithPointer() {
  Machine *pMachine = new Machine();
  return pMachine;
}
// member operator
void Machine::start() {
  isOn = true;
  cout << "Machine is on" << endl;
}

// const makes that any variable can not be modified
bool Machine::getState() const { return this->isOn; }
std::string Machine::getCpu() const { return cpu; }
std::string Machine::getGPU() const { return this->gpu; }
