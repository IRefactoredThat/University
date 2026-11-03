#include <cstdlib>
#include <iostream>

#include "string.h"

int main() {
  String first{String::read()};
  String second{"ana"};

  int pos{first.getSubstringPos(second)};
  if (pos != -1) {
    std::cout << "Has substring 'ana' found at " << pos << '.' << '\n';
  } else {
    std::cout << "Substring 'ana' not found." << '\n';
  }

  String *third = new String("testObj");
  third->write();
  std::cout << " has length " << third->getLength() << "." << '\n';

  String empty{};
  std::cout << "Empty is empty: " << std::boolalpha << (empty.getLength() == 0)
            << ".";

  delete third;
  return EXIT_SUCCESS;
}
