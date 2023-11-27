#pragma once

/**
 * This is a dummy class to demonstrate features of the boiler plate.
 */
class Dummy {
public:
  /**
   * Default constructor for Dummy (does nothing).
   */
  Dummy();

  /**
   * Returns a bool.
   * @return Always True.
   */
  bool doSomething();

private:
  // Handle for the loaded library
  void *libraryHandle;
  typedef int (*AddFunction)(int, int);
  // Function pointer for the add() function in the library
  AddFunction addFunction;
};

#ifdef ENABLE_DOCTEST_IN_LIBRARY
#include "doctest/doctest.h"
TEST_CASE("we can have tests in headers if we want") {
  Dummy d;
  CHECK(d.doSomething() == true);
}
#endif
