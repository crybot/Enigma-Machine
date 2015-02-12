#include "rotor.h"

const std::string rotor::ALPHABET = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";

rotor::rotor(std::string map) : map(map)
{

}

std::string rotor::get_map()
{
  return map;
}

rotor rotor::mirror()
{
  std::string mirror;
  mirror.resize(map.size());

  for (int i=0; i<map.size(); i++)
  {
    mirror[map[i] - 'A'] = ALPHABET[i];
  }

  return rotor(mirror);
}

char rotor::encode(char c)
{
  return map[c - 'A'];
} 

void rotor::increment(int k)
{
  for (auto &c: map) 
    c = shift(c, k);

}

char rotor::shift(char c, int k)
{
  c += k;
  if (c > 'Z') return 'A' + (c - 'Z' - 1);
  else if (c < 'A') return 'Z' - ('A' - c + 1);

  return c;
}
