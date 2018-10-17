//
// Created by liyingmin on 18-10-17.
//

#include "feature_io.h"
namespace io_tool {

void change_file_comma_to_space(std::string &in_file_path, std::string &out_file_path) {
  std::ifstream in(in_file_path);
  std::ofstream out(out_file_path);
  std::string line;
  while(getline(in, line)) {
    for(auto &ch : line) {
      if(ch == ',') {
        ch = ' ';
      }
    }
    out<<line<<std::endl;
  }
}

std::string &revise_str_comma_to_space(std::string &str) {
  for(auto &ch : str) {
    if(ch == ',') {
      ch = ' ';
    }
  }
  return str;
}


}

