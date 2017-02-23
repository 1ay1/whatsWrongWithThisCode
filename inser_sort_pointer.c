#include <stdio.h>
#include <stdlib.h>

int numberOfChs(char *ch)
{
  char ch1 = 'A';
  int n = 0;
  while(1)
  {
    ch1 = *(ch + n);
    if(ch1 == '\0') break;
    n += 1;
  }
  return n;
}

void swap(char *ch, char *ch2)
{
  char *tempCh = malloc(sizeof(char));
  *tempCh = *ch2;
  *ch2 = *ch;
  *ch = *tempCh;
}

void inserSort(char *ch)
{
  int i = 0, j = 0; //counters
  for(i = 1; i < (numberOfChs(ch)); i++)
  {
    j = i;
    while (j>0 && (int) *(ch+j) < (int) *(ch + (j-1)))
    {
      swap((ch+j), (ch+(j-1)));
      if(j == numberOfChs(ch)) break;
      j= j-1;
    }
  }
}

int main()
{
  char *ch = malloc((sizeof(char) * 14));
  ch = "INSERTIONSORT";
  inserSort(ch);
  printf("%s\n", ch );
  return 0;
}
