#include <stdbool.h>
#include <stdio.h>
#include <string.h>

bool isDelimiter(char ch)
{
    if (ch == ' ' || ch == '+' || ch == '-' || ch == '*' ||
            ch == '/' || ch == ',' || ch == ';' || ch == '>' ||
            ch == '<' || ch == '=' || ch == '(' || ch == ')' ||
            ch == '[' || ch == ']' || ch == '{' || ch == '}')
        return (true);
    return (false);
}

bool isOperator(char ch)
{
    if (ch == '+' || ch == '-' || ch == '*' ||
            ch == '/' || ch == '>' || ch == '<' ||
            ch == '=')
        return (true);
    return (false);
}

bool validIdentifier(char* str)
{
    if (str[0] == '0' || str[0] == '1' || str[0] == '2' ||
            str[0] == '3' || str[0] == '4' || str[0] == '5' ||
            str[0] == '6' || str[0] == '7' || str[0] == '8' ||
            str[0] == '9' || isDelimiter(str[0]) == true)
        return (false);
    return (true);
}

bool isKeyword(char* str)
{
    if (!strcmp(str, "if") || !strcmp(str, "else") ||
            !strcmp(str, "while") || !strcmp(str, "do") ||
            !strcmp(str, "break") ||
            !strcmp(str, "continue") || !strcmp(str, "int")
            || !strcmp(str, "double") || !strcmp(str, "float")
            || !strcmp(str, "return") || !strcmp(str, "char"))
        return (true);
    return (false);
}

bool isInteger(char* str)
{
    int i, len = strlen(str);

    if (len == 0)
        return (false);
    for (i = 0; i < len; i++)
    {
        if (str[i] != '0' && str[i] != '1' && str[i] != '2'
                && str[i] != '3' && str[i] != '4' && str[i] != '5'
                && str[i] != '6' && str[i] != '7' && str[i] != '8'
                && str[i] != '9' || (str[i] == '-' && i > 0))
            return (false);
    }
    return (true);
}

bool isRealNumber(char* str)
{
    int i, len = strlen(str);
    bool hasDecimal = false;

    if (len == 0)
        return (false);
    for (i = 0; i < len; i++)
    {
        if (str[i] != '0' && str[i] != '1' && str[i] != '2'
                && str[i] != '3' && str[i] != '4' && str[i] != '5'
                && str[i] != '6' && str[i] != '7' && str[i] != '8'
                && str[i] != '9' && str[i] != '.' ||
                (str[i] == '-' && i > 0))
            return (false);
        if (str[i] == '.')
            hasDecimal = true;
    }
    return (hasDecimal);
}

char* subString(char* str, int left, int right)
{
    int i;
    char* subStr = (char*)malloc(
                       sizeof(char) * (right - left + 2));

    for (i = left; i <= right; i++)
        subStr[i - left] = str[i];
    subStr[right - left + 1] = '\0';
    return (subStr);
}

void parse(char* str)
{
    int left = 0, right = 0;
    int len = strlen(str);

    while (right <= len && left <= right)
    {
        if (isDelimiter(str[right]) == false)
            right++;

        if (isDelimiter(str[right]) == true && left == right)
        {
            if (isOperator(str[right]) == true)
                printf("'%c' IS AN OPERATOR\n", str[right]);

            right++;
            left = right;
        }
        else if (isDelimiter(str[right]) == true && left != right
                 || (right == len && left != right))
        {
            char* subStr = subString(str, left, right - 1);

            if (isKeyword(subStr) == true)
                printf("'%s' IS A KEYWORD\n", subStr);

            else if (isInteger(subStr) == true)
                printf("'%s' IS AN INTEGER\n", subStr);

            else if (isRealNumber(subStr) == true)
                printf("'%s' IS A REAL NUMBER\n", subStr);

            else if (validIdentifier(subStr) == true
                     && isDelimiter(str[right - 1]) == false)
                printf("'%s' IS A VALID IDENTIFIER\n", subStr);

            else if (validIdentifier(subStr) == false
                     && isDelimiter(str[right - 1]) == false)
                printf("'%s' IS NOT A VALID IDENTIFIER\n", subStr);
            left = right;
        }
    }
    return;
}

int main()
{
    printf("Enter a string\n");
    char str[100];
    gets(str);

    parse(str);


    //whiteSpaceRemove
    whiteSpaceRemove(str);

    return(0);

}

//white space remove
void whiteSpaceRemove(char line[100])
{
    char space[100];
    int a = 0, b = 0;

    //printf("\nEnter a string for remove white space: \n");
    //gets(line);

    while (line[a] != '\0')
    {
        if (!(line[a] == ' ' && line[a+1] == ' '))
        {
            space[b] = line[a];
            b++;
        }
        a++;
    }

    space[b] = '\0';
    printf("\n\n String after removing white space\n%s\n", space);

    //comment
    FILE * findput;
    findput = fopen("text.txt", "w");
    fprintf(findput,space);
    fclose(findput);

    comment();
}

void check_comment (char) ;

FILE *fp , *fp2;

void comment()
{
    char c;
    fp = fopen ("text.txt","r") ;
    fp2 = fopen ("mynewfile.txt","w");

    while((c=fgetc(fp))!=EOF)
        check_comment(c);


    fclose(fp);
    fclose(fp2);
}

void check_comment(char c)
{
    char d;

    if( c == '/')
    {
        if((d=fgetc(fp))=='*')
         block_comment();

        else if( d == '/')
        {
          single_comment();

        }
        else
        {

            fputc(c,fp2);
            fputc(d,fp2);
        }
    }


    else
        fputc(c,fp2);
}


void block_comment()
{

 char d,e;

    while((d=fgetc(fp))!=EOF)
    {

        if(d=='*')
        {
            e=fgetc(fp);

            if(e=='/')
                return;
        }
   }

}


void single_comment()
{
 char d,e;

    while((d=fgetc(fp))!=EOF)
    {

        if(d=='\n')
            return;

    }

}


//





