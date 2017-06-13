#include <stdio.h>
#include <cmath>

inline int count_factors(int num)
{

  int mult = 1;
  
  for(int i = 2; i*i <= num; i++) {
    if(num%i == 0) {
      int count = 0;
      
      while(num%i == 0) {
	num /=i;
	count++;
      }
	mult *= count + 1;
    }
  }

  if (num == 1)
    return mult;
  return mult*2;
}


int main()
{
  int cases;

  scanf("%d", &cases);
  while(cases--) {
    double num;

    scanf("%lf", &num);
    //num = count_factors(num);

    //printf("%d\n", num);
    //if(num%2)
    //  printf("YES\n");
    //else
    //  printf("NO\n");
    if (std::sqrt(num) == std::floor(std::sqrt(num)))
      printf("YES\n");
    else
      printf("NO\n");
  }
}
