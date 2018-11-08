//
// Created by liyingmin on 18-10-17.
//
#ifndef FEATURE_IO_FEATURE_IO_H
#define FEATURE_IO_FEATURE_IO_H

#include <string>
#include <vector>
#include <iostream>
#include <fstream>
#include <sstream>
#include <unordered_map>
namespace feature_io_tool {

/**
 * a label and a feature of a line
 */
const unsigned char LABEL_1F = 0;

const unsigned char NONE_LABEL_1F = 1;

const unsigned char TRKID_N_NF = 2;
/***************
 * change the file ',' to ' '
 * @param in_file_path the input file path
 * @param out_file_path the output file path
 */
bool revise_file_comma_to_space(const std::string &in_file_path, const std::string &out_file_path);

/**
 * revise a str's comma to space
 * @param str input string
 * @return string which comma has changed to space
 */
void revise_str_comma_to_space(std::string &str);

bool read_features_to_vec(const std::string &in_file_path, std::vector<std::vector<std::string>> &features,
         const unsigned char &content_type = NONE_LABEL_1F, const unsigned int &feature_dim = 256);

bool read_trackid_feats_to_map(const std::string &in_file_path,
                      std::unordered_map<std::string, std::vector<std::string>> &trkid_featvec_uomap,
                      const unsigned char &content_type = TRKID_N_NF, const unsigned int &feature_dim = 256);

} // namespace io_tool

#endif //FEATURE_IO_FEATURE_IO_H
