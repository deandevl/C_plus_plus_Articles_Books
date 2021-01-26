//
// Created by Rick on 2020-09-20.
//
#include <iostream>
/*
 * Three levels of precision and minimum size:
 * float            4
 * double           8
 * long double      8, 12, or 16
 *
 * Special floats:
 * NaN - "Not a Number"
 * Inf - represents infinity
 */
namespace types {
  void float_formats(){
    std::cout << "\n----------Float Formats------------\n";
    double an{6.0221409e23};
    std::cout << "Avogadro's Number: " << an << "\n";
    float hp{9.75};
    std::cout << "Hogwarts' Platform: " << hp << "\n";
    // double nan{0.0/0.0};
    // std::cout << "NaN: " << nan << "\n";
  }
}

int main() {
  types::float_formats();
  return 0;
}
