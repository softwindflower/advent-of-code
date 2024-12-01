#include <stdlib.h>
#include <stdio.h>
#include <string.h>


int comp(const void *a, const void *b);
int calculate(int l1[], int l2[]);

int main()
{

  int list1[1000];
  int list2[1000];
  char line[20];
  char* p;
  int i = 0;
  FILE *fd = fopen("input.txt", "r");

  // Parse through file and tokenize
  for (i = 0; i < 1000; i++) 
  {
    fgets(line, sizeof(line), fd);
    p = strtok(line, " \t");
    if (p != NULL) 
    {
      int t1 = atoi(p);
      list1[i] = t1;
      p = strtok(NULL, " \t");

      if (p != NULL) 
      {
        int t2 = atoi(p);
        list2[i] = t2;
      }

    }
  }

  qsort(list1, 1000, sizeof(list1[0]), comp);
  qsort(list2, 1000, sizeof(list2[0]), comp);

  int done = calculate(list1, list2);
  printf("%d\n", done);

  fclose(fd);

  return 0;
}

int calculate(int l1[], int l2[])
{
  int final = 0;
  for (int i = 0; i < 1000; i++)
  {

    int result = l1[i] - l2[i];
    int count = abs(result);

    final += count;
  }

  return final;
}

int comp(const void *a, const void *b) 
{
    return (*(int *)a - *(int *)b);
}