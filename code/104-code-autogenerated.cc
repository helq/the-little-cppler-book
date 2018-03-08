#include <iostream>

int succ(int x) {
  return x + 1;
}

int add(int x, int y) {
  if (y==0) {
    return x;
  } else {
    return succ( add(x, y-1) );
  }
}

int main() {
  std::cout << succ(0)
     << " " << succ(succ(0))
     << " " << add( succ(succ(0)), 0 )
     << " " << add( succ(0), succ(0) )
     << " " << add( 0, succ(succ(0)) )
     << " " << add( 0, succ(succ(0)) )
     << " " << succ( add( 0, 2 ) )
     << " " << add( 10, 2 )
     << " " << add( 3, 21 )
     << std::endl;
  return 0;
}

