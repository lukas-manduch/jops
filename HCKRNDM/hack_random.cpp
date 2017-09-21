#include <vector>
#include <algorithm>
#include <stdio.h>


/** Returns number of ...
 *
 * Precondition: array must be sorted in ascending order
 */
int count_pairs(const std::vector<int>& numbers, int k)
{
	int count = 0;
	auto it1 = numbers.begin();
	auto it2 = numbers.begin() + 1;
	std::vector<int>::const_iterator bak = it2;

	while(it2 != numbers.end()) {

		if( (*it2 - *it1) < k ) {
			it2++;
			bak = it2;
			continue;
		}

		if((*it2 - *it1) == k) {
			it2++;
			count++;
			continue;
		}

		it1++;
		it2 = bak;
	}

	return count;
}


int main()
{
	int n, k;
	std::vector<int> numbers;

	scanf("%d %d", &n, &k);
	numbers.resize(n);

	for(int i = 0; i < n; i++)
		scanf("%d", &numbers[i]);

	std::sort(numbers.begin(), numbers.end());
	printf("%d\n", count_pairs(numbers, k));
	return 0;
}
