#include <iostream>
#include <vector>

int main()
{
  int cases;

  std::cin >> cases;
  while(cases--) {
    int rows;
    std::vector<std::pair<int,int>> circles;
    int max = 0;
    int max_index = -1;
    bool good = true;

    std::cin >> rows;
    while(rows--) {
      int one, two;

      std::cin >> one >> two;
      if(one > max) {
	max = one;
	max_index = circles.size();
      }
      circles.push_back({one, two});
    }
    for(int i = 0; i < circles.size(); i++) {
      if(circles[i].second >= max && i != max_index) {
	good = false;
	break; // no point in continuing
      }
    }
    if(good)
      std::cout << max_index + 1 << std::endl;
    else
      std::cout << -1 << std::endl;
  }
  
}
