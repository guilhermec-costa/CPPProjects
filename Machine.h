#include <iostream>
#include <string>
#ifndef MACHINE_H_
#define MACHINE_H_

class Machine {
private:
  bool isOn;
  std::string cpu;
  std::string gpu;

public:
  Machine();
  Machine(std::string cpu) {
    // the "this" keyword is a pointer to the memory address of the current
    // instance
    this->cpu = cpu;
  }
  // constructor initialization
  Machine(std::string cpu, std::string gpu) : gpu(gpu), cpu(cpu){};
  Machine(std::string cpu, std::string gpu, int RAM);
  ~Machine();
  void start();
  void stop();
  bool getState();
  std::string getGPU();
  std::string getCpu();
  int RAM;
};
#endif
