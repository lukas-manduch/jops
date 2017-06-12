#include <stdio.h>
#include <cctype>
#include <vector>
#define MAX 3000000
char word[MAX];

std::vector<std::pair<int, int>> get_map()
{
  std::vector<std::pair<int, int>> mp;
  const char *ptr = word;
  int index = 1;
  
  mp.resize(30);		// I need only 26 A-Z
  while(*ptr) {
    mp[(*ptr) - 'A'].second = index;
    if(mp[(*ptr) - 'A'].first == 0)
      mp[(*ptr) - 'A'].first = index;
    index++;
    ptr++;
  }
  return mp;
}

int main()
{
  scanf("%s", word);
  auto vec = get_map();

  int cases;
  scanf("%d", &cases);

  while(cases--) {
    char a, b;

    while(true) {
      a = getchar();
      if(std::isalpha(a))
	break;
    }
    while(true) {
      b = getchar();
      if(std::isalpha(b))
	break;
    }


    if(vec[a-'A'].first < vec[b - 'A'].second &&
       vec[a - 'A'].first != 0 )
      printf("YA\n");
    else
      printf("TIDAK\n");
  }
  return 0;
}
