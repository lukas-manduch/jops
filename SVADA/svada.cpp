#include <stdio.h>
#include <vector>

//#define DEBUG
#define INT long long

std::vector<std::pair<INT, INT>> load()
{
  std::vector<std::pair<INT, INT>> ret;
  INT cases;
  INT first, second;

  scanf("%lld", &cases);
  ret.reserve(cases);
  while(cases--) {
    scanf("%lld %lld", &first, &second);
    ret.push_back(std::make_pair(first, second));
  }
  return ret;
}

INT get_count(const std::vector<std::pair<INT, INT>>& pairs, INT time)
{
  INT total = 0;

  for(auto p : pairs) {
    INT tmp_time = time;

    tmp_time -= p.first;
    if(tmp_time >= 0) {
      total++;
      total += tmp_time / p.second;
    }
  }
  return total;
}


int main()
{
  INT interval;

  scanf("%lld", &interval);
  auto vec1 = load();
  auto vec2 = load();


  INT low = 1;
  INT high = interval;
  INT prob = 0;

  // Binary search
  while(true) {
    INT one, two;
    INT mid = (low + high) / 2;

    if(low > high) {
      printf("%lld\n", prob);
      return 0;
    }

    #ifdef DEBUG
    printf("DEBUG TRYING %lld\n", mid);
    #endif

    one = get_count(vec1, mid);
    two = get_count(vec2, interval - mid);

    #ifdef DEBUG
    printf("DEBUG ONE %lld\nDEBUG TWO %lld\n", one, two);
    #endif

    if(one == two) {
      printf("%lld\n", mid);
      return 0;
    }

    if(one < two) {
      prob = mid;
      low = mid + 1;
    }
    else {
      high = mid - 1;
    }

  }
}
