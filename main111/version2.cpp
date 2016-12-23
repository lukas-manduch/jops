#include <stdio.h>
#include <algorithm>
#include <cmath>
#define MAX_PRIME 300001 // Must be at least 2
#define VISIT 0
#define CONTAINS 1
#define IS_OK 2

char  numbers[MAX_PRIME];

void compute_sieve()
{
  numbers[0] = IS_OK;
  numbers[1] = IS_OK;
  for (unsigned int i = 2; i < MAX_PRIME; i++)
    numbers[i] = CONTAINS;
  for (unsigned int i = 2; i < MAX_PRIME; i++)
  {
    if (numbers[i] == IS_OK) continue;
    unsigned int j = i+i; // i * 2
    while (j<MAX_PRIME)
    {
      numbers[j] = VISIT;
      j += i;
    }
  }
}

inline int digits_count(unsigned int i)
{
  int ret = 1;
  while ( i/=10)
    ret++;
  return ret;
}


inline bool is_substring_prime(const unsigned int num)
{
  if (numbers[num] != VISIT)
    return numbers[num] == CONTAINS;
  int  dig_count = digits_count(num);
  int tens = 1;
  int fin;
  for ( int i = 1; i <= dig_count; i++)
  {
    fin = num / (tens*10);
    fin *= tens;
    fin += num % tens;
    tens *= 10;
    if (is_substring_prime(fin))
    {
      numbers[num] = CONTAINS;
      return true;
    }
  }
  numbers[num] = IS_OK;
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
      if (!is_substring_prime(a))
        output++;
    }
    printf("%d\n" , output);
  }

}
