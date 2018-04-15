#include <iostream>

struct pair {
  int x;
  int y;
};

pair fib(int i) {
  if(i<=0) {
    pair ret;
    ret.x = 0;
    ret.y = 1;
    return ret;
  } else {
    pair ret;
    pair ab = fib(i-1);
    ret.x = ab.y;
    ret.y = ab.x + ab.y;
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
