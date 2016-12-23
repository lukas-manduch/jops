#include <stdio.h>
#include <vector>
#include <algorithm>

bool try_with(int cows, int min_distance, const std::vector<int>& positions)
{
  int i =1;
  int cows_fits = 1;
  int last_val = positions[0];

  while (i < positions.size())
  {
    if ((positions[i] - last_val) >= min_distance)
    {
      if(++cows_fits == cows)
        return true;
      last_val = positions[i];
    }
    i++;
  }
  return false;
}
int my_binary_search(const int cows, int bot, int top,
    const std::vector<int>& positions)
{
  int mid;
  while (top - bot > 1)
  {
    mid = (top+bot) >> 1;
    (try_with(cows, mid, positions) ? bot : top) = mid;

  }
  return bot;
}
int get_largest_shortest(const int cows, const std::vector<int>& positions)
{
  int best = positions[positions.size()-1]/cows + 1;
  int worst = 1;
  return my_binary_search(cows, worst, best, positions);
}

int main()
{
  int test_cases;
  scanf("%d", &test_cases);
  while(test_cases--)
  {
    int cows, num_positions;
    scanf("%d %d", &num_positions, &cows);
    std::vector<int> positions;
    positions.reserve(num_positions);
    while(num_positions--)
    {
      int val;
      scanf("%d", &val);
      positions.push_back(val);
    }
    std::sort(positions.begin(), positions.end());
    printf("%d\n", get_largest_shortest(cows, positions));
  }
  
}
