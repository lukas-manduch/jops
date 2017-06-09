#include <vector>
#include <stdio.h>
#include <algorithm>

int main()
{
  int len;
  int dummy;
  std::vector<std::pair<int, int>> ys;
  int max = -1;
  int ret = 0;
  int last_x = -1;

  scanf("%d", &len);
  ys.reserve(len);
  while(len--) {
    int x,y ;

    scanf("%d %d", &x, &y);
    ys.push_back(std::make_pair(x,y));
  }
  for(int i = ys.size()-1; i >= 0; i--) {
    if(ys[i].first == last_x) {
      if(ys[i].second > max)
	max = ys[i].second;
      continue;
    }

    if(ys[i].second > max) {
      max = ys[i].second;
      ret++;
      last_x = ys[i].first;
    }
  }
  printf("%d\n", ret);
  return 0;
}
