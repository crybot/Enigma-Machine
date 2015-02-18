#ifndef ENIGMA_H 
#define ENIGMA_H

#include <vector>
#include <string>
#include "rotor.cpp"

class enigma
{
  private:
    std::vector<rotor> rotors;
    std::vector<rotor> mirrored_rotors;
    rotor reflector;

  public:
    enigma(std::vector<rotor> = 
	{  
	rotor("EKMFLGDQVZNTOWYHXUSPAIBRCJ"),
	rotor("AJDKSIRUXBLHWTMCQGZNPYFVOE"),
	rotor("BDFHJLCPRTXVZNYEIWGAKMUSQO")
	},
	rotor = rotor("EJMZALYXVBWFCRQUONTSPIKHGD"));

    std::string encrypt(std::string);
    void set_state(char, char, char);
};


#endif
