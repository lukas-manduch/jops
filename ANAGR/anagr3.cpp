#include <cassert>
#include <iostream>
#include <vector>
#include <cstring>
#include <cmath>
#include <string>
#include <algorithm>

#define YES 1
#define NO  2
#define PALI 3

std::vector<int> get_map(const std::string& str)
{
  std::vector<int> occ; occ.resize('z'); // Occurences
  for(char c : str) {
    c = tolower(c);
    if(isalpha(c))
      occ[c-'a']++;
  }
  return occ;
}

std::vector<int> diff_maps(const std::vector<int>& map1,
			   const std::vector<int>& map2)
{
  std::vector<int> diff_vec;
  diff_vec.resize(map1.size());
  assert(map1.size() == map2.size());
  for(unsigned int i = 0; i < map1.size(); i++) {
    diff_vec[i] = map1[i] - map2[i];
  }
  return diff_vec;
}

int check(const std::vector<int>& diff)
{
  int state = 0;
  int odd = 0;
  for(int i : diff) {
    
    if(i%2 == 1) // check parity
      odd++;
    // Check sizes of strings
    if(i > 0) {
      if(state < 0)
	return NO;
      state = i;
    } else if ( i < 0) {
      if (state > 0)
	return NO;
      state = i;
    }
  }
  if(state == 0)
    return YES;
  if(odd > 1)
    return NO;
  return PALI; // Everything is ideal for creation of palindrome
}

std::string make_pali(std::vector<int> diff)
{
  std::string res;
  char extra = 0;
  for(unsigned int i = 0; i < diff.size(); i++) {
    int count = abs(diff[i]);
    if (count%2 == 1)
      extra = i + 'a';
    res += std::string(count/2, i+'a');
  }
  
  std::string rev = res;
  std::reverse(rev.begin(), rev.end());
  
  if (extra)
    return res + extra + rev;
  return res + rev;
}


int main()
{
  int cases; char c;
  std::cin >> cases;
  c = std::cin.get();
  for(int i = 0; i < cases; i++) {
    std::string str1, str2;
    std::getline(std::cin, str1);
    std::getline(std::cin, str2);
    auto vec_map1 = get_map(str1);
    auto vec_map2 = get_map(str2);
    auto diff_map = diff_maps(vec_map1, vec_map2);
    int status = check(diff_map);
    if(status == YES)
      std::cout << "YES" << std::endl;
    else if (status == NO)
      std::cout << "NO LUCK" << std::endl;
    else // pali
      std::cout << make_pali(diff_map) << std::endl;
    
  }
}
