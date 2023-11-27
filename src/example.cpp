#include "example.h"

#include <dlfcn.h>
#include <iostream>

Dummy::Dummy() : libraryHandle(nullptr), addFunction(nullptr) {
  libraryHandle = dlopen("../target/release/librusty_dll.so", RTLD_LAZY);
  if (libraryHandle != nullptr) {
    addFunction = reinterpret_cast<AddFunction>(dlsym(libraryHandle, "add"));
  } else {
    std::cerr << "Failed to load library: " << dlerror() << std::endl;
  }
}

bool Dummy::doSomething() {
  // Do silly things, using some C++17 features to enforce C++17 builds only.
  constexpr int digits[2] = {100, 101};
  auto [firstDigit, secondDigit] = digits;

  std::cout << "C++ wants to add: " << firstDigit << " and " << secondDigit
            << std::endl;

  if (addFunction != nullptr) {
    // Call the add() function from the library
    int result = addFunction(firstDigit, secondDigit);
    std::cout << "Result from Rust's add() function: " << result << std::endl;
    return true;
  }

  std::cerr << "Failed to get function from library" << std::endl;
  return false;
}

#ifdef ENABLE_DOCTEST_IN_LIBRARY
#include "doctest/doctest.h"
TEST_CASE("we can have tests written here, to test impl. details") {
  CHECK(true);
}
#endif
