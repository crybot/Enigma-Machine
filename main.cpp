#include <iostream>
#include "enigma.cpp"

int main(int argc, char** argv)
{
  std::string message = argv[1]; 

  enigma machine;

  std::cout << machine.encrypt(message) << std::endl;
  std::cout << machine.decrypt(machine.encrypt(message)) << std::endl;
  return 0;
}
