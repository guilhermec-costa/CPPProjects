#include <iostream>
#include <string>
#ifndef MACHINE_H_
#define MACHINE_H_

class Machine {
private:
  bool isOn;
  std::string cpu;
  std::string gpu;
  short int RAM;

private:
  void _start();

public:
  Machine();
  Machine(std::string cpu) {
    // the "this" keyword is a pointer to the memory address of the current
    // instance
    this->cpu = cpu;
    this->RAM = 0;
    this->gpu = "";
    this->_start();
  }
  // constructor base initialization
  Machine(std::string cpu, std::string gpu) : gpu(gpu), cpu(cpu){};
  Machine(std::string cpu, std::string gpu, int RAM);
  Machine(const Machine &other) : cpu(other.cpu), gpu(other.gpu) {
    // const methods, given that it can not modify any property,
    // can be called inside copy constructors
    // passing a references, avoids the compiler creating another Machine
    std::cout << "created by copy" << std::endl;
  }
  static void withCopy(Machine &machine) {
    std::cout << "machine address in the method: " << &machine << std::endl;
  };

  static Machine &create();
  static Machine *createWithPointer();
  static Machine createWithCopyContructor();
  ~Machine();
  void stop() { this->isOn = false; };
  bool getState() const;
  std::string getGPU() const;
  std::string getCpu() const;
  int getRAM() const;
  void setCpu(const std::string cpu) { this->cpu = cpu; }
};
#endif
