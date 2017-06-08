#include <stdio.h>
#include <vector>
#include <algorithm>
#include <map>

void da(std::vector<int> a)
{
  for(auto i : a)
    printf("%2d ", i);
  printf("\n");
  for(int i = 0; i < a.size(); i++)
    printf("%2d ", i);
  printf("\n");
  fflush(stdout);
}


void increase(std::vector<int>& tree, int qfrom, int qto,
	      int tfrom, int tto, int current)
{
  int mid;
  if(qfrom == tfrom && qto == tto) {
    tree[current] += 1;
    return;
  }
  mid = (tfrom + tto) / 2;
  
  if(qfrom > qto)
    return;
  
  if(qfrom <= mid) {		// We must go to left
    increase(tree, qfrom, std::min(mid,qto), tfrom, mid, current*2 + 1);
  }
  if(qto > mid) {
    increase(tree, std::max(mid+1, qfrom), qto, mid+1, tto, current*2 + 2);
  }
}

int count(const std::vector<int>& tree, int num,
	  int tfrom, int tto, int current)
{
  int mid;
  if(tto == tfrom)
    return tree[current];
  mid = (tfrom + tto) / 2;
  if(num <= mid)
    return count(tree, num, tfrom, mid, current*2 +1) + tree[current];
  if(num > mid)
    return count(tree, num, mid+1, tto, current*2 + 2) + tree[current];
}

int main()
{
  int rains_count, queries_count, len;
  std::vector<int> stree;


  scanf("%d %d %d", &rains_count, &queries_count, &len);
  stree.resize(len*4);

  while(rains_count--) {
    int from_, to_;

    scanf("%d %d", &from_, &to_);
    increase(stree, from_, to_, 0, len-1, 0);
    //    printf("From: %d To: %d\n", from_, to_);
    //da(stree);
  }



  while(queries_count--) {
    int q;
    int res = 0;

    scanf("%d", &q);
    res = count(stree, q, 0, len-1, 0);
    printf("%d\n", res);
  }
  return 0;
}
