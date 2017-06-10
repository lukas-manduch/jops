#include <stdio.h>
#include <algorithm>

int get_first(int a, int count)
{
  //  printf("get first %d %d\n", a ,count);
  int multiply = 0;
  while(count > 0) {
    int tmp = ++multiply;
    
    count--;
    while(!(tmp%a)) {
      tmp /= a;
      count--;
    }
  }
  //  printf("RET %d\n", multiply);
  return multiply * a;
}

// Returns first i! which is divisible by a
int find(int a)
{
  int high = 0;
  //printf("find %d\n", a);
  for(int i = 2; i*i <= a; i++) {
    //printf("%d\n", i);
    if(!(a%i)) { // We found a denominator
      int count = 0;
      
      while(!(a%i)) {
	a /= i;
	count++;
      }
      //      printf("max from %d and:  ", high);
      high = std::max(high, get_first(i, count));
    }
  }

  return std::max(high, a);	// Maybe a is prime
}

int main()
{
  int a,b;

  scanf("%d %d", &a, &b);
  a = find(a);
  b = find(b);
  if(a < b)
    printf("%d\n", b - a);
  else
    printf("0\n");
  return 0;
}
