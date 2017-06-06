#include <vector>
#include <algorithm>
#include <iostream>
//#include <stdio.h>




// Returns diff in buildings regions
// i.e. if region was created or destroyed
// if building is true it means its sinked
inline int sink_building(std::vector<bool>& blds, int index)
{
  bool left_ok = true;
  bool right_ok = true;

  if(index-1 < 0 || blds[index-1])
    left_ok = false;
  if(index+1 >= blds.size() || blds[index+1])
    right_ok = false;
  blds[index] = true;

  if(left_ok && right_ok)
    return 1; 			// One created
  if(!left_ok && !right_ok)
    return -1;			// One destroyed
  return 0;			// One widened
}

struct Request
{
  int value;  // Sort by this
  int position;
};

struct Building
{
  int height;
  int index;
};

int main()
{
  int cases;

  std::cin >> cases;
  //scanf("%d", &cases);
  while(cases--) {
    std::vector<int> mins;
    std::vector<int> maxs;
    int bld_count, req_count;

    mins.reserve(100000);
    maxs.reserve(100000);

    //scanf("%d %d", &bld_count, &req_count);
    std::cin >> bld_count >> req_count;


    int h = 0;
    bool raising = true;
    for(int i=0; i<bld_count; i++){
      int hl;
      
      std::cin >> hl;
      //scanf("%d", &hl);
      if(hl > h && !raising) { 	// one before was min
	mins.push_back(h);
	raising = true;
      }
      if(hl < h && raising) {	// One before was max
	raising = false;
	maxs.push_back(h);
      }
      h = hl;
    }
    if(raising)
      maxs.push_back(h);
    
    std::sort(mins.begin(), mins.end());
    std::sort(maxs.begin(), maxs.end());
 
    int current_max = 0;	// Index 
    int current_min = 0;	// Index 
    
    for(int i = 0; i < req_count; i++) {
      int req;
      
      std::cin >> req;
      //scanf("%d", &req);
      while(maxs.size() > current_max &&
	    maxs[current_max] <= req) { 
	current_max++;
      }
      while(mins.size() > current_min &&
	    mins[current_min] <= req)
	current_min++;

      std::cout <<   1 + current_min - current_max << std::endl;
      //printf("%d ",  1 + current_min - current_max);
    }
    std::cout << std::endl;
    //printf("\n");
  }
  return 0;
}
