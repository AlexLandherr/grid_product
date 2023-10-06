#include "include/functions.h"
#include <string>
#include <vector>
#include <fstream>
#include <sstream>
#include <algorithm>

/*
In the 20x20 grid below, four numbers along a diagonal have been marked red.

The product of these numbers is 26x63x78x14 = 1788696.

What is the greatest product of four adjacent numbers in the same direction (up, down, left, right or diagonally) in the 20x20 grid?
*/

namespace func {
    std::vector<std::vector<int>> txt_file_to_vector(std::string file_path) {
        std::vector<std::vector<int>> grid;
        std::fstream grid_file("num_grid.txt");
        std::string single_line;

        while (std::getline(grid_file, single_line)) {
            std::vector<int> grid_line;

            //Remove irrelevant chars from line.
            single_line.erase(std::remove(single_line.begin(), single_line.end(), ' '), single_line.cend());
            single_line.erase(std::remove(single_line.begin(), single_line.end(), '\n'), single_line.cend());

            //Extract digit pair/number, turn into int and then add to grid_line vector.
            for (int i = 0; i < static_cast<int>(single_line.length()); i+=2) {
                grid_line.push_back(std::stoi(single_line.substr(i, 2)));
            }

            //Add grid_line to grid vector.
            grid.push_back(grid_line);
        }

        return grid;
    }

    int find_greatest_grid_product() {}
}