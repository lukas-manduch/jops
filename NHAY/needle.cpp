#include <iostream>
#include <string>
#include <vector>


std::vector<int> construct_kmp(const std::string& lf)
{
  std::vector<int> pos;
  pos.push_back(0);
  unsigned int iter = 0;
  for(unsigned int i = 1; i < lf.size(); i++) {
    if(lf[iter] == lf[i]) {
      pos.push_back(++iter);
    } else {
      while(iter != 0) {
	iter = pos[iter-1];
	if (lf[i] == lf[iter]) {
	  iter++;
	  break;
	}
      }
      pos.push_back(iter);
    }
  }
  return pos;
}

int main()
{
  int needle_length;
  while(std::cin >> needle_length) {
    std::string lf;
    lf.reserve(needle_length);
    std::cin >> lf;
    auto kmp = construct_kmp(lf);

    char c;
    int iter = 0;
    int pos = 0; // position in haystack
    bool found = false; // Do we need empty line?

    while(std::cin.get(c) && c != '\n')
      ;

    while(std::cin.get(c) && c != '\n') {
      if(lf[iter] == c) {
	if(++iter == needle_length) {
	  std::cout << pos - needle_length + 1 << std::endl;
	  found = true;
	}
      } else {
	while(iter != 0) {
	  iter = kmp[iter - 1];
	  if(lf[iter] == c) {
	    iter++;
	    break;
	  }
	}
      }
      pos++;
    }
    if(!found)
      std::cout << std::endl;

  }
  return 0;
}
