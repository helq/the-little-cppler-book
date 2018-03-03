#include <iostream>

int succ(int x) {
  return x + 1;
}

int main() {
  std::cout << succ(0)
     << " " << succ(succ(0))
     << " " << succ(0)
     << " " << succ(succ(succ(0)))
     << " " << succ(succ(succ(succ(0))))
     << std::endl;
  return 0;
}

