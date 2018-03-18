#include <iostream>

int main()
{
  char helloagain[] =
      {'H', 'e', 'l', 'l', 'o', ' ',
      'A', 'g', 'a', 'i', 'n', ' ', ':', ')'};
  int hellolen = 14;
  
  for (int i=0; i<hellolen; i++) {
    std::cout << helloagain[i];
  }
  std::cout << std::endl;

  return 0;
}
