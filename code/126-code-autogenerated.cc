#include <iostream>

struct pair {
  int x;
  int y;
};

pair fib(int i) {
  if(i<=0) {
    pair ret = {0, 1};
    return ret;
  } else {
    pair ab = fib(i-1);
    pair ret = { ab.y, ab.x + ab.y };
    return ret;
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
