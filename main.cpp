#include "feature_io.h"

int main() {
  std::string in_file_path = "/mnt/hgfs/winproj/data/xface_cluster/duoceng15feat.txt";
  std::string out_file_path = in_file_path + ".withoutcomma.txt";
  io_tool::change_file_comma_to_space(in_file_path, out_file_path);
  return 0;
}


