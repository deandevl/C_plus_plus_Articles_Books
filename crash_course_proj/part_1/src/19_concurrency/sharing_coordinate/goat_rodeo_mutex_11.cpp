//
// Created by Rick on 2020-10-03.
//
#include <future>
#include <mutex>
#include <iostream>

namespace  concurrent {
  void goat_rodeo_mutex(){
    std::cout << "\n----------------Avoiding a race condition with mutex----------------\n";
    const size_t iterations{1'000'000};
    int tin_cans_available{};
    std::mutex tin_can_mutex;

    auto eat_cans = std::async(std::launch::async, [&]{
      for(size_t i{}; i<iterations; i++){
        tin_can_mutex.lock();
        tin_cans_available--;
        tin_can_mutex.unlock();
      }
    });

    auto deposit_cans = std::async(std::launch::async, [&]{
      for(size_t i{}; i<iterations; i++){
        tin_can_mutex.lock();
        tin_cans_available++;
        tin_can_mutex.unlock();
      }
    });

    eat_cans.get();
    deposit_cans.get();
    std::cout << "Tin cans (mutex): " << tin_cans_available << "\n";
  }
}

int main(){
  concurrent::goat_rodeo_mutex();
  return 0;
}