#include<stdio.h>
int main()
{
    char str1[100], str2[100], str3[100];
    int length=0, i, j;
    printf("username : ");
    gets(str1);

    printf("password : ");
    gets(str2);

    if(length >= 8)
    {
        for(i = 0; str2[i] != '\0'; i++)
        {
            if(str2[i]> 'A' && str2[i]< 'Z')
            {
                if(str2[i]> 'a' && str2[i]< 'z')
                {
                    if(str2[i]>0 && str2[i]<9)
                    {
                        strcpy(str2, "str2[i]");
                        printf("%s\n", str2);
                    }
                }
            }

        }

        //gets(str2);
        //printf("password %s\n", str2);
    }

    return 0;
}
