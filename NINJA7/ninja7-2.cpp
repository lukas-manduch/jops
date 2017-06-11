#include <stdio.h>
#include <vector>
#include <algorithm>


// Precondition: both have same length
std::vector<int> make_diff(const std::vector<int>& a,
			   const std::vector<int>& b,
			   int& out_sum)
{
  std::vector<int> res;
  int sum = 0;

  res.reserve(a.size());
  for(int i = 0; i < a.size(); i++) {
    res.push_back(a[i] - b[i]);
    sum += a[i] - b[i];
  }
  out_sum = sum;
  return res;
}

std::vector<int> load_arr(int count)
{
  std::vector<int> a;
  int sum = 0;

  a.reserve(count);
  while(count--) {
    int tmp;

    scanf("%d", &tmp);
    a.push_back(tmp);
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
    std::vector<int> diff;
    int sum;
    int i;

    scanf("%d", &len);
    a = load_arr(len);
    b = load_arr(len);
    diff = make_diff(a, b, sum);
    std::sort(diff.begin(), diff.end());
    for(i = 0; i < diff.size(); i++) {
      if(sum>=0)
	break;
      sum -= diff[i];
    }

    printf("%d\n", (int)diff.size() - i);

  }
  return 0;
}
