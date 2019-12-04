#include <stdio.h>
// This code removes the comments from a file while moving the non-comments to another file.
FILE *fs, *ft;
int main ()
{
char source[67], target[67];
int c,d;
puts ("Enter C file name");
gets (source);
fs = fopen(source, "r");
if ( fs==NULL)
  {
   puts ("Can not open source file");
  }
puts ("Enter target name");
gets (target);
ft = fopen (target, "w");
if (ft == NULL)
{
  puts ("Can not open the target file");
}
while ( (c = getc(fs)) != EOF)
  {
    if ( c == '/')
      {
        if ( (d = getc(fs)) == '*')
        incomment();
        else
          {
             fprintf ( ft, "%c", c);
             fprintf ( ft, "%c", d);
          }
      }
    else
    fprintf(ft, "%c", c);
  }
  fclose (fs);
  fclose (ft);
