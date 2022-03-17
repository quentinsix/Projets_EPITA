#include <err.h>
#include "vector.h"

//OK
struct vector *vector_new()
{
    struct vector *vector = (struct vector *)malloc(sizeof(struct vector));
    int *data=(int*)malloc(sizeof(int));
    if(vector==NULL||data==NULL)
    {
        errx(1,"Not enough memory!");
    }
    else
    {
        vector->capacity=1;
        vector->size=0;
        vector->data=data;
    }
}


//OK (je pense)
void vector_free(struct vector *v)
{
    free(v->data);
    free(v);
}


//OK
void double_capacity(struct vector *v)
{
    v->capacity*=2;
    v->data=(int*)realloc(v->data,v->capacity*sizeof(int));
    if(v->data==NULL)
    {
        errx(1,"Not enough memory!");
    }
}


//OK
void vector_push(struct vector *v, int x)
{
    if(v->size==v->capacity)
    {
        double_capacity(v);
    }
    v->data[v->size]=x;
    v->size+=1;
}


//OK
int vector_pop(struct vector *v, int *x)
{
    if (v->size==0)
    {
        return 0;
    }
    x[0]=v->data[v->size-1];
    v->size-=1;
    return 1;
}


//OK
int vector_get(struct vector *v, size_t i, int *x)
{
    if(v->size<i+1)
    {
        return 0;
    }
    x[0]=v->data[i];
    return 1;
}

//OK
void vector_insert(struct vector *v, size_t i, int x)
{
    size_t taille = v->size;
    if (i>0&&i<=taille)
    {
        if(taille==v->capacity)
        {
                double_capacity(v);
        }
        int tmp=v->data[i];
        size_t a=taille-1;
        while(a>i)
        {
            v->data[a+1]=v->data[a];
            a--;
        }
        v->data[i+1]=v->data[a];
        v->data[i]=x;
        v->size+=1;
    }

}

//OK
int vector_remove(struct vector *v, size_t i, int *x)
{
    size_t taille = v->size-1;
    if(i<0||i>taille)
    {
        return 0;
    }
    x[0]=v->data[i];
    for(size_t j=i;j<taille;j++)
    {
        v->data[j]=v->data[j+1];
    }
    v->size--;
    return 1;
}