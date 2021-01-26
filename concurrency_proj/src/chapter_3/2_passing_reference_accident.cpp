//
// Created by Rick on 2020-11-01.
//
#include <mutex>
#include <vector>
#include <thread>
#include <algorithm>
#include <functional>
#include <iostream>

class some_data {
public:
  int a;
  std::string b;
  void do_something()
  {}
};

class data_wrapper {
private:
  some_data data;
  std::mutex m;
public:
  data_wrapper() {
    data.a = 99;
  }
  template<typename Function>
  void process_data(Function func) {
    std::lock_guard<std::mutex> lock(m);
    //std::lock_guard<std::mutex> guard(m);
    func(data);
  }
  int get_a(){return data.a;}
  void set_a(int new_a){
    std::lock_guard<std::mutex> lock(m);
    //std::lock_guard<std::mutex> guard(m);
    data.a = new_a;
  }
};

some_data* unprotected;
data_wrapper x;

void malicious_function(some_data& protected_data) {
  unprotected=&protected_data;
}

void good_foo(){
  x.set_a(106);
}

void bad_foo() {
  x.process_data(malicious_function);
  unprotected->do_something();
  // change the "protected" 'a' value directly -- by passing mutexed set_a()
  unprotected->a = 9999;
}

int main() {
  //note: By running multiple times, the value of 'a' changes depending on thread execution
  // But on occasion the bad_foo() does beat good_foo() and permanently changes the unprotected 'a'
  std::vector<std::thread> threads;
  threads.emplace_back(std::thread(good_foo));
  threads.emplace_back(std::thread(bad_foo));
  std::for_each(threads.begin(),threads.end(),
                std::mem_fn(&std::thread::join));

  std::cout << "Unprotected a value is now = " << x.get_a() << std::endl;
}

