#include <bits/stdc++.h>
#include <vector>
using namespace std;
typedef long long int ll;

 
// Find all possible sum of elements of a[] and store
// in x[]
void calcsubarray(ll a[], ll x[], int n, int c)
{
    for (int i=0; i<(1<<n); i++)
    {
        ll s = 0;
        for (int j=0; j<n; j++)
	  if (i & (1<<j)) {
                s += a[j+c];

	  }
        x[i] = s;
    }
}

void calcsubarray(ll a[], std::vector<std::pair<long long, int>>& x, int n, int c)
{
    for (int i=0; i<(1<<n); i++)
    {
        ll s = 0;
        for (int j=0; j<n; j++)
	  if (i & (1<<j)) {
                s += a[j+c];
		x[i].second += 1;
	  }
        x[i].first = s;
    }
}

 
// Returns the maximum possible sum less or equal to S
ll solveSubsetSum(ll a[], int n, ll S)
{
  //  std::vector<long long> Y;
  std::vector<std::pair<long long, int>> X, Y;

 
    int size_X = 1<<(n/2);
    int size_Y = 1<<(n-n/2);

    X.resize(size_X + 2);
    Y.resize(size_Y + 2);  

    
    calcsubarray(a, X, n/2, 0);
    calcsubarray(a, Y, n-n/2, n/2);


    sort(&Y[0], &Y[size_Y]);
 

    for (int i=0; i<size_X; i++)
    {
        if (X[i].first <= S)
        {
	  int p = lower_bound(&Y[0], &Y[0]+size_Y, std::make_pair(S-X[i].first, 0)) - &Y[0];
	    //printf("%lld\n", Y[p]); 
            if (p == size_Y || Y[p].first != (S-X[i].first))
	      continue;

	    if (( X[i].second + Y[p].second) != n/2)
	      continue;
	    return 1;
 
        }
    }
    return 0;
}
 

int main()
{
  int cases;
  scanf("%d", &cases);
  for(long long i =1; i <= cases; i++) {
    int len;
    std::vector<long long> in;
    long long sum = 0;

    scanf("%d", &len);
    in.reserve(len);
    
    while(len--) {
      long long num;

      scanf("%lld", &num);
      sum += num;
      in.push_back(num);
    }
    int y = (sum%2 || in.size()%2 ) ? 0 :
      solveSubsetSum(&in[0], in.size(), sum/2);
    //printf("%d %lu \n",y, in.size()/2);
    printf("Case %lld: ", i);
    if(y)
      printf("Yes\n");
    else
      printf("No\n");
  }
    return 0;
}
