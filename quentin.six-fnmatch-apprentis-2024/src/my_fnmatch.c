#include "my_fnmatch.h"

#include <stddef.h>
#include <stdlib.h>

// pour un char va parcourir une lite de int et regarder si il en fait partit
int CharIsEqual(int *tab, char c)
{
    if (tab[(int)c] == 1)
        return 0;
    return -1;
}

int *CharPossibleIfN(int *tab)
{
    if (tab[(int)('!')] == 1)
        tab[(int)('!')] = 0;
    for (int i = 0; i < 128; i++)
    {
        if (tab[i] == 0)
            tab[i] = 1;
        else
            tab[i] = 0;
    }
    return tab;
}

// return un tableau de int des char possibles
int *CharPossible(const char *str, int *tab, int D, int F)
{
    int z = D;
    D++;
    char a;
    while (D < F)
    {
        if (str[D + 1] == '-' && str[D + 2] != ']')
        {
            a = str[D];
            while (a <= str[D + 2])
            {
                tab[(int)a] = 1;
                a++;
            }
            D += 3;
        }
        else
        {
            tab[(int)str[D]] = 1;
            D++;
        }
    }
    if (str[z + 1] == '!' && z + 2 != F)
        tab = CharPossibleIfN(tab);
    return tab;
}

// return la position du dernier ] ou -1 si pas dans le cas de [...]
int isRange(const char *str, int index)
{
    int i = index + 1;
    index++;
    while (str[index])
    {
        if (str[index] == ']' && index != i)
            return index;
        index++;
    }
    return -1;
}

// c est le char apres l'étoile (marche pas bien mais trkl)
int Etoile(char c, const char *string, int iS)
{
    while (string[iS] != c)
    {
        iS++;
    }
    if (string[iS] != c)
        return -1;
    return iS - 1;
}

// fct principale avec un switch chacal tu connais
int my_fnmatch(const char *pattern, const char *string)
{
    int indexString = 0, i = 0, index = 0;
    while (pattern[i] && string[indexString])
    {
        int tabl[128] = { 0 };
        switch (pattern[i])
        {
        case '[':
            index = isRange(pattern, i);
            if (index != -1)
            {
                CharPossible(pattern, tabl, i, index);
                if (tabl[(int)string[indexString]] == 0)
                    return 1;
                i = index;
            }
            break;
        case '?':
            break;
        case '*':
            while (pattern[i] == '*')
                i++;
            indexString = Etoile(pattern[i + 1], string, indexString);
            if (indexString == -1)
                return 1;
            break;
        case '\\':
            if (pattern[++i] != string[indexString])
                return 1;
            break;
        default:
            if (pattern[i] != string[indexString])
                return 1;
            break;
        }
        i++;
        indexString++;
    }
    if (pattern[i] != '\0' || string[indexString] != '\0')
        return 1;
    return 0;
}
