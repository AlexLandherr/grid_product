#include <vector>
#include <string>

#ifndef FUNCTIONS_H
#define FUNCTIONS_H

namespace func {
    std::vector<std::vector<int>> txt_file_to_vector(std::string file_path);
    int find_greatest_grid_product(std::vector<std::vector<int>> grid);
}

#endif