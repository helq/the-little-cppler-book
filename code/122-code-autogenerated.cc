#include <iostream>

int main()
{
  char helloagain[] =
      {'H', 'e', 'l', 'l', 'o', ' ', 0, //<- added
      'A', 'g', 'a', 'i', 'n', ' ', ':', ')', 0};
  
  std::cout << helloagain << std::endl;

  return 0;
}
