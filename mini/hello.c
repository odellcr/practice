#include <stdio.h>

int main(int argc, char *argv[])
{
  int i = 0;
  int arr[10];

  for(i = 0; i < 10; i ++)
  {
	arr[i] = i;
	printf("i:%d\n",i);
  }

  printf("hello, world\n");

  return 0;
}
