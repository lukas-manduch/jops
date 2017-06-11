#include <stdio.h>
#include <vector>
#include <algorithm>
#include <map>

#define OUT 1
#define INC 0
#define INT long long int

void da(std::vector<INT> a)
{
  for(INT i = 0; i < a.size(); i++)
    printf("%3lld ", i);
  printf("\n");
  for(auto i : a)
    printf("%3lld ", i);
  printf("\n\n");
  fflush(stdout);
}

void update_cache(std::vector<INT>& tree, std::vector<INT>& cache,
		  INT tfrom, INT tto, INT current)
{
  INT mid;
  //  printf("update cache %d - %d on %d\n", tfrom, tto, current);
  if(cache[current] != 0 && tfrom < tto) {
    INT total = tto - tfrom + 1;

    // We must propagate to lower layers
    mid = (tfrom + tto) / 2;
    INT left =  (cache[current] / total) * (mid - tfrom + 1);
    INT right = (cache[current] / total) * (tto - (mid+1) + 1);
    // Solve left
    cache[current*2 + 1] += left;
    tree[current*2 + 1] += left;
    // Solve right
    cache[current*2 + 2] += right;
    tree[current*2 + 2] += right;
  }
  //  da(tree);
  //  da(cache);

  cache[current] = 0;		// Cache is resolved
}

void increase(std::vector<INT>& tree, std::vector<INT>& cache,
	      INT qfrom, INT qto,
	      INT tfrom, INT tto,
	      INT current, INT sum)
{
  INT mid;

  if(qfrom > qto)
    return;

  update_cache(tree, cache, tfrom, tto, current);

  

  tree[current] += (qto - qfrom + 1) * sum;

  if(qfrom == tfrom && qto == tto) {
    cache[current] = (qto - qfrom + 1) * sum;
    return;
  }

  //  da(tree);
  //  da(cache);
  //    printf("Increase tree %d - %d query %d - %d sum %d\n",
  //	 tfrom, tto, qfrom, qto, sum);

  mid = (tfrom + tto) / 2;

  if(qfrom <= mid) {		// We must go to left
    increase(tree, cache, qfrom, std::min(mid,qto),
	     tfrom, mid, current*2 + 1, sum);
  }
  if(qto > mid) {		// Go right
    increase(tree, cache, std::max(mid+1, qfrom), qto,
	     mid+1, tto, current*2 + 2, sum);
  }
}

INT count( std::vector<INT>& tree, std::vector<INT>& cache,
	  INT qfrom, INT qto,
	  INT tfrom, INT tto, INT current)
{
  INT mid;
  INT sum = 0;

  if(qfrom > qto)
    return 0;

  update_cache(tree, cache, tfrom, tto, current);
  
  if(qfrom == tfrom && qto == tto) {
    return tree[current];
  }
  mid = (tfrom + tto) / 2;


  if(qfrom <= mid) {		// We must go to left
    sum += count(tree, cache,
		 qfrom, std::min(mid,qto),
		 tfrom, mid, current*2 + 1);
  }
  
  if(qto > mid) {
    sum += count(tree, cache,
		 std::max(mid+1, qfrom), qto,
		 mid+1, tto, current*2 + 2);
  }
  return sum;
}

int  main()
{
  INT cases;
  scanf("%lld", &cases);
  while(cases--) {
    INT queries_count, len;
    std::vector<INT> stree, cache;


    scanf("%lld %lld ", &len, &queries_count);
    len++;
    stree.resize(len*4);
    cache.resize(len*4);

    while(queries_count--) {
      INT from_, to_, type;

      scanf("%lld", &type);
      scanf("%lld %lld", &from_, &to_);
      if(type == INC) {
	INT sum;

	scanf("%lld", &sum);
	increase(stree, cache, from_, to_, 0, len-1, 0, sum);
      }
      else { // type == OUT
	printf("%lld\n", count(stree, cache, from_, to_, 0, len -1, 0));
      }
    }
  }

  return 0;
}
