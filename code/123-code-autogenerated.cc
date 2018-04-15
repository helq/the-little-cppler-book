#include <iostream>

struct pair {
  int x;
  int y;
};

int main() {
  pair p;
  p.x = 12;
  p.y = 6;
  std::cout << p.x << " " << p.y << std::endl;
  return 0;
}

