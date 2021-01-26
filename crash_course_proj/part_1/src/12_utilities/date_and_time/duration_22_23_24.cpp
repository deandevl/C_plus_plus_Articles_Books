//
// Created by Rick on 2020-10-29.
//
#include <chrono>
#include <thread>
#include <iostream>

namespace times {
  void get_durations(){
    using namespace std::literals::chrono_literals;
    auto one_s = std::chrono::seconds (1);
    auto thousand_ms = 1000ms;
    std::cout << "one_s == thousand_ms: " << (one_s == thousand_ms) << std::endl;
  }

  void cast_duration(){
    using namespace std::chrono;
    auto billion_ns_as_s = duration_cast<seconds>(1'000'000'000ns);
    std::cout << "billion_ns_as_s = " << billion_ns_as_s.count() << std::endl;
  }

  void wait_duration(){
    using namespace std::chrono;
    using namespace std::literals::chrono_literals;
    auto start = std::chrono::system_clock::now();
    std::this_thread::sleep_for(100ms);
    auto end = std::chrono::system_clock::now();
    auto wait_duration = duration_cast<milliseconds>(end - start);
    std::cout << "wait duration(ms) = " << wait_duration.count() << std::endl;
  }
}
int main(){
  times::get_durations();
  times::cast_duration();
  times::wait_duration();

  return 0;
}