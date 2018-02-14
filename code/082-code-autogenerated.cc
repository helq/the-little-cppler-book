#include <iostream>

void momentum(double initial_v, double time) {

  double acction   = 9.8; // m/s^2 acc
  double mass      = 3;   // kg    mass

  double final_v = initial_v + acction * time;
  double momentum = mass * final_v;
  std::cout << "Momentum after " << time
            << "s is: " << momentum << "kg*m/s"
            << std::endl;
}

int main() {
  momentum(10, 2.3);
  momentum(10, 4.2);
  momentum(10, 9);

  return 0;
}

