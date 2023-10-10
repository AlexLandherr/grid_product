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

    int find_greatest_grid_product(std::vector<std::vector<int>> grid) {
        /*Traversing grid via a four-number wide 'window' that scans from left to right;
        from the top row to the bottom row.*/
        int max_product_row = 0;

        for (int i = 0; i < static_cast<int>(grid.size()); i++) {
            //Extract a single row.
            std::vector<int> single_row = grid[i];

            //Looping over the extracted row.
            for (int j = 0; j < (static_cast<int>(single_row.size()) - 3); j++) {
                int a = single_row[j];
                int b = single_row[j + 1];
                int c = single_row[j + 2];
                int d = single_row[j + 3];
                int temp_product = a * b * c * d;

                if (temp_product > max_product_row) {
                    max_product_row = temp_product;
                }
            }
        }

        /*Traversing grid via a four-number wide 'window' that scans from top to bottom;
        from the leftmost column to the rightmost column.*/
        int max_product_column = 0;

        for (int col = 0; col < static_cast<int>(grid.size()); col++) {
            std::vector<int> single_column;

            //Extract single column.
            for (int i = 0; i < static_cast<int>(grid.size()); i++) {
                single_column.push_back(grid[i][col]);
            }

            for (int k = 0; k < (static_cast<int>(single_column.size()) - 3); k++) {
                int a = single_column[k];
                int b = single_column[k + 1];
                int c = single_column[k + 2];
                int d = single_column[k + 3];
                int temp_product = a * b * c * d;

                if (temp_product > max_product_column) {
                    max_product_column = temp_product;
                }
            }
        }

        /*Traversing grid via a four-number long diagonal 'line' that scans from left to right;
        with the diagonal's final number being positioned lower than the first (or pointing from the top left to the bottom right).*/
        int max_product_top_left_bottom_right_diagonal = 0;

        for (int row = 0; row < (static_cast<int>(grid.size()) - 3); row++) {
            for (int column = 0; column < (static_cast<int>(grid.size()) - 3); column++) {
                int a = grid[row][column];
                int b = grid[row + 1][column + 1];
                int c = grid[row + 2][column + 2];
                int d = grid[row + 3][column + 3];
                int temp_product = a * b * c * d;

                if (temp_product > max_product_top_left_bottom_right_diagonal) {
                    max_product_top_left_bottom_right_diagonal = temp_product;
                }
            }
        }
    }
}