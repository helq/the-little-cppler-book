#include <iostream>
#include <cmath>

double aproxTan(double angle) {
  return sin(angle) / cos(angle);
}

int main() {
  double angle = 0.2;
  double pi = 3.14159265358979;
  std::cout
    << "The tangent of " << angle << "pi "
    << "is aprox. " << aproxTan(pi*angle)
    << std::endl;

  return 0;
}

