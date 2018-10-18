//
// Created by liyingmin on 18-10-17.
//

#include "feature_io.h"

bool feature_io_tool::revise_file_comma_to_space(const std::string &in_file_path, const std::string &out_file_path) {
  if(in_file_path == out_file_path) {
    return false;
  }
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
  return true;
}

void feature_io_tool::revise_str_comma_to_space(std::string &str) {
  for(auto &ch : str) {
    if(ch == ',') {
      ch = ' ';
    }
  }
}
void read_label_1f(const std::string &in_file_path, std::vector<std::vector<std::string>> &features,
                   const unsigned int &feature_dim);
void read_none_label_1f(const std::string &in_file_path, std::vector<std::vector<std::string>> &features,
                        const unsigned int &feature_dim);
void read_trkid_n_nf(const std::string &in_file_path, std::vector<std::vector<std::string>> &features,
                     const unsigned int &feature_dim);

bool feature_io_tool::read_features_to_vec(const std::string &in_file_path,
                                           std::vector<std::vector<std::string>> &features,
                                           const unsigned char &content_type, const unsigned int &feature_dim) {
  if(in_file_path.empty() || feature_dim != 256 || feature_dim != 128) {
    return false;
  }
  switch (content_type) {
    case LABEL_1F:
      read_label_1f(in_file_path, features, feature_dim);
      break;
    case NONE_LABEL_1F:
      read_none_label_1f(in_file_path, features, feature_dim);
    case TRKID_N_NF:
      read_trkid_n_nf(in_file_path, features, feature_dim);
    default:
      break;
  }
  return true;
}


void read_label_1f(const std::string &in_file_path, std::vector<std::vector<std::string>> &features,
                   const unsigned int &feature_dim) {
  std::ifstream in(in_file_path);
  std::string line;
  std::vector<std::string> s_one_feature;
  while(getline(in, line)) {
    feature_io_tool::revise_str_comma_to_space(line);
    std::istringstream feature_stream(line);
  }
}

void read_none_label_1f(const std::string &in_file_path, std::vector<std::vector<std::string>> &features,
                        const unsigned int &feature_dim) {

}

void read_trkid_n_nf(const std::string &in_file_path, std::vector<std::vector<std::string>> &features,
                     const unsigned int &feature_dim) {

}


