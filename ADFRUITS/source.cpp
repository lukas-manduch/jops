#include <stdio.h>
#include <string.h>
#include <algorithm>

#define MAX 120
// #define DEBUG

void solve(const char* first, const char* second, char* result)
{
	int mat[MAX][MAX];
	int lenFirst = strlen(first);
	int lenSecond = strlen(second);

	// Init
	for(int i = 0; i <= std::max(lenFirst, lenSecond); i++)
		mat[0][i] = mat[i][0] = i;

	int i, j;
	for(i = 1; i <= lenFirst; i++) {
		for(j = 1; j <= lenSecond; j++) {
			if(first[i-1] == second[j-1]) {
				mat[i][j] = mat[i-1][j-1] + 1;

			} else {
				mat[i][j] = std::min(mat[i-1][j], mat[i][j-1]) + 1;
			}
#ifdef DEBUG
			printf("%3d", mat[i][j]);
#endif

		}
#ifdef DEBUG
		printf("\n");
#endif
	}

	i = lenFirst;
	j = lenSecond;

	result += mat[i][j];
	*result = '\0';
	result--;
	while(i!=0 || j!=0) {
		if(!i) {
			*result = second[j-1];
			j--;
			result--;
			continue;
		}
		else if (!j) {
			*result = first[i - 1];
			i--;
			result--;
			continue;
		}
		if(first[i-1] == second[j-1]) {
			*result = first[i-1];
			i--;
			j--;
			result--;
			continue;
		}

		if(mat[i][j-1] < mat[i-1][j]) {
			*result = second[j-1];
			j--;
		}
		else {
			*result = first[i-1];
			i--;
		}
		result--;
	}
	result++;

	// *out = '\0';
	// return out - result;
}

int main()
{
	char first[MAX] , second[MAX];

	while(scanf("%s %s", first, second) != EOF) {
		char result[MAX*2];

		solve(first, second, result);
		printf("%s\n", result);
	}
	return 0;
}
