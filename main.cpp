#include <iostream>
#include <vector>
#include <string>
#include <fstream>

/***************
 * change the file ',' to ' '
 * @param in_file_path the input file path
 * @param out_file_path the output file path
 */
void change_comma_to_space(std::string &in_file_path, std::string &out_file_path);
int main() {
  std::string in_file_path = "/mnt/hgfs/winproj/data/xface_cluster/duoceng15feat.txt";
  std::string out_file_path = "/mnt/hgfs/winproj/data/xface_cluster/duoceng15feat.back2.txt";
  change_comma_to_space(in_file_path, out_file_path);
  return 0;
}


void change_comma_to_space(std::string &in_file_path, std::string &out_file_path) {
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
