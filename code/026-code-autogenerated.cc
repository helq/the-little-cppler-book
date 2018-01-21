#include <iostream>

int main()
{
  int var1 = 2*2+20;
  if (var1 >= 7 + 3) {
    std::cout << "i never run :(" << std::endl;
  } else {
    if (var1 > 23) {
      std::cout << "hey!!" << std::endl;
    } else {
      // nothing in this branch
    }
  }

  return 0;
}
