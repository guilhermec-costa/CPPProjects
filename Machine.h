#include <string>
#ifndef MACHINE_H_
#define MACHINE_H_

class Machine {
private:
  bool isOn;
  std::string cpu;

public:
  Machine();
  Machine(std::string cpu);
  void start();
  void stop();
  bool getState();
  std::string getCpu();
};
#endif
