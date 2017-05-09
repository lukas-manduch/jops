#include <iostream>

char left_right(int i, int j) {
	if (i == j)
		return '\\';
	return '.';
}

char right_left(int i, int j, int total_size) {
	if ((i + j + 1) == total_size)
		return '/';
	return '.';
}

// Solves only first matrix
char get_conc_char(int i, int j, int total_size) {
	if (i >= total_size) { // right part
		if (j >= total_size)  // down part
			return right_left(i - total_size, j - total_size, total_size);
		else // up part
			return left_right(i-total_size, j);
	}
	else { // left part
		if (j >= total_size)  // down part
			return left_right(i, j - total_size);
		else // up part
			return right_left(i, j, total_size);
	}
}


int main() {
	int cases;
	std::cin >> cases;
	while (cases--) {
		int cols, rows, total_size;
		std::cin >> rows >> cols >> total_size;
		for (int r = 0; r < rows*total_size*2; r++) {
			for (int c = 0; c < cols*total_size * 2; c++) {
				std::cout << get_conc_char(r % (total_size * 2), c % (total_size * 2), total_size);
			}
			std::cout << std::endl;
		}
		std::cout << std::endl;
	}
	return 0;

}