#include "mix.h"

char separator[] = " ,;:!?./%*$=+)@_-('&1234567890\"\r\n";

size_t Length_Word(char s[])
{
    size_t i;
    for(i=0;s[i]!='\0';i++);
    return i;
}


//returns 0 if char is a separator, 1 otherwise
int Is_Separator(char c)
{
    for (size_t i=0;i<Length_Word(separator);i++)
    {
        if(c==separator[i])
        {
            return 0;
        }
    }
    return 1;
}


//The main program
void mix(char s[])
{
    printf("%s\n",s);
    size_t size=Length_Word(s);
    printf("%c",s[0]);
    int a=1;
    while(a<size)
    {
        //every possible condition not to swap the letters
        if(Is_Separator(s[a-1])==0||Is_Separator(s[a])==0||s[a+1]=='\0'||\
            Is_Separator(s[a+1])==0||s[a+2]=='\0'||Is_Separator(s[a+2])==0)
        {
            printf("%c",s[a] );
            a++;
        }
        else
        {
            printf("%c%c",s[a+1],s[a]);
            a=a+2;
        }
    }
    printf("\n");
}
