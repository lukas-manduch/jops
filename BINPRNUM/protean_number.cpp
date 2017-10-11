#include <stdio.h>
#include <string.h>
#include <stdint.h>

#define MAX_LEN 200
// #define DEBUG

uint64_t max[MAX_LEN]; // Max value at that bit
uint64_t val[MAX_LEN]; // Value of bit

void solve_untill(int until, int solved)
{
	solved++; // Use as iterator
	while(solved <= until) {
		if(solved <= 2) {
			max[solved] = solved;
			val[solved] = solved;
		} else {
			val[solved] = max[solved - 1] + 1;
			max[solved] = val[solved] + max[solved - 2];
		}
#ifdef DEBUG
		printf("Solved %d Values (%d, %d)\n", solved, val[solved], max[solved]);
#endif

		solved++;
	}
}


int main()
{
	unsigned int cases;
	unsigned int solved = 0;
	unsigned int caseID = 1;


	scanf("%d", &cases);
	while(cases--) {
		char binary_number[500];
		size_t num_len;
		unsigned long long output = 0;

		scanf("%s", binary_number);
		num_len = strlen(binary_number);

		if(solved < num_len) {
			solve_untill(num_len, solved);
			solved = num_len;
		}

		// Print output
		for(int i = num_len-1; i >= 0; i--) {
			if(binary_number[i] == '1') {
				output += val[num_len - i];
#ifdef DEBUG
				printf("Adding numi %d, vali %d\n", i, num_len - i);
#endif
			}
		}
		printf("Case %d: %lld\n",caseID, output);
		caseID++;
	}
}
