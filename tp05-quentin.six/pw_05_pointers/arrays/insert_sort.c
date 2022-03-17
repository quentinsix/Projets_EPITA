#include "insert_sort.h"

// Insertion using the plain algorithm.
void array_insert(int *begin, int *end, int x)
{
    //comprend pas à quoi sert cette fct (essayé des trucs mais 
    //ça marchait pas)
    *end=x;
    while (begin!=end)
    {
        if(*begin>*(begin+1))
        {
            swap(begin,begin+1);    
        }
        begin++;
    }
        
}

// Insertion using the binary-search algorithm.
void array_insert_bin(int *begin, int *end, int x)
{
    //algo facilement trouvé sur internet si jamais soupçon de triche
    int *mid=NULL;
    int *right=end;
    while(begin<=right)
    {
        mid=begin+((right-begin)/2);
        if(*mid==x)
        {
            break;
        }
        else if (*mid<x)
        {
            begin=mid+1;
        }
        else
        {
            right=mid-1;
            
        }
    }
    if(*mid<x)
    {
        mid++;
    }
    int *m =end;
    while(m>mid)
    {
        *m=*(m-1);
        m--;
    }
    *mid=x;
    
}

//comprend pas à quoi sert la fct array_is_sorted
//et comprend pas comment on est censé lire les valeurs affichés sur la console
void array_insert_sort(int *begin, int *end)
{
    //comme dit plus haut essayé mais pas reussi
    // for (int *p=begin;p<end;p++)
    // {
    //     array_insert(begin,p+1,*p);
    // }


    //Le code juste en dessous marche aussi (en une seule fct)
    int *ptr=begin;
    while(ptr!=end-1)
    {
        if(*ptr>*(ptr+1))
        {
            swap(ptr,ptr+1);
            ptr=begin;
        }
        else
        {
            ptr++;
        }
    }
}


void array_insert_sort_bin(int *begin, int *end)
{

    for (int *p=begin+1;p<end;p++)
    {
        array_insert_bin(begin,p,*p);
    }
    
}