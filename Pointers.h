#ifndef POINTERS_H
#define POINTERS_H

enum enumTest {
  ENUM_CONSTANT_1 = 1,
  ENUM_CONSTANT_2 = 2,
  ENUM_CONSTANT_3 = 3,
  ENUM_CONSTANT_4 = 4
};

class Pointers {
public:
  static void init();
  static void manipulateViaValue(int value);
  static void manipulateViaReference(int *value);
  static void pointersAndArrays();
};

#endif
