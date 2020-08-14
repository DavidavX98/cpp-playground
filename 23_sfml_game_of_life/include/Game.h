#pragma once

#include <iostream>
#include <vector>
#include <windows.h>

class Game {
private:

	int color;


public:
	bool infinite_map;
	int matrixH;
	int matrixW;
	std::vector <std::vector <bool>> matrix;
	std::vector <std::vector <bool>> lastMatrix;

	Game(int h, int w);

	void matrixInit();
	void setMatrixElem(int x, int y);
	void randomPatt();
	void newGeneration();
	void pentaPatt();
	void pulsarPatt();
	void DrawShape(std::string pattern);
};
