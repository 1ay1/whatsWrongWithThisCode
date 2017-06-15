#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void sort_string(char *s)
{
   int c, d = 0, length;
   char *pointer, *result, ch;
 
   length = strlen(s);
 
   result = (char*)malloc(length+1);
 
   pointer = s;
 
   for ( ch = 'a' ; ch <= 'z' ; ch++ )
   {
      for ( c = 0 ; c < length ; c++ )
      {
         if ( *pointer == ch )
         {
            *(result+d) = *pointer;
            d++;
         }
         pointer++;
      }
      pointer = s;
   }
   *(result+d) = '\0';
 
   strcpy(s, result);
   free(result);
}

int fact(int n)
{
    if (n >= 1)
        return n*fact(n-1);
    else
        return 1;
}

int main()
{
  printf("Enter string: ");
  char s[1000];
  scanf("%s", s);
  sort_string(s);
  int num=0;
  int slen = strlen(s);
  char ch = s[0];
  char ch1;
  int i1 = 0;
  while(ch != '\0')
    {
      if(ch != s[i1 +1]) num++;
      i1++;
      ch = s[i1];
    }
  int repeat[num];
  for(int i = 0; i<num; i++)
    {
      repeat[i] = 0;
      ch = s[i];
      ch1= s[i];
      i1 =0;
      while(ch1 == ch)
	{
	  repeat[i]++;
	  i1++;
	  ch1 = s[i + i1];
	}
    }

  float res=0;
  float fr;
  for(int i = 0; i < num; i ++)
    {
      fr = fact(slen-1);
      for(int j = 0 ; j < num; j++)
	{
	  if(i == j)
	    {
	      fr = fr/(fact(repeat[j-1]));
	    }
	  else
	    {
	      fr = fr/fact(j);
	    }
	  res = res + fr;
	}
    }      
  printf("%d\n", (int)  res);
  return 0;
}
      
