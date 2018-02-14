#include <iostream>

int main()
{
  for (int i=0; i<18; i++) {
    if ((i%3!=0) && (i%7!=0)) {
      std::cout << i << " ";
    } else {
      std::cout << ". ";
    }
  }
  std::cout << std::endl;

  return 0;
}
