#include <algorithm>
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
  std::transform(text.begin(), text.end(), text.begin(),::toupper);
  text.erase(std::remove_if(text.begin(), text.end(), ::isspace), text.end());
  for (auto& c : text)
  {
    for (auto &rotor : rotors)
    {
      rotor.increment(1);
      c = rotor.encode(c);
    }

    c = reflector.encode(c);

    for (auto it = rotors.rbegin(); it != rotors.rend(); ++it)
    {
      c = (*it).mirror().encode(c);
    }
  }

  return text;
}

void enigma::set_state(char first, char second, char third)
{
  rotors[0].set_state(first);
  rotors[1].set_state(second);
  rotors[2].set_state(third);
}
