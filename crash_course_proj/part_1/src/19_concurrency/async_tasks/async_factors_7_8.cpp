//
// Created by Rick on 2020-10-29.
//
#include <iostream>
#include <set>
#include <chrono>
#include <sstream>
#include <string>


namespace concurrent {
  using namespace std;

  class Stopwatch {
  public:
    Stopwatch(std::chrono::nanoseconds &mResult) : m_result(mResult),
                                                   m_start(std::chrono::high_resolution_clock::now()) {
    }

    ~Stopwatch() {
      m_result = std::chrono::high_resolution_clock::now() - m_start;
    }

  private:
    std::chrono::nanoseconds &m_result;
    const std::chrono::time_point<std::chrono::high_resolution_clock> m_start;
  };

  void test_stopwatch() {
    const size_t n = 1'000'000;
    std::chrono::nanoseconds elapsed;
    {
      Stopwatch stopwatch(elapsed);
      volatile double result{1.23e45};
      for (double i = 1; i < n; i++) {
        result /= i;
      }
    }
    auto time_per_division = elapsed.count() / double(n);
    std::cout << "Nanoseconds per division = " << time_per_division << std::endl;
  }

  template <typename T>

  set<T> factorize(T x){
    std::set<T> result{1};
    for(T candidate{2}; candidate <= x; candidate++){
      if(x % candidate == 0){
        result.insert(candidate);
        x /= candidate;
        candidate = 1;
      }
    }
    return result;
  }

  string factor_task(unsigned long x){
    chrono::nanoseconds elapsed_ns;
    set<unsigned long> factors;
    {
      Stopwatch stopwatch(elapsed_ns);
      factors = factorize(x);
    }
    const auto elapsed_ms =
        chrono::duration_cast<chrono::milliseconds>(elapsed_ns).count();
    stringstream ss;
    return 0;
  }

}



int main(){
  concurrent::test_stopwatch();
  return 0;
}