#include <iostream>

struct pair {
  int x;
  int y;
};


int main()
{
  pair first;
  pair second;
  
  first.x = 12;
  second.x = 45;
  second.y = 3;
  first.y = first.x * second.y;
  second.y = 12;
  
  std::cout << first.x << " "
            << first.y << std::endl
            << second.x << " "
            << second.x << std::endl;

  return 0;
}
