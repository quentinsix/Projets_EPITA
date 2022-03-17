#include "evalexpr.h"
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int Appartient(char c)
{
  char s[] = "()0123456789+-*/%^ \n";
  for (int i = 0; i < 20; i++)
  {
    if (s[i] == c)
      return 0;
  }
  return 1;
}

int IsStrCorrect(char *str)
{
  int i = 0;
  while (str[i] != '\0')
  {
    if (Appartient(str[i]) == 1)
      return 1;
    i++;
  }
  return 0;
}

//==============================

//convertit un string normal en string rpn pour la RPN fonction
char *NormalToRPN(char *str, char *str1)
{
    struct heap *h = create_heap(100);
    int i = 0, iS = 0, twoNumb = 0;
    while (str[i] != '\n' && str[i] != '\0')
    {
        //printf("%c",str[i]);
        int Chiffre = 0;
        while (str[i] <= '9' && str[i] >= '0' && str[i] != '\0')
        {
            //printf("%c", str[i]);
            Chiffre = 1;
            str1[iS++] = str[i];
            i++;
        }
        //printf(" ");
        if (Chiffre == 1)
        {
            twoNumb++;
            str1[iS++] = ' ';
        }
        if (twoNumb == 2)
        {
            str1[iS++] = h->array[h->size - 1];
            str1[iS++] = ' ';
            pop(h);
            twoNumb = 0;
        }
        if (str[i] == ')')
        {
            while (h->array[h->size - 1] != '(' && h->size - 1 > 0)
            {
                str1[iS] = h->array[h->size - 1];
                iS++;
                pop(h);
            }
            if (h->array[h->size - 1] == '(')
                pop(h);
            else
                return "Afsd";
            //erreur à gérer pour si le ')' n'existe pas dans la heap
        }
        if (str[i] == '(')
            add(h, str[i]);
        // A CHANGER NORMALEMENT sauf si grosse flemme sa mere
        if (str[i] == '+' || str[i] == '-' || str[i] == '*' || str[i] == '/')
            add(h, str[i]);
        if (str[i] == '%' || str[i] == '^')
            add(h, str[i]);
        //str [i] == tous les autres trucs
        i++;
    }
    while (h->size != 0)
    {
        str1[iS++] = h->array[h->size - 1];
        str1[iS++] = ' ';
        pop(h);
    }
    delete_heap(h);
    return str1;
}

// vraie fonction
int RPN(char *buf)
{
    int i = 0;
    struct heap *v = create_heap(100);
    while (buf[i] != '\0')
    {
        //printf("%c",buf[i]);
        // truc à gerer pour les num plus long que un digit !!
        int total = 0, isChiffre = 0;
        while (buf[i] <= '9' && buf[i] >= '0')
        {
            isChiffre = 1;
            total *= 10;
            total += buf[i] - 48;
            i++;
        }
        if (isChiffre == 1)
            i--;
        //printf("%d %d\n" , total,i);
        switch (buf[i])
        {
            case ' ':
                break;
            case '+':
                add_vector(v);
                break;
            case '-': 
                sub_vector(v);
                break;
            case '*':
                mult_vector(v);
                break;
            case '^':
                pow_vector(v);
                break;
            case '/':
                if (v->array[v->size - 1] == 0)
                    return 3;
                div_vector(v);
                break;
            case '%':
                if (v->array[v->size - 1] == 0)
                    return 3;
                rest_vector(v);
                break;
            default:
                add(v, total);
                break;
        }
        //print_heap(v);
        i++;
    }
    i = v->array[0];
    delete_heap(v);
    if(buf[0] != '\0' || buf[0] != '\n')
        printf("%d\n", i);
    return 0;
}

/*
int main(int argc, char *argv[])
{
    char str[100];
    char str1[100];
    //NormalToRPN("100 -10+1\n",str);
    printf("%s\n", NormalToRPN("100 -10+1\n",str));
    //printf("%s\n", NormalToRPN("110 - 1",str1));
    RPN(NormalToRPN("100 - 10 + 1\n",str1));
    //RPN("110 1-");
}
*/
/*
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
        printf("%s\n", NormalToRPN(buf, str1));
        RPN(NormalToRPN(buf, str1));
    }
    else if (argc == 2)
    {
        int a = 0;
        while (argv[1][a] != '\0' && rpn[a] != '\0')
        {
            if (argv[1][a] != rpn[a])
                return 4;
            a++;
        }
        if (argv[1][a] != rpn[a])
            return 4;
        if (buf[0] != '\n')
            RPN(buf);
    }
    return 0;
}
*/
