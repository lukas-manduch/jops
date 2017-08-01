#include <stdio.h>
#include <string.h>
#include <vector>
#include <string>
#include <algorithm>



struct Merger
{
	int order[2];
	int position;
};

int cmpmthd(Merger a, Merger b)
{
	return (a.order[0] == b.order[0]) ?
		a.order[1] < b.order[1]:
		a.order[0] < b.order[0];

}

void dump(std::vector<std::vector<int>> &arr)
{
	for(auto a : arr) {
		for(auto b : a) {
			printf("%3d", b);
		}
		printf("\n");
	}
}

void dump(Merger *lst, int ln)
{
	for(int i = 0; i < ln; i++) {
		printf("{%d, %d}", lst[i].order[0], lst[i].order[1]);
	}
	printf("\n");
}
/**
 * \brief Returns suffix array
 *
 * Classic suffix array solving.
 * Matrix although is special:
 *  0 -> special
 *  1 -> 2^0
 *  2 -> 2^1
 *
 * @precondition: array must be big enough to be
 *  doubled
 *
 */
std::vector<int> solve(const char* beads)
{
	std::vector<std::vector<int>> matrix;
	int length;
	int ceil_lg = 0;

	// compute variables
	length = strlen(beads);
	while((1<< ceil_lg) < length)
		ceil_lg++;

	// initialize matrix
	matrix.resize(ceil_lg + 2);
	for(auto &row : matrix)
		row.resize(length);

	Merger lst[90000];      // A lot

	// Copmute first row
	for(int i = 0; i < length; i++) {
		matrix[0][i] = beads[i] - 'a';
	}

	// ALgorithm
	for(int step = 0, curr_lg = 1 << step; // 2^0 = 1
	    step <= ceil_lg;
	    step++, curr_lg = 1 << step) {

		for(int i = 0; i < length; i++) {
			lst[i].order[0] = matrix[step][i];
			lst[i].order[1] =
				matrix[step][(i + curr_lg) % length];
			lst[i].position = i;
		}
		//dump(lst, length);

		std::stable_sort(lst, &lst[length], cmpmthd);

		//dump(lst, length);

		//printf("\n");

		// Save current status, and keep same values
		// on same level
		int pos = -1;   // Will be increased at first iteration
		Merger last;
		last.order[0] = -1;
		for(int i = 0; i < length; i++) {
			if(cmpmthd(last, lst[i]) != // If not same
			   cmpmthd(lst[i], last)) { // as last one
				pos++;
			}
			matrix[step + 1][lst[i].position] = pos;
			last = lst[i];
		}
	}
	//dump(matrix);
	return std::move(matrix[ceil_lg + 1]);
}

int main()
{
	int cases;

	scanf("%d", &cases);
	while(cases--) {
		char beads[90000]; // 9 times more

		scanf("%s", beads);
		std::vector<int> result = solve(beads);
		// Find min
		for(unsigned int i = 0; i < result.size(); i++)
			if(result[i] == 0) {
				printf("%d\n", i + 1);
				break;
			}
		// That's it


	}
	return 0;
}
