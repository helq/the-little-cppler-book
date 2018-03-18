#include <iostream>
#include <cmath>

void branches(int i, int spaces, int depth) {
  if(i<pow(2, depth)) {
    std::cout << depth;
    for (int j = 0; j < spaces; j++) {
      std::cout << " ";
    }
    branches(i+1, spaces, depth);
  }
}

void tree(int spacesbefore, int depth) {
  if(depth>=0) {
    for(int j=0; j<spacesbefore; j++) {
      std::cout << " ";
    }
    branches(0, 2*spacesbefore+1, depth);
    std::cout << std::endl;
    tree(2*spacesbefore+1, depth-1);
  }
}

int main()
{
  tree(0, 4);

  return 0;
}
