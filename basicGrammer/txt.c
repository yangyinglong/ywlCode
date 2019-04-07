#include<stdio.h>
#include<string.h>

int main()
{
  int i, len;
  int s = 0;
  char a[80];
  char b;
  gets(a);
  scanf("%c", &b);
  len = strlen(a);
  for(i = 0; i <= len; i ++)
  {
    if(a[i] == b)
    {
      s ++;
    }
  }
  
  printf("%d\n", s);
  return 0;
}