#include "NS.h"
#include <iostream>

namespace gmcc {

Cat::Cat() {}
Cat::~Cat() {}
void Cat::speak() {
  std::cout << "meuuwing in namespace" << std::endl;
}
} // namespace gmcc
