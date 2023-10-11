#include "include/functions.h"
#include <string>
#include <vector>
#include <fstream>
#include <algorithm>

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

    int find_greatest_grid_product(std::vector<std::vector<int>> grid) {
        /*Traversing grid via a four-number wide 'window' that scans from left to right;
        from the top row to the bottom row.*/
        int max_product = 0;

        for (int i = 0; i < static_cast<int>(grid.size()); i++) {
            for (int j = 0; j < (static_cast<int>(grid[i].size()) - 3); j++) {
                if (grid[i][j] * grid[i][j + 1] * grid[i][j + 2] * grid[i][j + 3] > max_product) {
                    max_product = grid[i][j] * grid[i][j + 1] * grid[i][j + 2] * grid[i][j + 3];
                }
            }
        }

        /*Traversing grid via a four-number wide 'window' that scans from top to bottom;
        from the leftmost column to the rightmost column.*/

        for (int col = 0; col < static_cast<int>(grid.size()); col++) {
            for (int k = 0; k < (static_cast<int>(grid.size()) - 3); k++) {
                if (grid[k][col] * grid[k + 1][col] * grid[k + 2][col] * grid[k + 3][col] > max_product) {
                    max_product = grid[k][col] * grid[k + 1][col] * grid[k + 2][col] * grid[k + 3][col];
                }
            }
        }

        /*Traversing grid via a four-number long diagonal 'line' that scans from left to right;
        with the diagonal's final number being positioned lower than the first (or pointing from the top left to the bottom right).*/

        for (int row = 0; row < (static_cast<int>(grid.size()) - 3); row++) {
            for (int column = 0; column < (static_cast<int>(grid.size()) - 3); column++) {
                if (grid[row][column] * grid[row + 1][column + 1] * grid[row + 2][column + 2] * grid[row + 3][column + 3] > max_product) {
                    max_product = grid[row][column] * grid[row + 1][column + 1] * grid[row + 2][column + 2] * grid[row + 3][column + 3];
                }
            }
        }

        /*Traversing grid via a four-number diagonal 'line' that scans from left to right;
        with the diagonal's final number being positioned lower than the first (or pointing from the top right to the lower left).*/

        for (int row = 0; row < (static_cast<int>(grid.size()) - 3); row++) {
            for (int col = 3; col < static_cast<int>(grid.size()); col++) {
                if (grid[row][col] * grid[row + 1][col - 1] * grid[row + 2][col - 2] * grid[row + 3][col - 3] > max_product) {
                    max_product = grid[row][col] * grid[row + 1][col - 1] * grid[row + 2][col - 2] * grid[row + 3][col - 3];
                }
            }
        }

        return max_product;
    }
}