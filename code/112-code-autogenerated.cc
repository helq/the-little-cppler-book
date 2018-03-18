#include <iostream>
void huh(int i, int n) {
  if(i>=n) {
    std::cout << "This is the end: " << n
              << std::endl;
  } else {
    std::cout << i << std::endl;
    huh(i+1, n);
  }
}

int main()
{
  huh(4, 10);

  return 0;
}
