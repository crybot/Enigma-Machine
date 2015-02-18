#ifndef ROTOR_H
#define ROTOR_H

#include <string>

class rotor
{
  private:
    std::string map;
    char ringstellung;
    static const std::string ALPHABET;

    char shift(char, int);

  public:
    rotor(std::string map);
    rotor mirror();
    std::string get_map();
    char encode(char);
    void increment(int);
    void set_state(char);
};

#endif
