#include<stdio.h>
int main()
{
    //Concatinate string
    char str1[100], str2[100];

    printf("Enter first string : ");
    gets(str1);

    printf("Enter second string : ");
    gets(str2);

    strcat(str1, str2);

    printf("Concatenate : %s\n", str1);


    //reverse a program
    char arr[100];

    printf("Enter a string to reverse : ");
    gets(arr);

    strrev(arr);

    printf("Reverse of the string is : %s\n", arr);

    return 0;


    return 0;
}
