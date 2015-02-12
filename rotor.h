#ifndef ROTOR_H
#define ROTOR_H

#include <string>

class rotor
{
  private:
    std::string map;
    static const std::string ALPHABET;

    char shift(char, int);

  public:
    rotor(std::string map);
    void increment(int);
    std::string get_map();
    rotor mirror();
    char encode(char);
};

#endif
