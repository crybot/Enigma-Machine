#include <iostream>
#include "enigma.cpp"

int main(int argc, char** argv)
{
  enigma crypter;
  enigma decrypter;

  while(true)
  {
    std::string clear;
    std::string encrypted;
    std::getline(std::cin, clear);

    encrypted = crypter.encrypt(clear);
    std::cout <<  "encrypted message: " << encrypted << std::endl;
    std::cout <<  "decrypted message: " << decrypter.encrypt(encrypted) << std::endl;

  }

  return 0;
}
