#include <stdio.h>

int main()
{
  long long a, b;

  while(scanf("%lld %lld", &a, &b) != EOF && (a|b) != 0 ) {
    long long num, sum, num2;
    int carry = 0;


    num = a > b ? a : b;
    sum = a + b;
    num2 = sum - num;
    
    while(sum > 0) {
      if(sum%10 < num%10  || sum%10 == num%10 && num2%10)
	carry++;
      
      sum /=10;
      num /=10;
      num2 /= 10;
    }
    if(carry == 1)
      printf("%d carry operation.\n", carry);
    else if (carry)
      printf("%d carry operations.\n", carry);      
    else
      printf("No carry operation.\n");
  }
}
