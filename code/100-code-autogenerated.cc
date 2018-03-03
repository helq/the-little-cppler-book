#include <iostream>

int succ(int x) { return x + 1; }

int add(int x, int y) {
  if (y==0) { return x; }
  else      { return succ( add(x, y-1) ); }
}

int main() {
  std::cout
     << add( succ(0), succ(succ(0)) )
     << std::endl;
  return 0;
}

