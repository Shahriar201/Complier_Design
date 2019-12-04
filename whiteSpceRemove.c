#include <stdio.h>

int main()
{
   char line[100], space[100];
   int a = 0, b = 0;

   printf("Enter a string: \n");
   gets(line);

   while (line[a] != '\0')
   {
      if (!(line[a] == ' ' && line[a+1] == ' ')) {
        space[b] = line[a];
        b++;
      }
      a++;
   }

   space[b] = '\0';

   printf("Text after removing blanks\n%s\n", space);

   return 0;
}
