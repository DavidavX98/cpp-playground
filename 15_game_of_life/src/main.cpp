#include <iostream>
#include <vector>
#include <windows.h>

class Game {
private:
	int matrixH;
	int matrixW;

	int color;


public:
	std::vector <std::vector <bool>> matrix;
	std::vector <std::vector <bool>> lastMatrix;
	
	Game(int h, int w) {
		matrixH = h;
		matrixW = w;
		matrix.resize(h);
		color = 15;
		matrixInit();
	}

	void matrixInit() {
		for (int i = 0; i < matrixH; i++)
		{
			for (int j = 0; j < matrixW; j++) {
				matrix[i].push_back(0);
			}
		}
	}

	void setMatrixElem(int x, int y) {
		matrix[y % matrixH][x % matrixW] = 1;
	}

	void DrawShape(std::string pattern, int x, int y)  {
		if(pattern == "Block") blockPatt(x, y);
		else if (pattern == "Boat") boatPatt(x, y);
		else if (pattern == "Blinker") blinkerPatt(x, y);
		else if (pattern == "Beacon") beaconPatt(x, y);
		else if (pattern == "Pulsar") pulsarPatt(x, y);
		else if (pattern == "Pentadecathlon") pentaPatt(x, y);
		else if (pattern == "Glider") gliderPatt(x, y);

		/*switch (pattern)
		{
		case "Block":blockPatt(x, y);	break;
		case "Boat":boatPatt(x, y);			break;
		case 3:blinkerPatt(x, y);		break;
		case 4:beaconPatt(x, y);		break;
		case 5:pulsarPatt(x, y);		break;
		case 6:pentaPatt(x, y);			break;
		case 7:gliderPatt(x, y);		break;
		default:						break;
		}*/

		lastMatrix = matrix;
	}

	void clearPatt() {
		for (int i = 0; i < matrixH; i++)
		{
			for (int j = 0; j < matrixW; j++) {
				matrix[i][j] = 0;
			}
		}
	}

	void randomPatt() {
		for (int i = 0; i < matrixH; i++)
		{
			for (int j = 0; j < matrixW; j++) {
				matrix[i][j] = rand() % 2;
			}
		}
	}

	void blockPatt(int x, int y) {
		setMatrixElem(x, y);
		setMatrixElem(x, y+1);
		setMatrixElem(x+1, y);
		setMatrixElem(x+1, y+1);
	}

	void boatPatt(int x, int y) {
		setMatrixElem(x, y);
		setMatrixElem(x+1, y);
		setMatrixElem(x, y+1);
		setMatrixElem(x+2, y+1);
		setMatrixElem(x+1, y+2);
	}

	void blinkerPatt(int x, int y) {
		setMatrixElem(x, y);
		setMatrixElem(x+1, y);
		setMatrixElem(x+2, y);
	}

	void beaconPatt(int x, int y) {
		setMatrixElem(x, y);
		setMatrixElem(x+1, y);
		setMatrixElem(x, y+1);
		setMatrixElem(x+3, y+2);
		setMatrixElem(x+2, y+3);
		setMatrixElem(x+3, y+3);
	}

	void pulsarPatt(int x, int y) {
		setMatrixElem(x+2, y);
		setMatrixElem(x+3, y);
		setMatrixElem(x+4, y);
		setMatrixElem(x+8, y);
		setMatrixElem(x+9, y);
		setMatrixElem(x+10, y);

		setMatrixElem(x + 2, y+5);
		setMatrixElem(x + 3, y+5);
		setMatrixElem(x + 4, y+5);
		setMatrixElem(x + 8, y+5);
		setMatrixElem(x + 9, y+5);
		setMatrixElem(x + 10, y+5);

		setMatrixElem(x + 2, y+7);
		setMatrixElem(x + 3, y+7);
		setMatrixElem(x + 4, y+7);
		setMatrixElem(x + 8, y+7);
		setMatrixElem(x + 9, y+7);
		setMatrixElem(x + 10, y+7);

		setMatrixElem(x + 2, y+12);
		setMatrixElem(x + 3, y+12);
		setMatrixElem(x + 4, y+12);
		setMatrixElem(x + 8, y+12);
		setMatrixElem(x + 9, y+12);
		setMatrixElem(x + 10, y+12);


		setMatrixElem(x, y + 2);
		setMatrixElem(x, y + 3);
		setMatrixElem(x, y + 4);
		setMatrixElem(x, y + 8);
		setMatrixElem(x, y + 9);
		setMatrixElem(x, y + 10);

		setMatrixElem(x+5, y + 2);
		setMatrixElem(x+5, y + 3);
		setMatrixElem(x+5, y + 4);
		setMatrixElem(x+5, y + 8);
		setMatrixElem(x+5, y + 9);
		setMatrixElem(x+5, y + 10);

		setMatrixElem(x+7, y + 2);
		setMatrixElem(x+7, y + 3);
		setMatrixElem(x+7, y + 4);
		setMatrixElem(x+7, y + 8);
		setMatrixElem(x+7, y + 9);
		setMatrixElem(x+7, y + 10);

		setMatrixElem(x+12, y + 2);
		setMatrixElem(x+12, y + 3);
		setMatrixElem(x+12, y + 4);
		setMatrixElem(x+12, y + 8);
		setMatrixElem(x+12, y + 9);
		setMatrixElem(x+12, y + 10);
	}

