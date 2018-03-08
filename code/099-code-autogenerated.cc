#include <iostream>

int main()
{
  for(int i=0; i<10; i++) {
    for(int j=0; j<15; j++) {
      if((i+j)%4 == 0) {
        std::cout << '#';
      } else {
        std::cout << '.';
      }
    }
    std::cout << std::endl;
  }

  return 0;
}
