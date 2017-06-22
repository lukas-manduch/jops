#include <stdio.h>
#include <vector>
#include <algorithm>

// Percondition: array is sorted
int solve(int cities, const std::vector<std::pair<int, int>>& roads)
{
	std::vector<int> state;

	state.resize(cities+1, -1); // City 0 doesn't exists
	state[1] = 1; // I can go to pos 1
	for(auto pr : roads) {
		if(state[pr.first] != -1) {
			if(state[pr.second] == -1)
				state[pr.second] = state[pr.first];
			else
				state[pr.second] += state[pr.first];
			state[pr.second] %= 1000000007;
		}
	}
	return state[cities] > 0 ? state[cities] : 0;
}


int main()
{
	int cases;

	scanf("%d", &cases);
	for(int c = 0; c < cases; c++) {
		int citiesC, roadsC, max_from = 0;
		bool sort_arr = false;
		std::vector<std::pair<int, int>> roads;

		scanf("%d %d", &citiesC, &roadsC);
		for(int i = 0; i < roadsC; i++) {
			int from, to;

			scanf("%d %d", &from, &to);
			if (from > to)
				std::swap(from, to);
			roads.push_back(std::make_pair(from, to));
			// Check if array is sorted
			if(from < max_from)
				sort_arr = true;
			max_from = from;

		}
		if(sort_arr)
			std::sort(roads.begin(), roads.end());
		printf("Case %d: %d\n",
		       c + 1,
		       solve(citiesC, roads));

	}
	return 0;
}
