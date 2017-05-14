#include <map>
#include <stdio.h>

#define LF 47

int main()
{
  int cases;
  

  scanf("%d", &cases);
  for(int j = 0; j < cases; j++) {
    int len; // Length of current line
    int sum = 0; // sum of numbers
    int output = 0; // result
    std::map<int, int> &case_map = *(new std::map<int, int>);


    case_map[0] = 1;
    scanf("%d", &len);
    for ( int i = 0; i < len; i++) {
      int val; // current number
      int look_for; // look for this in map
 
      scanf("%d", &val);
      sum += val;
      look_for = sum - LF;
    
      output += case_map[look_for];
      // Insert current value to map
	case_map[sum] += 1;
    }
    printf("%d\n", output);
  }
}
