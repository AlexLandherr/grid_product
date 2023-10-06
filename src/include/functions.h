#include <array>
#include <string>

#ifndef FUNCTIONS_H
#define FUNCTIONS_H

namespace func {
    std::array<std::array<std::string, 20>, 20> txt_file_to_array(std::string file_path);
    int find_greatest_grid_product();
}

#endif