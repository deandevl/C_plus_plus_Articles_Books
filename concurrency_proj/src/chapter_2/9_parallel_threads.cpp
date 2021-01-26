//
// Created by Rick on 2020-10-31.
//
#include <thread>
#include <numeric>
#include <algorithm>
#include <functional>
#include <vector>
#include <iostream>

template<typename Iterator,typename T>
struct accumulate_block {
  void operator()(Iterator first,Iterator last,T& result) {
    // show thread's id
    std::cout << "Thread id: " << std::this_thread::get_id() << std::endl;
    result=std::accumulate(first,last,result);
  }
};

template<typename Iterator,typename T>
T parallel_accumulate(Iterator first,Iterator last,T init) {
  unsigned long const length=std::distance(first,last);

  if(!length)
    return init;

  unsigned long const min_per_thread=25;
  unsigned long const max_threads=
      (length+min_per_thread-1)/min_per_thread;

  unsigned long const hardware_threads=
      std::thread::hardware_concurrency();

  //unsigned long const num_threads=
  //    std::min(hardware_threads!=0?hardware_threads:2,max_threads);

  unsigned long const num_threads=hardware_threads;

  unsigned long const block_size=length/num_threads;

  std::cout << "The task is to accumulate the numbers from 0 to " << length << " using " << num_threads << " threads\n";
  std::cout << "Each thread will accumulate " << block_size << " numbers\n";

  std::vector<T> results(num_threads);
  std::vector<std::thread>  threads(num_threads-1);

  Iterator block_start=first;
  for(unsigned long i=0;i<(num_threads-1);++i) {
    Iterator block_end=block_start;
    std::advance(block_end,block_size);
    std::cout << "Assigning thread no. " << i << " -- block start: " << *block_start << " block end: " << *block_end <<std::endl;
    threads[i]=std::thread(
        accumulate_block<Iterator,T>(),
        block_start,block_end,std::ref(results[i]));
    block_start=block_end;
  }

  std::cout << "Main thread -- " << "block start: " << *block_start << " to the last element" << std::endl;
  accumulate_block<Iterator,T>()(block_start,last,results[num_threads-1]);

  // join all the threads
  std::for_each(threads.begin(),threads.end(),
                std::mem_fn(&std::thread::join));

  return std::accumulate(results.begin(),results.end(),init);
}

int main() {
  std::vector<int> vi;
  for(int i=0;i<20;++i) {
    vi.push_back(i);
  }

  int sum=parallel_accumulate(vi.begin(),vi.end(),5);
  std::cout<<"sum="<<sum<<std::endl;
}

