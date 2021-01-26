//
// Created by Rick on 2020-10-03.
//

#include <future>
#include <mutex>
#include <iostream>
#include <condition_variable>

namespace  concurrent {
  void goat_rodeo_condition_var(){
    std::cout << "\n----------------Avoiding a race condition with condition variable----------------\n";
    const size_t iterations{1'000'000};
    int tin_cans_available{};
    std::mutex tin_can_mutex;
    std::condition_variable cv;

    auto eat_cans = std::async(std::launch::async, [&]{
      std::unique_lock<std::mutex> lock{tin_can_mutex};
      cv.wait(lock, [&]{return tin_cans_available == 1'000'000;});
      for(size_t i{}; i < iterations; i++){
        tin_cans_available--;
      }
    });

    auto deposit_cans = std::async(std::launch::async, [&]{
      std::scoped_lock<std::mutex>lock{tin_can_mutex};
      for(size_t i{}; i < iterations; i++){
        tin_cans_available++;
      }
      cv.notify_all();
    });
    eat_cans.get();
    deposit_cans.get();
    std::cout << "Tin cans (condition_value): " << tin_cans_available << "\n";
  }
}

int main() {
  concurrent::goat_rodeo_condition_var();
  return 0;
}