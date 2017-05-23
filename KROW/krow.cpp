/*
KROW - K-In-A-Row
no tags

Hansel and Gretel do not listen to their teacher at school. Instead
they secretly play a game called K-In-A-Row. One day in the evening
they started to argue who had won more games that day. They collected
all the papers they had used for playing the game and they started to
count how many times each of them had won. But it was very tedious and
they were sleepy. Help them to count how many games each of them had
won.

K-In-A-Row is played in a square grid with M times N squares. Two
players alternate in their moves. A player chooses an empty square and
fills in his/her sign (Hansel uses cross 'x' and Gretel uses circle
'o'). The game is won by the player who first places at least K
his/her own signs in a row (either horizontally, vertically or in one
of the two diagonal directions). The game stops immediately after one
of the players completes K of his/her signs in a row; thus it may
never happen that both players have completed K of their signs in a
row. If no player creates such a row, nobody wins.
Input file specification

The first line contains the number of games L. It is followed by L
blocks, each describing one game. Each block starts with a line
containing 3 numbers M, N and K. Numbers M and N give the size of the
grid (M,N<200) and K is the length of the required row. The following
N lines each containing M characters describe the situation after the
end of the game. Character '.' denotes an empty field, characters 'x'
and 'o' denote fields marked by Hansel and Gretel respectively. You
may assume that the input is correct.
Output file specification

The output file consists of two numbers separated by a colon ':'. The
first number denotes the number of the games won by Hansel, the second
one gives the number of the games won by Gretel.
Example

Input file:
2
3 3 3
.x.
.xo
oox
4 7 4
....
..x.
ooox
oxx.
oox.
o.ox
..xx

Output file:
0:1

*/

#include <iostream>
#include <stdlib.h>
#define MAX 300


struct Position
{
  int one_left, one_right, one_top;
  int two_left, two_right, two_top;
};

int solve(char desk[][MAX], int width, int height, int win_size)
{
  Position *pos;
  int ret = 0;
  int i, j;

  pos = (Position*)calloc(MAX*MAX + 4*MAX, sizeof(Position));



  for(i=0; i<height; i++) {
    char last = 0;
    int total = 0;
    Position *curr, *prev;
    curr = pos + i * (MAX) + MAX;
    prev = pos + i * (MAX); // Now I don't need to check zero l.


    // At first, check if something is not in line
    for(j=0; j<width; j++) {
      if(desk[i][j] == last) {
	if(++total == win_size && last != '.') {
	  if(last == 'x')
	    ret = 1;
	  else
	    ret = -1;
	  goto cleanup;
	}
      } else {
	total  = 1;
	last = desk[i][j];
      }
    }

    // Now check columns and diagonals
    for(j=0; j<width; j++) {
      if(desk[i][j] == 'x') {
	curr[j].one_top = prev[j].one_top + 1;
	if(curr[j].one_top == win_size) {
	  ret = 1;
	  goto cleanup;
	}
	if(j!=0)
	  curr[j].one_left = prev[j-1].one_left + 1;
	else
	  curr[j].one_left = 1;
	if(curr[j].one_left == win_size) {
	  ret = 1;
	  goto cleanup;
	}


	if(j != width -1)
	  curr[j].one_right = prev[j+1].one_right + 1;
	else
	  curr[j].one_right = 1;
	if(curr[j].one_right == win_size) {
	  ret = 1;
	  goto cleanup;
	}

      }
      /////////////////////////////////////////////
      else if (desk[i][j] == 'o') {
	curr[j].two_top = prev[j].two_top + 1;
	if(curr[j].two_top == win_size) {
	  ret = -1;
	  goto cleanup;
	}
	if(j!=0)
	  curr[j].two_left = prev[j-1].two_left + 1;
	else
	  curr[j].two_left = 1;

	if(curr[j].two_left == win_size) {
	  ret = -1;
	  goto cleanup;
	}

	if(j != width -1)
	  curr[j].two_right = prev[j+1].two_right + 1;
	else
	  curr[j].two_right = 1;

	if(curr[j].two_right == win_size) {
	  ret = -1;
	  goto cleanup;
	}
      }
    }
  }

 cleanup:
  if(pos)
    free(pos);
  return ret;
}


int main()
{
  int games;
  int i;
  int first = 0, second = 0;

  std::cin >> games;

  for(i=0; i<games; i++) {
    int width, height, win;
    int j, k;
    char desk[MAX][MAX];
    int ret;

    std::cin >> width >> height >> win;
    for(j=0; j<height; j++) {
      for(k=0; k<width; k++) {
	std::cin >> desk[j][k];
      }
    }

    ret = solve(desk, width, height, win);
    if(ret == 1)
      second++;
    else if (ret==-1)
      first++;
  }
  printf("%d:%d\n", second, first);
  return 0;
}
