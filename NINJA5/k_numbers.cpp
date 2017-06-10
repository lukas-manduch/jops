#include <stdio.h>
#include <algorithm>
#include <vector>

int main()
{
  int cases;

  scanf("%d", &cases);
  while(cases--) {
    int total;
    int nums;
    std::vector<int> arr;
    int ret = 0;

    scanf("%d %d", &total, &nums);
    arr.reserve(nums);

    while(nums--) {
      int tmp;
      
      scanf("%d", &tmp);
      arr.push_back(tmp);
    }
    arr.push_back(-1);
    arr.push_back(total + 2);
    
    std::sort(arr.begin(), arr.end());
    for(int i = 1; i<arr.size(); i++) {
      int diff;

      diff = arr[i] - arr[i-1] - 3;
      if(diff <= 0)
	continue;
      ret += diff/2 + diff%2;
    }
    
    printf("%d\n", ret + (int)arr.size() - 2);

    
  }
}
