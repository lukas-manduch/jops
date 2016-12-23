#include <stdio.h>
#include <vector>
#include <algorithm>

bool try_with(int cows, int min_distance, const std::vector<int>& positions)
{
  int i =1;
  int cows_fits = 1;
  int current_distance = 0;
  int last_val = positions[0];

  while (i < positions.size())
  {
    current_distance += positions[i] - last_val;
    last_val = positions[i];
    if (current_distance >= min_distance)
    {
      current_distance = 0;
      cows_fits++;
    }
    i++;
  }
  return cows_fits >= cows;
}
int my_binary_search(const int cows, int bot, int top,
    const std::vector<int>& positions)
{
  if (bot == top)
    return try_with(cows, bot , positions) ? bot : 0;
  int mid = ( bot + top ) / 2;
  bool my_res = try_with ( cows, mid, positions);
  if (my_res) // it is this or even something above
  {
    int my_res2 = my_binary_search(cows, mid + 1, top, positions);
    if (my_res2)
      return my_res2;
    return mid;
  }
  else 
    return my_binary_search(cows, bot , mid - 1, positions);

}
int get_largest_shortest(const int cows, const std::vector<int>& positions)
{
  int best = positions[positions.size()-1]/cows;
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

