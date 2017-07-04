#include <queue>
#include <stdio.h>

//         TIME   QUEUE
int values[10010][10010];

int calculate(int start)
{
  std::priority_queue<int> vals; // Returns max seen till now
  int total = 0;
  for(; start > 0; start--) {
    for(int i = 1; i <= values[start][0]; i++) // Push all possible
      vals.push(values[start][i]);

    if(!vals.empty()) {
      total += vals.top();
      vals.pop();
    }
  }
  return total;
}

int main()
{
  int N;
  int max_time = 0;

  scanf("%d", &N);

  while(N--) {
    int value, time;

    scanf("%d %d", &value, &time);
    values[time][0] += 1;	// current size (used as index)
    values[time][values[time][0]] = value;

    if(max_time < time)
      max_time = time;
  }
  printf("%d\n", calculate(max_time));
}
