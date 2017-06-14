#include <stdio.h>
#include <vector>
#include <algorithm>

// Precondition: vector is sorted
int solve(const std::vector<std::pair<int, int>>& act)
{
  int until = -1;
  int count = 0;

  for(auto p : act) {
    if(p.second < until)
      continue;
    count++;
    until = p.first;
  }
  return count;
}

int main()
{
  int cases;

  scanf("%d", &cases);
  while(cases--) {
    int len;
    std::vector<std::pair<int, int>> act;

    scanf("%d", &len);


    act.reserve(len);
    while(len--) {
      int start, end;

      scanf("%d %d", &start, &end);
      act.push_back(std::make_pair(end, start));
    }
    std::sort(act.begin(), act.end());
    printf("%d\n", solve(act));

  }
}
