//
// Created by Rick on 2020-10-03.
//
#include <future>
#include <iostream>


//C++ Crash Course: 19 Concurrency and Parallelism
// async returns a "future" object which you can interact with in 3 ways
// future object holds the value of async task--it has a single template parameter
//  that cooresponds with the type of the async task return type.
namespace  concurrent {
  void async_interaction() {
    // query async's "future" about its validity using the valid method
    // if future is not valid then they cannot return a current value
    std::cout << "\n-------------checking if future is valid--------\n";
    auto future_valid = std::async(std::launch::async, [] { return "female"; });
    std::cout << "Future valid() value: " << future_valid.valid() << "\n";

    // get the async's current value
    // note that get() will block until the async task is finished
    std::cout << "\n------------checking the return object of the async function------------\n";
    auto future_get = std::async(std::launch::async, []{return "female";});
    std::cout << "Future get() value: " << future_get.get();

    // check the asymc's status using either std::wait_for() or std::wait_until()
    // using std::wait_for()
    std::cout << "\n------------checking for async function status-----------\n";
    auto sleepy = std::async(std::launch::async, []{std::this_thread::sleep_for(std::chrono::seconds(3));});
    auto not_ready_yet = sleepy.wait_for(std::chrono::seconds(2));
    std::cout << "Future not ready after 2 sec?: " << (not_ready_yet == std::future_status::timeout) << "\n";
    auto totally_ready = sleepy.wait_for(std::chrono::seconds(3));
    std::cout << "Future ready after 4 sec?: " << (totally_ready == std::future_status::ready) << "\n";
  }
}

int main(){
  concurrent::async_interaction();
  return 0;
}
