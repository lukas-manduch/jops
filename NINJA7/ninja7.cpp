#include <stdio.h>
#include <vector>
#include <algorithm>

// returns max difference between second values
int get_max_diff(const std::vector<std::pair<int, int>>& a)
{
  int max = -1111111;
  int min =  1111111;
  int diff = 0;
  
  for(const auto& p : a) {
    if(min > p.second) {
      min = p.second;
      max = p.second;
    }
    if(max < p.second) {
      max = p.second;
      diff = std::max(diff, max - min);
    }
    //printf("{%d, %d}\n", p.first, p.second);
  }
  return diff;
}

// Precondition: both have same length
std::vector<std::pair<int, int>> make_diff(const std::vector<int>& a,
					   const std::vector<int>& b)
{
  std::vector<std::pair<int, int>> res;

  res.reserve(a.size());
  for(int i = 0; i < a.size(); i++) {
    res.push_back(std::make_pair(a[i] - b[i], i));
  }
  return res;
}

std::vector<int> load_prefix_sum(int count)
{
  std::vector<int> a;
  int sum = 0;

  a.reserve(count + 1);
  a.push_back(0);
  while(count--) {
    int tmp;

    scanf("%d", &tmp);
    sum += tmp;
    a.push_back(sum);
  }
  return a;
}



int main()
{
  int cases;

  scanf("%d", &cases);
  while(cases--) {
    int len;
    std::vector<int> a, b;
    std::vector<std::pair<int,int>> diff;

    scanf("%d", &len);
    a = load_prefix_sum(len);
    b = load_prefix_sum(len);
    diff = make_diff(a, b);
    std::sort(diff.begin(), diff.end());
    printf("%d\n", get_max_diff(diff));
    
  }
  return 0;
}
