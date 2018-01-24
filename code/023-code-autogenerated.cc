#include <iostream>

int main()
{
  double acction   = 9.8; // m/s^2 acceleration
  double mass      = 3;   // kg    mass
  double initial_v = 10;  // m/s   ini. velocity
  double time      = 2.3; // s     time passed
  
  double final_v = initial_v + acction * time;
  
  std::cout << "Velocity after " << time
            << "s is: " << final_v << "m/s"
            << std::endl;
  
  double momentum = mass * final_v;
  
  std::cout << "Momentum after " << time
            << "s is: " << momentum << "kg*m/s"
            << std::endl;

  return 0;
}