	void pentaPatt(int x, int y) {
		setMatrixElem(x, y+1);
		setMatrixElem(x+1, y+1);

		setMatrixElem(x+2, y);
		setMatrixElem(x+2, y+2);

		setMatrixElem(x+3, y+1);
		setMatrixElem(x+4, y+1);
		setMatrixElem(x+5, y+1);
		setMatrixElem(x+6, y+1);

		setMatrixElem(x + 7, y);
		setMatrixElem(x + 7, y + 2);

		setMatrixElem(x+8, y + 1);
		setMatrixElem(x + 9, y + 1);
	}

	void gliderPatt(int x, int y) {
		setMatrixElem(x+1, y);
		setMatrixElem(x+2, y+1);
		setMatrixElem(x+2, y+2);
		setMatrixElem(x+1, y+2);
		setMatrixElem(x, y+2);
	}
	
	void newGeneration() {
		for (int i = 0; i < matrixH; i++)
		{
			for (int j = 0; j < matrixW; j++)
			{
				int sum = 0;
				for (int i1 = 0; i1 < 3; i1++)
				{
					for (int j1 = 0; j1 < 3; j1++) {
						int x;
						int y;

						if (i - 1 + i1 < 0)
							x = matrixH - 1;
						else if (i - 1 + i1 > matrixH - 1)
							x = 0;
						else
							x = i - 1 + i1;

						if (j - 1 + j1 < 0)
							y = matrixW - 1;
						else if (j - 1 + j1 > matrixW - 1)
							y = 0;
						else
							y = j - 1 + j1;

						if(x != i || y != j)
							sum += lastMatrix[x][y];
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

	void drawFrame() {
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
		system("cls");
		for (int i = 0; i < matrixH + 2; i++) {
			for (int j = 0; j < matrixW + 3; j++)
			{
				if (j > matrixW + 1)
					color = 15;
				else if (i == 0 || i == matrixH + 1 || j == 0 || j == matrixW + 1)
					color = 16;
				else if (matrix[i-1][j-1])
					color = 224;
				else
					color = 15;
				SetConsoleTextAttribute(hConsole, color);
				std::cout << "  ";
			}
			std::cout << "\n";
		}
	}

	void play(int ticks) {
		for(int i = 0; i < ticks; i++)
		{
			drawFrame();
			newGeneration();
			Sleep(50);
		}
	}
};

int h;
int w;
int patt;
int x;
int y;
int ticks;

std::vector<std::string> listOfPatterns;
HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
CONSOLE_FONT_INFOEX cfi;

void printHeader() {
	SetConsoleTextAttribute(hConsole, 10);
	std::cout << "\t\t=================================\n";
	std::cout << "\t\t====  Conway's Game of Life  ====\n";
	std::cout << "\t\t=================================\n\n";

	SetConsoleTextAttribute(hConsole, 12);
	std::cout << "\tGame of Life este un automat celular conceput de John Horton Conway in 1970.\n"
		<< "Este un joc fara jucator, ceea ce inseamna ca evolutia sa este determinata de starea sa initiala.\n"
		<< "Putem interactiona cu Jocul creand o configuratie initiala si observand modul in care evolueaza.\n\n";
	SetConsoleTextAttribute(hConsole, 14);
	std::cout << "* Pentru a iesi apasa";
	SetConsoleTextAttribute(hConsole, 10);
	std::cout << " CTRL+C\n\n";
}

void initPattList() {
	listOfPatterns.push_back("Stergere");
	listOfPatterns.push_back("Random");
	listOfPatterns.push_back("Block");
	listOfPatterns.push_back("Boat");
	listOfPatterns.push_back("Blinker");
	listOfPatterns.push_back("Beacon");
	listOfPatterns.push_back("Pulsar");
	listOfPatterns.push_back("Pentadecathlon");
	listOfPatterns.push_back("Glider");
}

void printList()
{
	std::cout << "\n";
	for (int i = 0; i < listOfPatterns.size(); i++)
	{
		SetConsoleTextAttribute(hConsole, 14);
		std::cout << "[";
		SetConsoleTextAttribute(hConsole, 12);
		std::cout << i;
		SetConsoleTextAttribute(hConsole, 14);
		std::cout << "] - " << listOfPatterns[i] << ";" << std::endl;
	}
}

void requestMatrixSize() {
	SetConsoleTextAttribute(hConsole, 11);
	std::cout << "Alege inaltimea matricei (>= 20): ";
	std::cin >> h;
	if (h < 20) {
		h = 20;

		SetConsoleTextAttribute(hConsole, 12);
		std::cout << "!!! Ai ales o inaltime mai mica decat 20.\n";
		SetConsoleTextAttribute(hConsole, 10);
		std::cout << " -> Aceasta a fost resetata la 20.\n";
		SetConsoleTextAttribute(hConsole, 11);
	}

	std::cout << "Alege latimea matricei (>= 20): ";
	std::cin >> w;
	if (w < 20) {
		w = 20;
		SetConsoleTextAttribute(hConsole, 12);
		std::cout << "!!! Ai ales o latime mai mica decat 20.\n";
		SetConsoleTextAttribute(hConsole, 10);
		std::cout << " -> Aceasta a fost resetata la 20.\n";
		SetConsoleTextAttribute(hConsole, 11);
	}
}

void drawing(Game &game) {
	bool draw = 1;
	while (draw) {
		printList();

		SetConsoleTextAttribute(hConsole, 11);
		std::cout << "Adauga un pattern din lista de mai sus:";
		std::cin >> patt;
		SetConsoleTextAttribute(hConsole, 10);
		std::cout << "-> Ai ales ";
		SetConsoleTextAttribute(hConsole, 14);
		std::cout << listOfPatterns[patt];
		std::cout << "\n";

		if (patt > 1) {
			SetConsoleTextAttribute(hConsole, 11);
			std::cout << "Alege coordonata x:";
			std::cin >> x;
			if (x < 0) {
				x = 0;

				SetConsoleTextAttribute(hConsole, 12);
				std::cout << "!!! Ai ales o coordonata mai mica decat 0.\n";
				SetConsoleTextAttribute(hConsole, 10);
				std::cout << " -> Aceasta a fost resetata la 0.\n";
			}

			SetConsoleTextAttribute(hConsole, 11);
			std::cout << "Alege coordonata y:";
			std::cin >> y;
			if (y < 0) {
				y = 0;
				SetConsoleTextAttribute(hConsole, 12);
				std::cout << "!!! Ai ales o coordonata mai mica decat 0.\n";
				SetConsoleTextAttribute(hConsole, 10);
				std::cout << " -> Aceasta a fost resetata la 0.\n";
			}
		}
		else if (listOfPatterns[patt] == "Random")
			game.randomPatt();
		else if (listOfPatterns[patt] == "Stergere")
			game.clearPatt();

		game.DrawShape(listOfPatterns[patt], x, y);
		game.drawFrame();

		SetConsoleTextAttribute(hConsole, 14);
		std::cout << "[";
		SetConsoleTextAttribute(hConsole, 12);
		std::cout << "0";
		SetConsoleTextAttribute(hConsole, 14);
		std::cout << "] - Continua\n[";
		SetConsoleTextAttribute(hConsole, 12);
		std::cout << "1";
		SetConsoleTextAttribute(hConsole, 14);
		std::cout << "] - Mai adauga un pattern\n";
		SetConsoleTextAttribute(hConsole, 11);
		std::cout << "Alege una din optiunile de mai sus: ";
		std::cin >> draw;
	}
}

void requestTicks() {
	std::cout << "\nAlege cate iteratii din joc sa se execute: ";
	std::cin >> ticks;
}

int main() {
	::SendMessage(::GetConsoleWindow(), WM_SYSKEYDOWN, VK_RETURN, 0x20000000);      //fullscreen mode

	printHeader();	
	initPattList();
	requestMatrixSize();

	Game game1(h, w);

	drawing(game1);
	requestTicks();

	game1.play(ticks);

	return 0;
}