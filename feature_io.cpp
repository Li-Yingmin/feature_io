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
  in.close();
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

void read_label_1f_to_map(const std::string &in_file_path,
                   std::unordered_map<std::string, std::vector<std::string>> trkid_featvec_uomap,
                   const unsigned int &feature_dim);
void read_trkid_n_nf_to_map(const std::string &in_file_path,
                   std::unordered_map<std::string, std::vector<std::string>> trkid_featvec_uomap,
                   const unsigned int &feature_dim);

bool feature_io_tool::read_features_to_vec(const std::string &in_file_path,
                                           std::vector<std::vector<std::string>> &features,
                                           const unsigned char &content_type, const unsigned int &feature_dim) {
  if(in_file_path.empty() || (feature_dim != 256 && feature_dim != 128)) {
    return false;
  }
  std::cout<<"read feature..."<<std::endl;
  switch (content_type) {
    case LABEL_1F:
      std::cout<<"read_label_1f"<<std::endl;
      read_label_1f(in_file_path, features, feature_dim);
      break;
    case NONE_LABEL_1F:
      std::cout<<"read_none_label_1f"<<std::endl;
      read_none_label_1f(in_file_path, features, feature_dim);
      break;
    case TRKID_N_NF:
      std::cout<<"read_trkid_n_nf"<<std::endl;
      read_trkid_n_nf(in_file_path, features, feature_dim);
      break;
    default:
      break;
  }
  return true;
}

bool feature_io_tool::read_trackid_feats_to_map(const std::string &in_file_path,
                                                std::unordered_map<std::string, std::vector<std::string>> trkid_featvec_uomap,
                                                const unsigned char &content_type, const unsigned int &feature_dim) {
  if(in_file_path.empty() || (feature_dim != 256 && feature_dim != 128)) {
    return false;
  }
  std::cout<<"read feature..."<<std::endl;
  switch (content_type) {
    case LABEL_1F:
      std::cout<<"read_label_1f"<<std::endl;
      read_label_1f_to_map(in_file_path, trkid_featvec_uomap, feature_dim);
      break;
    case TRKID_N_NF:
      std::cout<<"read_trkid_n_nf"<<std::endl;
      read_trkid_n_nf_to_map(in_file_path, trkid_featvec_uomap, feature_dim);
      break;
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
  std::string s_dim;
  std::string s_label;
  while(getline(in, line)) {
    feature_io_tool::revise_str_comma_to_space(line);
    std::istringstream feature_stream(line);
    feature_stream >> s_label;//read label
    while(feature_stream >> s_dim) {
      s_one_feature.push_back(s_dim);
    }
    if(s_one_feature.size() != feature_dim) {
      std::cout<< "feature dim size error"<<std::endl;
    }
    features.push_back(s_one_feature);
    s_one_feature.clear();
  }
  in.close();
}

void read_none_label_1f(const std::string &in_file_path, std::vector<std::vector<std::string>> &features,
                        const unsigned int &feature_dim) {
  std::ifstream in(in_file_path);
  std::string line;
  std::vector<std::string> s_one_feature;
  std::string s_dim;
  while(getline(in, line)) {
    feature_io_tool::revise_str_comma_to_space(line);
    std::istringstream feature_stream(line);
    while(feature_stream >> s_dim) {
      s_one_feature.push_back(s_dim);
    }
    if(s_one_feature.size() != feature_dim) {
      std::cout<< "feature dim size error"<<std::endl;
    }
    features.push_back(s_one_feature);
    s_one_feature.clear();
  }
  in.close();
}

void read_trkid_n_nf(const std::string &in_file_path, std::vector<std::vector<std::string>> &features,
                     const unsigned int &feature_dim) {
  std::ifstream in(in_file_path);
  std::string line;
  std::vector<std::string> s_one_feature;
  std::string s_dim;
  std::string track_id;
  std::string feat_num;
  while(getline(in, line)) {
    feature_io_tool::revise_str_comma_to_space(line);
    std::istringstream feature_stream(line);
    feature_stream >> track_id >> feat_num;
    while(feature_stream >> s_dim) {
      s_one_feature.push_back(s_dim);
    }
    if(s_one_feature.size() != feature_dim) {
      std::cout<< "feature dim size error"<<std::endl;
    }
    features.push_back(s_one_feature);
    s_one_feature.clear();
  }
  in.close();
}

void read_label_1f_to_map(const std::string &in_file_path,
                   std::unordered_map<std::string, std::vector<std::string>> trkid_featvec_uomap,
                   const unsigned int &feature_dim) {
  std::ifstream in(in_file_path);
  std::string line;
  std::string s_one_feature;
  std::vector<std::string> featvec;
  std::vector<std::string> one_feat_cnt;
  std::string s_dim;
  std::string s_label;
  while(getline(in, line)) {
    feature_io_tool::revise_str_comma_to_space(line);
    std::istringstream feature_stream(line);
    feature_stream >> s_label;
    while(feature_stream >> s_dim) {
      one_feat_cnt.push_back(s_dim);
      s_one_feature += s_dim;
      s_one_feature += " ";
    }
    if(one_feat_cnt.size() != feature_dim) {
      std::cout<< "feature dim size error"<<std::endl;
    }
    featvec.push_back(s_one_feature);
    trkid_featvec_uomap[s_label] = featvec;
    s_one_feature.clear();
    featvec.clear();
    one_feat_cnt.clear();
  }
  in.close();
}
void read_trkid_n_nf_to_map(const std::string &in_file_path,
                     std::unordered_map<std::string, std::vector<std::string>> trkid_featvec_uomap,
                     const unsigned int &feature_dim) {
  std::ifstream in(in_file_path);
  std::string line;
  std::string s_one_feature;
  std::vector<std::string> featvec;
  std::vector<std::string> one_feat_cnt;
  std::string s_feat_num;
  std::string s_dim;
  std::string s_trackid;
  while(getline(in, line)) {
    feature_io_tool::revise_str_comma_to_space(line);
    std::istringstream feature_stream(line);
    feature_stream >> s_trackid >> s_feat_num;
    for(auto i = 0; i < std::stoi(s_feat_num); ++i) {
      while(feature_stream >> s_dim) {
        one_feat_cnt.push_back(s_dim);
        s_one_feature += s_dim;
        s_one_feature += " ";
      }
      if(one_feat_cnt.size() != feature_dim) {
        std::cout<< "feature dim size error"<<std::endl;
      }
      featvec.push_back(s_one_feature);
      s_one_feature.clear();
      one_feat_cnt.clear();
    }
    trkid_featvec_uomap[s_trackid] = featvec;
    featvec.clear();
  }
  in.close();
}
