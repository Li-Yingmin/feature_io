//
// Created by liyingmin on 18-10-17.
//
#ifndef FEATURE_IO_FEATURE_IO_H
#define FEATURE_IO_FEATURE_IO_H

#include <string>
#include <iostream>
#include <fstream>
#include <sstream>
namespace io_tool {
/***************
 * change the file ',' to ' '
 * @param in_file_path the input file path
 * @param out_file_path the output file path
 */
void change_file_comma_to_space(std::string &in_file_path, std::string &out_file_path);

/**
 *
 * @param str input string
 * @return string which comma has changed to space
 */
std::string& revise_str_comma_to_space(std::string &str);


}


#endif //FEATURE_IO_FEATURE_IO_H
