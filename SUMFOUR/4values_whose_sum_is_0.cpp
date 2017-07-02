#include <stdio.h>
#include <vector>
#include <algorithm>

//#define DEBUG

#ifdef DEBUG
void da(std::vector<int> a)
{
  for(int i = 0; i < a.size(); i++)
    printf("%3d|", i );
  printf("\n");
  for(auto au : a)
    printf("%3d|" , au);
  printf("\n");
}
#endif

// Precondition: Sorted vectors
int get_count(const std::vector<int>& a, const std::vector<int>& b)
{
#ifdef DEBUG
  da(a);
  printf("\n");
  da(b);
#endif
  int ia = 0;
  int ib = b.size() - 1;
  int total = 0;

  while(ia != a.size()) {
    int sum = a[ia] + b[ib];
    int tmp_ib = -1;

    while(sum >= 0 && ib >= 0) { // Move ib
      if(sum == 0) {
	total++;
	#ifdef DEBUG
	printf("Found pair, indexes %d %d\n", ia, ib);
	#endif
	if(tmp_ib == -1) // Save position for case when next a is same as current
	  tmp_ib = ib;
      }
      ib--;
      sum = a[ia] + b[ib];
    }

    if(tmp_ib != -1)
      ib = tmp_ib;
    ia++;
  }

  return total;
}

int main()
{
  std::vector<int> v[4];
  std::vector<int> sums[2];
  int length;

  scanf("%d", &length);
  for(auto &a : v)
    a.reserve(length);
  sums[0].reserve(length*length + 100);
  sums[1].reserve(length*length + 100);

  // Load
  while(length--) {
    int a,b,c,d;

    scanf("%d %d %d %d", &a, &b, &c, &d);
    v[0].push_back(a);
    v[1].push_back(b);
    v[2].push_back(c);
    v[3].push_back(d);
  }

  // Merge
  for(auto i : v[0]) {
    for(auto j : v[1]) {
      sums[0].push_back(i + j);
    }
  }

  for(auto i : v[2]) {
    for(auto j : v[3]) {
      sums[1].push_back(i + j);
    }
  }

  std::sort(sums[0].begin(), sums[0].end());
  std::sort(sums[1].begin(), sums[1].end());

  printf("%d\n", get_count(sums[0], sums[1]));
  return 0;
}
