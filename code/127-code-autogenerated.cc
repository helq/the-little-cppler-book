#include <iostream>

struct pair {
  int x;
  int y;
};

pair fib(int i) {
  if(i<=0) {
    return pair{0, 1};
  } else {
    pair ab = fib(i-1);
    return pair{ ab.y, ab.x + ab.y };
  }
}

int main()
{
  pair res;
  res = fib(5);
  std::cout << res.x << " "
            << res.y << std::endl;

  return 0;
}
