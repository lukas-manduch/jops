#include <stdio.h>
#include <algorithm>
#define MAX_PRIME 100001 // Must be at least 2

bool numbers[MAX_PRIME];

void compute_sieve()
{
  numbers[0] = false;
  numbers[1] = false;
  for (unsigned int i = 2; i < MAX_PRIME; i++)
    numbers[i] = true;
  for (unsigned int i = 2; i < MAX_PRIME; i++)
  {
    if (!numbers[i]) continue;
    unsigned int j = i+i; // i * 2
    while (j<MAX_PRIME)
    {
      numbers[j] = false;
      j += i;
    }
  }
}

inline bool is_subsequence_prime(unsigned int num, unsigned int mask)
{
  //printf("Trying %d with mask %d " , num , mask);
  unsigned int out = 0;
  unsigned int ten_pow = 1;
  while ( num && mask )
  {
    if ( mask % 2)
    {
      out += (num % 10) * ten_pow;
      ten_pow *= 10;
    }
    num /= 10;
    mask >>= 1;
  }
  //printf(" res is %d \n" , numbers[out]);
  return numbers[out];
}

inline int digits_count(unsigned int i)
{
  int ret = 1;
  while ( i/=10)
    ret++;
  return ret;
}

inline bool is_subsequence_prime(unsigned int num)
{
  int digits = digits_count(num);
  unsigned int max_mask = 0;
  while (digits--)
  {
    max_mask <<= 1;
    max_mask += 1;
  }
  //printf( " %d has max mask %d\n", num , max_mask);

for (int out_mask =0; out_mask <= max_mask; )
{
  out_mask <<=1;
  out_mask +=1;
  for (int mask = out_mask; mask <= max_mask; mask<<= 1)
  {
    if (is_subsequence_prime(num,mask))
        return true;
  }

}
/*
  for (int mask = 1; mask <= max_mask; mask++)
  {
    if (is_subsequence_prime(num,mask))
        return true;
  }
*/
  return false;
}

int main()
{
  compute_sieve();
  unsigned int cases, a , b;
  scanf("%d" , &cases);
  for ( unsigned int case_ =0; case_ < cases; case_++)
  {
    unsigned int output = 0;
    scanf("%d %d" , &a , &b );
    if (a > b) std::swap(a , b);
    for ( ; a <= b; a++)
    {
      if (!is_subsequence_prime(a))
        output++;
    }
    printf("%d\n" , output);
  }

}
