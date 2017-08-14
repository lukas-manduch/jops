#include <stdio.h>
#include <vector>
#include <string.h>
#include <algorithm>

#define MAX_LEN 10000
// #define DEBUG

struct Entry
{
	int first{}, second{};
	int position{};
};

int cmpmthd(Entry a, Entry b)
{
	if(a.first != b.first)
		return a.first < b.first;
	return a.second < b.second;
}

#ifdef DEBUG
void da(std::vector<std::vector<int>> matrix)
{
	for(const auto& vec : matrix) {
		for(const auto& item : vec) {
			printf("%4d", item);
		}
		printf("\n");
	}
}
#endif

int lcp(int first, int second, const std::vector<std::vector<int>>& matrix)
{
	int row = matrix.size() - 1;
	int len = matrix[0].size();
	int common = 0;
	int longlen = len - second;

	for(; first < len && second < len && row >= 0; row--) {
		if(matrix[row][first] == matrix[row][second]) {
			common += 1 << row;
			first += 1 << row;
			second += 1 << row;
		}
	}
#ifdef DEBUG
	if((longlen - common) <= 0 )
		return -1000000;
#endif
	return longlen - common;
}

int solve(const char *str, const int len)
{
	std::vector<std::vector<int>> matrix;
	std::vector<Entry> entries;

	// INIT
	entries.resize(len);
	int shift = 0;
	while( (1<<shift) < len)
		shift++;
	matrix.resize(shift + 2); // We need zero row to hold char values
	for(auto& vec : matrix)
		vec.resize(len);

	// Compute first row
	for(int i = 0; i < len; i++)
		matrix[0][i] = str[i];

	// Compute other rows
	for(int current = 0; current <= shift/* in cycle is + 1*/; current++) {
		int index = current + 1; // Because we have special zero row...
		int powered = 1 << current;

		// Load entries
		for(int i = 0; i < len; i++) {
			entries[i].first = matrix[index - 1][i];
			int cat = ((i+powered) < len)
				? matrix[index - 1][(i+powered)]
				: -1;

			entries[i].second = cat;
			entries[i].position = i;
		}

		std::stable_sort(entries.begin(), entries.end(), cmpmthd);

		int position = -1;
		for(int i = 0; i < len; i++) {
			if (i > 0
			    && cmpmthd(entries[i], entries[i-1])
			    == cmpmthd(entries[i-1], entries[i]))
				;
			else
				position++;
			matrix[index][entries[i].position] = position;
		}
	}
#ifdef DEBUG
	da(matrix);
#endif
	// Now is matrix solved, lets do LCP
	int sum = 0;
	for(int i = 0; i < len; i++) {
		if(i==0)        // First row is special case
			sum += len - entries[i].position;
		else {
#ifdef DEBUG
			printf("BEFORE lcp %d %d, sum is %d\n",
			       entries[i-1].position,
			       entries[i].position,
			       sum);
#endif

			sum += lcp(entries[i-1].position,
			           entries[i].position,
			           matrix);
		}
	}

	return sum;
}


int main()
{
	int cases;

	scanf("%d", &cases);
	while(cases--) {
		char arr[MAX_LEN];
		size_t len;

		scanf("%s", arr);
		len = strlen(arr);
		printf("%d\n", solve(arr, len));
	}

	return 0;
}
