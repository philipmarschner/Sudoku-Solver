#pragma once

#include <vector>
#include <iostream>
#include <chrono>
#include <thread>

class Sudoku
{
public:
	Sudoku();
	void load(std::vector<std::vector<int>> vect);
	void show();
	void solve();
	std::vector<int> findNum(int col, int row);
	bool isInRow(int num, int col);
	bool isInCol(int num, int row);
	bool isInBox(int num, int col, int row);
	bool checkBox(int num, int colS, int colE, int rowS, int rowE);
	~Sudoku();

private:
	std::vector<std::vector<int>> sudoku;
};

