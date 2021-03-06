#include <iostream>

bool surprise(int a, int b) {
  double y = a - 4.5;
  double x = (b - 7)/2;
  double rad = 3;
  bool circle = x*x + y*y < rad*rad;
  return circle;
}

int main() {
  for(int i=0; i<10; i++) {
    for(int j=0; j<15; j++) {
      if( surprise(i, j) ) {
        std::cout << '#';
      } else {
        std::cout << '.';
      }
    }
    std::cout << std::endl;
  }
  return 0;
}

