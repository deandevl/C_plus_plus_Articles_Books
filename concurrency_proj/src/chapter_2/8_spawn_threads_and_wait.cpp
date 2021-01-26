//
// Created by Rick on 2020-10-31.
//
#include <vector>
#include <thread>
#include <algorithm>
#include <functional>
#include <iostream>

void do_work(unsigned id){
  std::cout << "Doing work no. " << id << std::endl;
}

void f() {
  std::vector<std::thread> threads;
  for(unsigned i=0;i<20;++i) {
    threads.push_back(std::thread(do_work,i));
  }
  std::for_each(threads.begin(),threads.end(),
                std::mem_fn(&std::thread::join));
  //note: mem_fn converts member function to function object
}

int main() {
  f();
}
