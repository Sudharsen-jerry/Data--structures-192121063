#include <stdio.h>
int main()
{
  int array[100], c,b, n;
  printf("Enter number of elements in array:");
  scanf("%d", &n);
  printf("enter array elements\n");
  for (c = 0; c < n; c++)
  {
    scanf("%d", &array[c]);
  }
  for (c = 0; c <n; c++)
  {
  	for(b=0;b<c;b++)
    if (array[c] == array[b])  
    {
      printf("duplicate element:%d\n", array[c]);
    }
    else
    {
    	printf("duplicates not found\n");
	}
  }
  return 0;
}
