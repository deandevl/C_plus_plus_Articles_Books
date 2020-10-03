//
// Created by Rick on 2020-09-20.
//
#include <iostream>
/*
 * 7 integer types and their size
 * short            2
 * unsigned short   2
 * int              4
 * unsigned int     4
 * long             4
 * unsigned long    4
 * long long        8
 *
 * Avoid unsigned integers --
 * 1. unexpected behavior can result when you mix signed with unsigned integers
 * 2. when subtracting you could end up with a unsigned integer having to receive a negative value
 */

/*
 * 4 integer literals and their prefixes
 * binary: 0b
 * octal: 0 a hold over from B language -- be careful when using a value beginning with 0
 * decimal: the default
 * hexadecimal: 0x
 */

namespace types {
  void integer_formats() {
    std::cout << "\n----------Integer Literal Formats------------\n";
    unsigned short a{0b10101010}; // binary
    std::cout << "Binary: " << a << std::endl;

    int b{0123}; // octal
    std::cout << "Octal: " << b << std::endl;

    unsigned long long d{0xFFFFFFFFFFFFFFFF}; // hexadecimal
    std::cout << "Hexidecimal: " << d << std::endl;
  }
}


