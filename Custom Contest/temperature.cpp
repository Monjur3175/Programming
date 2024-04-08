#include<iostream>
#include <cmath>

double calculateTemperature(double celsius, double fahrenheit) {
  return (celsius * 1.8) + 32; // formula for converting Celsius to Fahrenheit
}

int main() {
  double celsius = 20; // enter the temperature in Celsius
  double fahrenheit = calculateTemperature(celsius); // calculate the temperature in Fahrenheit
  std::cout << "The temperature in Fahrenheit is: " << fahrenheit << std::endl;
  return 0;
}
