#include <iostream>
#include <string>
#include "enigma.h"

enigma::enigma(std::vector<rotor> rotors, rotor reflector) : rotors(rotors), reflector(reflector) 
{
  for (auto rotor : rotors)
    mirrored_rotors.push_back(rotor.mirror());
}

std::string enigma::encrypt(std::string text)
{
  for (auto& c : text)
  {
    for (auto rotor : rotors)
    {
      c = rotor.encode(c);
    }

    c = reflector.encode(c);

    for (auto it = rotors.rbegin(); it != rotors.rend(); ++it)
    {
      c = (*it).encode(c);
    }
  }

  return text;
}

std::string enigma::decrypt(std::string text)
{
  for (auto& c : text)
  {
    for (auto rotor : mirrored_rotors)
    {
      c = rotor.encode(c);
    }

    c = reflector.encode(c);

    for (auto it = mirrored_rotors.rbegin(); it != mirrored_rotors.rend(); ++it)
    {
      c = (*it).encode(c);
    }
  }

  return text;
}

