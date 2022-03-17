#include "evalexpr.h"
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[])
{
    char rpn[] = "-rpn";
    char buf[100];
    char str1[200];
    fgets(buf, 100, stdin);
    if (IsStrCorrect(buf) == 1)
        return 1;
    if (buf[0] == '\n')
        return 0;
    if (argc == 1)
    {
        //si y a des erreurs de parenthese mais check pas le reste
        if (NormalToRPN(buf, str1)[0] == 'A')
            return 2;
        //printf("%s\n", NormalToRPN(buf, str1));
        return RPN(NormalToRPN(buf, str1));
    }
    else if (argc == 2)
    {
        if (strcmp(argv[1], rpn))
            return 4;
        if (buf[0] != '\n')
            return RPN(buf);
    }
    if (argc > 2)
        return 4; 
    return 0;
}
