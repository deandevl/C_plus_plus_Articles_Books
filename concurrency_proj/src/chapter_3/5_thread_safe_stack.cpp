//
// Created by Rick on 2020-11-01.
//
#include <exception>
#include <stack>
#include <mutex>
#include <memory>
#include <vector>
#include <thread>
#include <algorithm>
#include <functional>
#include <iostream>

struct empty_stack: std::exception {
  const char* what() const throw() {
    return "empty stack";
  }
};

template<typename T>
class threadsafe_stack {
private:
  std::stack<T> data;
  mutable std::mutex m;
public:
  threadsafe_stack(){}
  threadsafe_stack(const threadsafe_stack& other) {
    std::lock_guard<std::mutex> lock(other.m);
    data=other.data;
  }
  threadsafe_stack& operator=(const threadsafe_stack&) = delete;

  void push(T new_value) {
    std::lock_guard<std::mutex> lock(m);
    data.push(new_value);
  }
  std::shared_ptr<T> pop() {
    std::lock_guard<std::mutex> lock(m);
    if(data.empty()) throw empty_stack();
    std::shared_ptr<T> const res(std::make_shared<T>(data.top()));
    data.pop();
    return res;
  }
  void pop(T& value) {
    std::lock_guard<std::mutex> lock(m);
    if(data.empty()) throw empty_stack();
    value=data.top();
    data.pop();
  }
  bool empty() const {
    std::lock_guard<std::mutex> lock(m);
    return data.empty();
  }
};

void check_empty(threadsafe_stack<int> si, bool& is_empty){
  is_empty = si.empty();
}

int main() {
  threadsafe_stack<int> si;
  /*
  std::vector<std::thread> threads;

  bool is_empty;
  threads.emplace_back(std::thread(check_empty, si, is_empty));
  std::cout << "Is empty: " << is_empty << std::endl;
   */

  si.push(5);
  si.push(99);
  si.pop();
  if(!si.empty()) {
    int x;
    si.pop(x);
    std::cout << "Poped x value: " << x << std::endl;
  }
}

