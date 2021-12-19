#include "Sudoku.h"

Sudoku::Sudoku()
{
}

void Sudoku::load(std::vector<std::vector<int>> vect)
{
	if (vect.size() != 9)
	{
		std::cout << "Error! Not right amount of rows!\n";
		return;
	}
	for (int i = 0; i < vect.size(); i++)
	{
		if (vect.at(i).size() != 9)
		{
			std::cout << "Error! Row: " << i << " is not of right size\n";
			return;
		}
		for (int j = 0; j < vect.at(i).size(); j++)
		{
			if (vect.at(i).at(j) < 0 || vect.at(i).at(j) > 9)
			{
				std::cout << "Error! Value at: " << i << "," << j << " not legal!\n";
				return;
			}
		}
	}
	sudoku = vect;
}

void Sudoku::show()
{
	if (sudoku.size() == 0)
	{
		std::cout << "No sudoku loaded!";
		return;
	}

	std::cout << "+-------+-------+-------+\n";
				
	for (int i = 0; i < sudoku.size(); i++)
	{
		for (int j = 0; j < sudoku.at(i).size(); j++)
		{
			if (j == 0)
			{
				std::cout << "|";
			}
			if (sudoku.at(i).at(j) == 0)
			{
				std::cout << " .";
			}
			else
			{
				std::cout << " " << sudoku.at(i).at(j);
			}
			
			if (j % 3 == 2)
			{
				std::cout << " |";
			}
		}
		std::cout << std::endl;

		if (i % 3 == 2)
		{
			std::cout << "+-------+-------+-------+\n";
		}
	}
}

void Sudoku::solve()
{
	bool done = false;
	while (!done)
	{
		done = true;
		//List of legal numbers at this position
		std::vector<std::vector<std::vector<int>>> leagalNum(sudoku.size(), std::vector<std::vector<int>>(sudoku.size()));	

		//Find all posible numbers for each position
		for (int row = 0; row < sudoku.size(); row++)
		{
			for (int col = 0; col < sudoku.at(row).size(); col++)
			{
				//Skip if cell not empty
				if (sudoku.at(row).at(col) != 0)
					continue;
				leagalNum[row][col] = findNum(col, row);
				//std::cout << "size: " << leagalNum.at(row).at(col).size() << " at " << col << "," << row << std::endl;
			}
		}

		//Insert number where only one solution exists
		for (int row = 0; row < sudoku.size(); row++)
		{
			for (int col = 0; col < sudoku.at(row).size(); col++)
			{
				//Skip if cell not empty
				if (leagalNum.at(row).at(col).size() == 1)
				{
					sudoku.at(row).at(col) = leagalNum.at(row).at(col).front();
					std::cout << "size: " << leagalNum.at(row).at(col).size() << " at " << col << "," << row << " elelemt: " << leagalNum.at(row).at(col).front()  << std::endl;
					done = false;
				}
			}
		}
		show();
		std::this_thread::sleep_for(std::chrono::milliseconds(1000));
		system("CLS");
	}
}

std::vector<int> Sudoku::findNum(int col, int row)
{
	std::vector<int> nums;

	for (int i = 1; i < sudoku.size() + 1; i++)
	{
		if (isInRow(i, col))
			continue;
		if (isInCol(i, row))
			continue;
		if (isInBox(i, col, row))
			continue;
		nums.push_back(i);
	}
	return nums;
}

bool Sudoku::isInRow(int num, int col)
{
	for (size_t r = 0; r < sudoku.size(); r++)
	{
		if (sudoku.at(r).at(col) == num)
		{
			return true;
		}
	}
	return false;
}

bool Sudoku::isInCol(int num, int row)
{
	for (size_t c = 0; c < sudoku.size(); c++)
	{
		if (sudoku.at(row).at(c) == num)
		{
			return true;
		}
	}
	return false;
}

bool Sudoku::isInBox(int num, int col, int row)
{
	//for box 1, 2 and 3
	if (row < 3)
	{
		//box 1
		if (col < 3)
			if (checkBox(num, 0, 2, 0, 2))
				return true;
		//box 2
		if (col > 2 && col < 6)
			if (checkBox(num, 3, 5, 0, 2))
				return true;
		//box 3
		if (col > 5)
			if (checkBox(num, 6, 8, 0, 2))
				return true;
	}

	//for box 4, 5 and 6
	if (row > 2 && row < 6)
	{
		//box 4
		if (col < 3)
			if (checkBox(num, 0, 2, 3, 5))
				return true;
		//box 5
		if (col > 2 && col < 6)
			if (checkBox(num, 3, 5, 3, 5))
				return true;
		//box 6
		if (col > 5)
			if (checkBox(num, 6, 8, 3, 5))
				return true;
	}

	//for box 7, 8 and 9
	if (row > 5)
	{
		//box 7
		if (col < 3)
			if (checkBox(num, 0, 2, 6, 8))
				return true;
		//box 8
		if (col > 2 && col < 6)
			if (checkBox(num, 3, 5, 6, 8))
				return true;
		//box 9
		if (col > 5)
			if (checkBox(num, 6, 8, 6, 8))
				return true;
	}

	return false;
}

bool Sudoku::checkBox(int num, int colS, int colE, int rowS, int rowE)
{
	for (int row = rowS; row < rowE + 1; row++)
	{
		for (int col = colS; col < colS + 1; col++)
		{
			if (sudoku.at(row).at(col) == num)
			{
				return true;
			}
		}
	}
	return false;
}

Sudoku::~Sudoku()
{
}
