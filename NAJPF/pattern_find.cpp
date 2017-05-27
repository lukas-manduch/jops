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
  int cases;
  std::cin >> cases;
  while(cases--) {
    std::string haystack;
    std::string lf;

    std::cin >> haystack;
    std::cin >> lf;
    auto kmp = construct_kmp(lf);

    int iter = 0;
    //int pos = 0; // position in haystack
    int found = 0; // Do we need empty line?
    std::vector<int> positions;

    
    for(int i = 0; i < haystack.size(); i++) {
      if(lf[iter] == haystack[i]) {
	if(++iter == lf.size()) {
	  positions.push_back(i - lf.size() + 2);
	  found++;
	  iter = kmp[iter - 1];
	}
      } else {
	while(iter != 0) {
	  iter = kmp[iter - 1];
	  if(lf[iter] == haystack[i]) {
	    iter++;
	    break;
	  }
	}
      }
    }
    if(positions.empty())
      std::cout << "Not Found" << std::endl;
    else {
      std::cout << positions.size() << std::endl;
      bool space = false;
      for(int j : positions) {
        if (space)
          std::cout << " " << j;
	else {
          std::cout << j;
	  space = true;
	}
      }
      std::cout << std::endl;
    }
    if(cases)
      std::cout << std::endl;
  }
  return 0;
}
