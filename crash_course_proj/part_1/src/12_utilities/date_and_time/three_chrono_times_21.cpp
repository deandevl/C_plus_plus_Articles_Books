//
// Created by Rick on 2020-10-29.
//
#include <chrono>
#include <iostream>

namespace times {
  using namespace std::chrono;

  void get_chrono_times() {
    auto sys_now = std::chrono::system_clock::now();
    auto hires_now = std::chrono::high_resolution_clock::now();
    auto steady_now = std::chrono::steady_clock::now();

    std::cout << "System clock now: " << sys_now.time_since_epoch().count() << std::endl;
    std::cout << "High res now:" << hires_now.time_since_epoch().count() << std::endl;
    std::cout << "Steady clock now: " << steady_now.time_since_epoch().count() << std::endl;
  }
}
int main(){
  times::get_chrono_times();
  return 0;
}