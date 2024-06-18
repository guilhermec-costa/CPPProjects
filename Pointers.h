#ifndef POINTERS_H
#define POINTERS_H

#include <cstdint>
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
  static void changeValueViaPointer(int *value, int _new);
  static void pointersAndArrays();
  static void pointersArithmetic();
  static void reverseString();
  static void references();
  static void changeValueViaReference(int& cur, int _new);
};

static const int simpleValue = 5;
#endif
