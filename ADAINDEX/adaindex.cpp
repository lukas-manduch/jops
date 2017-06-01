#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define LETTERS 26

struct Node
{
  struct Node *node[LETTERS];
  int count[LETTERS];
};

/* Precondition: ptr cannot be NULL */
void insert(struct Node* ptr)
{
  int chr;

  chr = getchar();
  if(chr == '\n' || chr == EOF)
    return;
  if(ptr->node[chr - 'a'] == NULL) {
    ptr->node[chr-'a'] = (struct Node*)calloc(1, sizeof(struct Node));
  }
  ptr->count[chr-'a']++;
  insert(ptr->node[chr-'a']);
}

int get_count(struct Node* ptr)
{
  int chr;
  int ret;
  int thisc;

  if(!ptr) {
    while((chr= getchar()) != '\n')
      ;
    return 0;    
  }


  chr = getchar();
  if(chr == '\n' || chr == EOF)
    return -1;

  thisc = ptr->count[chr-'a'];

  ret = get_count(ptr->node[chr-'a']);

  if (ret== -1) // this is last one
    return thisc;

  return ret; // return something nice
}

int main()
{
  int words, queries;
  char c;
  struct Node nd;

  memset(&nd, 0, sizeof(struct Node));
  scanf("%d %d", &words, &queries);
  while((c = getchar()) != '\n')
    ;

  while(words--)
    insert(&nd);
  while(queries--)
    printf("%d\n", get_count(&nd));
  return 0;
}
