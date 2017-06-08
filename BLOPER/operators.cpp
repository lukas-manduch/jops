#include <stdio.h>
#include <vector>
#include <cstdlib>

#define PLUS 0
#define MINUS 1

// Precondition - array must be zeroed
// Precondition2 - num must be > 0
bool solve(std::vector<int>& nums, int num)
{
  int len;
  int sum;

  len = nums.size() -1;
  sum = (len+1)*(len/2);
  if(len%2 == 1)
    sum += len/2 + 1;

  sum -= num;
  if(sum%2 || sum < 0)
    return false;

  sum = sum/2;
  while(true) {
    if(sum == 0)
      return true;
    if(len == 0)
      return false;
    if(sum == 1)
      return false;
    if(len >= sum) {
      nums[sum] = MINUS;
      sum = 0;
      return true;
    }
    if((len+1) == sum)
      len--;
    
    sum -= len;
    nums[len--] = MINUS;
    

  }
  return true;
}

bool solve_minus(std::vector<int>& nums, int num)
{
  int len;
  int sum;

  len = nums.size() -1;
  sum = (len+1)*(len/2);
  if(len%2 == 1)
    sum += len/2 + 1;

  sum -= num;
  if(sum%2 || sum < 0)
    return false;

  sum = sum/2;
  while(true) {
    if(sum == 0)
      return true;
    if(len == 0)
      return false;
    if(sum == 1)
      return false;
    if(len >= sum) {
      nums[sum] = MINUS;
      sum = 0;
      return true;
    }
    if((len+1) == sum)
      len--;
    
    sum -= len;
    nums[len--] = MINUS;
    

  }
  return true;
}

int main()
{
  int len, num;

  while(scanf("%d %d",&len, &num) != EOF) {
    std::vector<int> arr;
    bool ret;
    bool positive;

    positive = true;//num > 0;
    arr.resize(len+1);		// Ignore zero index
    ret = solve(arr, (num));
    if(!ret) {
      printf("Impossible\n");
      continue;
    }
    for(int i = 1; i < arr.size(); i++) {
      if(positive) {
	if(arr[i] == MINUS)
	  printf("-");
	else if (i!=1)
	  printf("+");
      } else {
	if(arr[i] == MINUS && i!=1)
	  printf("+");
	else
	  printf("-");
	    
      }
      printf("%d", i);
    }
    printf("\n");
  }

}
