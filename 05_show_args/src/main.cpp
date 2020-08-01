#include <iostream>

int main(int argc, char* argv[]) {
	if (argc <= 1) {
		std::cout << "No program arguments found." << std::endl;
		return 1;
	}

	for (int i = 1; i < argc; ++i) {
		std::cout << argv[i] << std::endl;
	}

	return 0;
}