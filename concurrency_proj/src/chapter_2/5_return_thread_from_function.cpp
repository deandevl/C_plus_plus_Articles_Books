//
// Created by Rick on 2020-10-31.
//
#include <thread>
#include <iostream>

void some_function() {
  std::cout << "Hello from 'some_function()'\n";
}

void some_other_function(int) {
  std::cout << "Hello from 'some_other_function()'\n";
}

std::thread f() {
  //void some_function();
  return std::thread(some_function);
}
std::thread g() {
  //void some_other_function(int);
  std::thread t(some_other_function,42);
  return t;
}

int main() {
  std::thread t1=f();
  t1.join();
  std::thread t2=g();
  t2.join();
}
