//
// Created by Rick on 2020-11-21.
//
#include <mutex>
#include <condition_variable>
#include <thread>
#include <queue>
#include <string>
#include <iostream>
#include <vector>

struct Employee{
  std::string name;
  short id;
  int age;
  double wage;
  bool is_sick;
};

Employee create_employee(std::string name, short id, int age, double wage, bool is_sick){
  return Employee{
    name = name,
    id = id,
    age = age,
    wage = wage,
    is_sick = is_sick
  };
}

void process_employee(Employee& employee){
  if(employee.is_sick){
    std::cout << employee.name << " is " << "sick today\n";
  }
}

std::mutex mut;
std::queue<Employee> employee_queue;
std::condition_variable employees_cond;

void employee_preparation_thread(
    std::vector<std::string>& names,
    std::vector<short>& ids,
    std::vector<int>& ages,
    std::vector<double>& wages,
    std::vector<bool>& sick_status){
  for(int i = 0; i < names.size(); i++){
    Employee employee = create_employee(names[i], ids[i], ages[i], wages[i], sick_status[i]);
    std::lock_guard<std::mutex> lk(mut);
    employee_queue.push(employee);
    employees_cond.notify_one();
  }
}

void employee_processing_thread(int n_employees) {
  int count = 0;
  while(count < n_employees) {
    std::unique_lock<std::mutex> lk(mut);
    employees_cond.wait(lk, [] { return !employee_queue.empty(); });
    Employee employee = employee_queue.front();
    employee_queue.pop();
    lk.unlock();
    process_employee(employee);
    count++;
  }
}

int main(){
  std::vector<std::string> names{"Rick", "Jim", "Judy", "Pete"};
  std::vector<short> ids{101, 102, 103, 104};
  std::vector<int> ages{45, 33, 28, 54};
  std::vector<double> wages{34564.0, 67821.0, 39876.0, 102342.0};
  std::vector<bool> sick_status{false, false, true, true};

  std::thread t1(employee_preparation_thread,names,ids,ages,wages,sick_status);
  std::thread t2(employee_processing_thread,names.size());

  t1.join();
  t2.join();
}