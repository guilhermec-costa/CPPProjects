#ifndef CAT_H_
#define CAT_H_

#include <iostream>
using namespace std;
// if the include is included in the header, there is not need to include in the correspondent .cpp file
namespace gcc {

const bool global_something = true;
class Cat {
public:
  Cat();
  virtual ~Cat();
  void speak();
};
} // namespace gcc

#endif
