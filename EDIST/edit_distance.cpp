#include <stdio.h>
#include <string.h>
#include <algorithm>

#define MAX 3000
int arr[MAX][MAX];

void da(int len1, int len2)
{
  for(int i = 0; i<= len2; i++) {
    for(int j = 0; j<= len1; j++) {
      printf("%d  ", arr[i][j]);
    }
    printf("\n");
  }
}

int solve(const char* str1, const char* str2, int len1, int len2)
{
  for(int i = 0; i<=std::max(len1,len2); i++) {
        arr[0][i] = i;
        arr[i][0] = i;
  }

  for(int i = 1; i <= len2; i++) {
    for(int j = 1; j <= len1; j++) {
            if(str1[j-1] == str2[i-1]) {
		arr[i][j] = arr[i-1][j-1];
       } else {
	      arr[i][j] = std::min({arr[i-1][j],
		    arr[i][j-1],
		    arr[i-1][j-1]})
		+ 1;
       }
    }
  }
  //da(len1, len2);
  return arr[len2][len1];
}

int main()
{
  int cases;

  scanf("%d", &cases);
  while(cases--) {
    char str1[MAX], str2[MAX];
    int len1, len2;
    int res;
      
    scanf("%s %s", str1, str2);
    len1 = strlen(str1);
    len2 = strlen(str2);
    res =  solve(str1, str2, len1, len2);
    printf("%d\n", res);
  }
  return 0;
}
