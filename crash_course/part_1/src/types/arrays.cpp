//
// Created by Rick on 2020-09-20.
//
#include <iostream>
#include <iterator>

namespace types {
  void pass_array(int prime[5]) {
    prime[0] = 4;
    prime[1] = 6;
    prime[2] = 8;
    prime[3] = 9;
    prime[4] = 10;
  };
  void arrays() {
    // -----------------fixed arrays-----------------------
    /*
     * fixed arrays cannot have a length based on user input or some value calculated at runtime.
     * fixed arrays have a fixed length that cannot be changed
     */
    // initialize with values
    int my_array_1[4]{1, 2, 3, 4}; //fixed length or size array and initialized
    int my_array_2[]{1, 2, 3, 4}; //short cut for initializing arrays with values

    // using a symbolic constant
    constexpr int array_length{4};
    int my_array_3[array_length]{}; //initializes all elements to zero
    int my_array_4[5];  //elements are uninitialized -- values could be anything

    std::cout << "-----------------Arrays-----------------------" << "\n";

    // -----------------finding the size----------------
    // to find the number of elements in an array use std::size() from <iterator>
    std::cout << "\nThe number of elemnets of my_array_1: " << std::size(my_array_1) << "\n";

    //------------------iterating arrays--------------------------
    //using a for loop
    unsigned long maximum = 0;
    for(size_t i = 1; i < std::size(my_array_1); i++){
      if(my_array_1[i] > maximum){
        maximum = my_array_1[i];
      }
    }
    std::cout << "my_array_1 maximum = " << maximum << "\n";

    //using range
    unsigned long minimum = 100000;
    for(int value : my_array_1){
      if(value < minimum){
        minimum = value;
      }
    }
    std::cout << "my_array_1 minimum " << minimum << "\n";
    // ------------------passing arrays to function arguments------------
    /* c++ does NOT copy an array when an array is passed into a function.
     * Instead the ACTUAL array is passed.
     */

    int my_prime[]{1, 2, 3, 5, 7};
    std::cout << "Array before pass_array(): " << "\n";
    for(int value : my_prime){    //range based loop
      std::cout << value << "\n";
    }

    // call pass_array() function
    pass_array(my_prime);

    std::cout << "\nArray after pass_array():" << "\n";
    for(int value : my_prime){    //range based loop
      std::cout << value << "\n";
    }

    //-------------------------------char arrays----------------------------
    // String literals can be placed on multiple lines. Whitespace and newlines will be ignored.
    char house[] {"a " "house "
                       "of " "gold."
                 };
    std::cout << "A book holds " << house << "\n";
  }
}
