//
// Created by Rick on 2020-10-30.
//
#include <thread>
#include <string>
#include <iostream>
#include <queue>

enum command_type {
  open_new_document,
  done_editing
};

struct file_status {
  std::string file_name;
  command_type cmd_type;
};

std::queue<std::string> filenames;
int initialize_filenames() {
  filenames.push("bar_1.doc");
  filenames.push("bar_2.doc");
  filenames.push("bar_3.doc");
  filenames.push("bar_4.doc");
  return filenames.size();
}

file_status get_filename() {
  std::string filename;
  filename = filenames.front();
  filenames.pop();
  if(!filenames.empty()) {
    file_status return_status{filename, open_new_document};
    return return_status;
  }else {
    file_status return_status{filename, done_editing};
    return return_status;
  }
}

void edit_document_in_word(std::string const& filename){
  // todo:: submit filename to Word
}

int main() {
  std::string ans;

  while(ans != "q") {
    std::cout << "Enter 's' for single file or 'b' for batch edit mode.\n";
    std::cout << "Enter 'q' to quit program.\n";
    std::getline(std::cin, ans);
    if(ans == "b") {
      initialize_filenames();
      command_type com_type = open_new_document;
      while (com_type != done_editing) {
        file_status filestatus = get_filename();
        std::cout << "Opening document " << filestatus.file_name << " in Word via detached thread\n";
        std::thread t(edit_document_in_word, filestatus.file_name);
        t.detach();
        com_type = filestatus.cmd_type;
      }
      std::cout << "Done acquiring batched files for editing.\n";
    }else if(ans == "s"){
      std::cout << "Enter file name or 'q' to quit.\n";
      std::getline(std::cin, ans);
      if(ans != "q"){
        std::cout << "Opening document " << ans << " in Word via detached thread\n";
        std::thread t(edit_document_in_word, ans);
        t.detach();
      }
    }
  }
  std::cout << "Finished editing session.\n";
}

