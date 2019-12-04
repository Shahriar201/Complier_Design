#include<stdio.h>
int main()
{
    char ar[100];
    int i;
    printf("Enter a string for encode and then decode\n");
    scanf("%s", ar);
    for( i = 0; ar[i] != '\0'; ++i)
    {
        ar[i] = ar[i] + 1;
    }

    printf("Encode a program : %s \n", ar);

    for( i = 0; ar[i] != '\0'; ++i)
    {
        ar[i] = ar[i] - 1;
    }

    printf("Decode a program : %s \n", ar);


    return 0;
}
