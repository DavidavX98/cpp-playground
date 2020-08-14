#include "game.h"


Game::Game(int h, int w) {
	matrixH = h;
	matrixW = w;
	matrix.resize(h);
	matrixInit();
}

void Game::matrixInit() {
	for (int i = 0; i < matrixH; i++)
	{
		for (int j = 0; j < matrixW; j++) {
			matrix[i].push_back(0);
		}
	}
	lastMatrix = matrix;
}

void Game::setMatrixElem(int x, int y) {
	matrix[x % matrixW][y % matrixH] = 1;
}

void Game::randomPatt() {
	for (int i = 0; i < matrixH; i++)
	{
		for (int j = 0; j < matrixW; j++) {
			matrix[i][j] = rand() % 2;
		}
	}
	lastMatrix = matrix;
}

void Game::pulsarPatt() {
	int y = 10;
	int x = 10;
	setMatrixElem(x + 2, y);
	setMatrixElem(x + 3, y);
	setMatrixElem(x + 4, y);
	setMatrixElem(x + 8, y);
	setMatrixElem(x + 9, y);
	setMatrixElem(x + 10, y);

	setMatrixElem(x + 2, y + 5);
	setMatrixElem(x + 3, y + 5);
	setMatrixElem(x + 4, y + 5);
	setMatrixElem(x + 8, y + 5);
	setMatrixElem(x + 9, y + 5);
	setMatrixElem(x + 10, y + 5);

	setMatrixElem(x + 2, y + 7);
	setMatrixElem(x + 3, y + 7);
	setMatrixElem(x + 4, y + 7);
	setMatrixElem(x + 8, y + 7);
	setMatrixElem(x + 9, y + 7);
	setMatrixElem(x + 10, y + 7);

	setMatrixElem(x + 2, y + 12);
	setMatrixElem(x + 3, y + 12);
	setMatrixElem(x + 4, y + 12);
	setMatrixElem(x + 8, y + 12);
	setMatrixElem(x + 9, y + 12);
	setMatrixElem(x + 10, y + 12);


	setMatrixElem(x, y + 2);
	setMatrixElem(x, y + 3);
	setMatrixElem(x, y + 4);
	setMatrixElem(x, y + 8);
	setMatrixElem(x, y + 9);
	setMatrixElem(x, y + 10);

	setMatrixElem(x + 5, y + 2);
	setMatrixElem(x + 5, y + 3);
	setMatrixElem(x + 5, y + 4);
	setMatrixElem(x + 5, y + 8);
	setMatrixElem(x + 5, y + 9);
	setMatrixElem(x + 5, y + 10);

	setMatrixElem(x + 7, y + 2);
	setMatrixElem(x + 7, y + 3);
	setMatrixElem(x + 7, y + 4);
	setMatrixElem(x + 7, y + 8);
	setMatrixElem(x + 7, y + 9);
	setMatrixElem(x + 7, y + 10);

	setMatrixElem(x + 12, y + 2);
	setMatrixElem(x + 12, y + 3);
	setMatrixElem(x + 12, y + 4);
	setMatrixElem(x + 12, y + 8);
	setMatrixElem(x + 12, y + 9);
	setMatrixElem(x + 12, y + 10);
}

void Game::pentaPatt() {
	int y = 10;
	int x = 10;

	setMatrixElem(x, y + 1);
	setMatrixElem(x + 1, y + 1);

	setMatrixElem(x + 2, y);
	setMatrixElem(x + 2, y + 2);

	setMatrixElem(x + 3, y + 1);
	setMatrixElem(x + 4, y + 1);
	setMatrixElem(x + 5, y + 1);
	setMatrixElem(x + 6, y + 1);

	setMatrixElem(x + 7, y);
	setMatrixElem(x + 7, y + 2);

	setMatrixElem(x + 8, y + 1);
	setMatrixElem(x + 9, y + 1);
}

void Game::DrawShape(std::string pattern) {
	if (pattern == "Random") randomPatt();
	else if (pattern == "Pulsar") pulsarPatt();
	else if (pattern == "Pentadecathlon") pentaPatt();

	lastMatrix = matrix;
}

void Game::newGeneration() {
	for (int i = 0 + !infinite_map; i < matrixH - !infinite_map; i++)
	{
		for (int j = 0 + !infinite_map; j < matrixW - !infinite_map; j++)
		{
			int sum = 0;
			for (int i1 = 0; i1 < 3; i1++)
			{
				for (int j1 = 0; j1 < 3; j1++) {
					int x;
					int y;

 					if (infinite_map) {
						x = i - 1 + i1;
						if (x < 0)
							x = matrixH - 1;
						else if (x >= matrixH)
							x = 0;

						y = j - 1 + j1;
						if (y < 0)
							y = matrixW - 1;
						else if (y >= matrixW)
							y = 0;

						if (x != i || y != j)
							sum += lastMatrix[x][y];
					}
					else {
						x = i - 1 + i1;
						y = j - 1 + j1;

						if ((x != i || y != j))
							sum += lastMatrix[x][y];
					}
				}
			}

			if (lastMatrix[i][j]) {
				if (sum == 2 || sum == 3)
					matrix[i][j] = 1;
				else
					matrix[i][j] = 0;
			}
			else {
				if (sum == 3)
					matrix[i][j] = 1;
				else
					matrix[i][j] = 0;
			}
		}
	}
	lastMatrix = matrix;
}
