#include <stdio.h>
#include <vector>
#include <algorithm>
#include <queue>

// Precondition: Vector is sorted
int solve(const std::vector<std::pair<int, int>>& positions,
	  int start, int start_val) {
  std::priority_queue<int> vals;
  int arr_pos = positions.size() - 1;
  int station_stops = 0;
  int max_pos = start - start_val;


  while(max_pos > 0) {
    while(true) { // Increase our reach if possible
      if(arr_pos < 0 || // If there is nothing more
	 // Or we are as far as we can be
	 max_pos > positions[arr_pos].first)
	break;
      vals.push(positions[arr_pos--].second);
    }

    if(vals.empty())
      break;

    max_pos -= vals.top();
    vals.pop();
    station_stops++;
  }

  if(max_pos <= 0)
    return station_stops;
  return -1;
}

int main()
{
  int cases;

  scanf("%d", &cases);
  while(cases--) {
    int len;
    std::vector<std::pair<int, int>> positions;
    int start, start_val;

    scanf("%d", &len);
    positions.reserve(len);
    while(len--) {
      int dist, amount;

      scanf("%d %d", &dist, &amount);
      positions.push_back(std::make_pair(dist, amount));
    }
    std::sort(positions.begin(), positions.end());
    scanf("%d %d", &start, &start_val);
    printf("%d\n", solve(positions, start, start_val));
  }
}
