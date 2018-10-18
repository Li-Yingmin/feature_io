#include "feature_io.h"

int main() {
  std::string in_file_path = "/mnt/hgfs/winproj/data/xface_cluster/zhangqi_new_feature_old_module.txt";
  std::vector<std::vector<std::string>> features;
  std::unordered_map<std::string, std::vector<std::string>> label_features_map;
  if(feature_io_tool::read_features_to_vec(in_file_path, features, feature_io_tool::NONE_LABEL_1F)) {
    std::cout<<"yes"<<std::endl;
  }
  if(feature_io_tool::read_trackid_feats_to_map(in_file_path, label_features_map, feature_io_tool::TRKID_N_NF)) {
    std::cout<<"yes"<<std::endl;
  }
  for(const auto &feat : features) {
    for(const auto &dim : feat) {
      std::cout<< dim << " ";
    }
    std::cout<<std::endl<<std::endl;
  }
  return 0;
}


