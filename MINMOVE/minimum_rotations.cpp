#include <stdio.h>
#include <string.h>
#include <vector>
#include <algorithm>



int solve(char* beads)
{
	int length;
	// compute variables
	length = strlen(beads);
	strcat(beads, beads);

	int min = 0, next = 1, step = 0;
	while((next < length)
	      && (min + step < length)) {
		if(beads[min + step]
		   == beads[next + step]) {
			step++;
		}
		else if (beads[min + step]
		         < beads[next + step]) {
			next = next + step + 1;
			step = 0;
		}
		else {
			min += step + 1;
			next = min + 1;
			step = 0;
		}
	}
	return min;
}

int main()
{
	char a[800000];
	scanf("%s", a);
	printf("%d", solve(a));
	return 0;
}
