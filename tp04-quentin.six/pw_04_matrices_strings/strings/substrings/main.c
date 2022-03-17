#include <stdlib.h>
#include <stdio.h>
#include <err.h>

//returns lenght of word s
size_t Length_Word(char s[])
{
    size_t i;
    for( i=0;s[i]!='\0';i++);
    return i;
}

//the program that print the "^" under the letter if second string
//is contained by the first string
void main_program(char S1[],char S2[],size_t size1,size_t size2)
{
    size_t i=0;
    size_t a=0;
    while ( i<size1 && a<size2)
    {
        if(S1[i]==S2[a])
        {
            
            a++;
        }
        else
        {
            a=0;
        }
        i++;
    }
    if(a==size2)
    {
    printf("%s\n",S1);
    for (size_t j=0;j<i-size2;j++)
    {
        printf(" ");
    }
    printf("^\n");
    }
    else
    {
        printf("Not Found!\n");
    }
}

int main(int argc, char** argv){
	if (argc != 3)
	{
		errx(1,"Usage: str1 str2");
	}

	char* S1 = argv[1];
	char* S2 = argv[2];
    main_program(S1,S2,Length_Word(S1),Length_Word(S2));
    return 0;
}
