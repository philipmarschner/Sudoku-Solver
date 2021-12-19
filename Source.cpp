#include <vector>
#include <iostream>
#include <string>

#include "Sudoku.h"


int main()
{
    std::vector<std::vector<int>> vect
    {
        {0, 0, 0, 5, 0, 0, 0, 3, 1},
        {0, 0, 0, 0, 4, 2, 0, 7, 8},
        {6, 0, 0, 1, 0, 7, 2, 0, 5},
        {1, 0, 0, 6, 8, 5, 4, 9, 0},
        {7, 4, 0, 2, 0, 0, 0, 0, 0},
        {0, 8, 0, 7, 0, 0, 1, 2, 0},
        {0, 1, 0, 9, 0, 6, 0, 5, 0},
        {3, 0, 0, 0, 5, 0, 7, 0, 2},
        {2, 0, 5, 0, 7, 0, 8, 0, 9}
    };

	Sudoku s;
    s.load(vect);
    s.show();
    s.solve();
    s.show(); 


	return 0;
}