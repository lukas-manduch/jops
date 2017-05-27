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

std::string load_haystack(int n)
{
  std::string ret;
  int current;
  int previous = 0; // IDK

  ret.reserve(n);
  
  for(int i = 0; i < n; i++) {
    std::cin >> current;
    if(current > previous)
      ret += 'G';
    else if (current < previous)
      ret += 'L';
    else
      ret += 'E';
    previous = current;
  }
  return ret;
}


int main()
{
  int cases;
  std::cin >> cases;
  while(cases--) {
    std::string haystack;
    std::string lf;
    int haystack_len;

    std::cin >> haystack_len;
    haystack = load_haystack(haystack_len);
    
    std::cin >> lf;

    auto kmp = construct_kmp(lf);

    int iter = 0;
    
    bool found = false; // Do we need empty line?
    
    for(int i = 0; i < haystack.size(); i++) {
      if(lf[iter] == haystack[i]) {
	if(++iter == lf.size()) {
	  found = true;
	  break; // Break haystack cycle, we are finished
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
    if(found)
      std::cout << "YES" << std::endl;
    else
      std::cout << "NO" << std::endl;
  }
  return 0;
}
