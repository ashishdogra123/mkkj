#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
void arr_alloc (int x, int y, int(**aptr)[x][y])
{
  *aptr = malloc( sizeof(int[x][y]) ); // allocate a true 2D array
  assert(*aptr != NULL);
}
void arr_fill (int x, int y, int array[x][y])
{
    int i,j;
    for(i=0; i<x; i++)
    {
        for(j=0; j<y; j++)
        {
            array[i][j] = j + 1;
        }
    }
}
void arr_print (int x, int y, int array[x][y])
{
    int i,j;
  for(i=0; i<x; i++)
  {
    for(j=0; j<y; j++)
    {
      printf("%d ", array[i][j]);
    }
    printf("\n");
  }
}
int main (void)
{
  int x = 2;
  int y = 3;
  int (*aptr)[x][y];
  printf("%d\n",aptr);
  arr_alloc(x, y, &aptr);
  arr_fill(x, y, *aptr);
  arr_print(x, y, *aptr);
  printf("%d\n",aptr);
  printf("%d\n",&aptr);
  printf("%d\n",***aptr);
  free(aptr); // free the whole 2D array

  return 0;
}
