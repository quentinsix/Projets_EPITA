#include <stdlib.h>
#include "list.h"

//OK
void list_init(struct list *list)
{
    list->data = 0;
    list->next = NULL;
}

//OK
int list_is_empty(struct list *list)
{
    if (list->next==NULL)
        return 1;
    return 0;
}

//OK
size_t list_len(struct list *list)
{
    size_t n=0;
    while (list->next!=NULL)
    {
        list=list->next;
        n++;
    }
    return n;
}

//OK
void list_push_front(struct list *list, struct list *elm)
{
    elm->next=list->next;
    list->next=elm;
}

//OK
struct list *list_pop_front(struct list *list)
{
    if (list_is_empty(list)==1)
    {
        return NULL;
    }
    else
    {
        struct list *elm = list->next;
        list->next=elm->next;
        return elm;
    }

}

//OK
struct list *list_find(struct list *list, int value)
{
    if (list_is_empty(list)==1)
    {
        return NULL;
    }
    while(list!=NULL)
    {
        if(value==list->data)
        {
            return list;
        }
        list=list->next;
    }
    return NULL;
}


//OK 
struct list *list_lower_bound(struct list *list, int value)
{
    if (list_is_empty(list)==1)
    {
        return NULL;
    }
    struct list *dad= list;
    list=list->next;
    while(list!=NULL)
    {
        if (list->data>value)
        {
            return dad;
        }
        dad=list;
        list=list->next;
    }
    return dad;
}

//OK
int list_is_sorted(struct list *list)
{
    if (list_is_empty(list)==1 || list_len(list)==1)
    {
        return 1;
    }
    while(list->next!=NULL)
    {
        if(list->data>list->next->data)
        {
            return 0;
        }
        list=list->next;
    }
    return 1;
}

//OK
void list_insert(struct list *list, struct list *elm)
{
    if (list_is_empty(list)==1)
    {
        list_push_front(list,elm);
    }
    else
    {
        struct list *dad=list;
        list=list->next;
            int bo=0;
            while(list!=NULL && bo==0)
            {
                if(list->data>elm->data)
                {
                    bo=1;
                    dad->next=elm;
                    elm->next=list;
                }
                dad=list;
                list=list->next;
            }
            if (list==NULL && bo ==0)
            {
                dad->next=elm;
            }
    }
}


//OK
void list_rev(struct list *list)
{

        struct list *dad=NULL;
        struct list *curr=list->next;
        struct list *dernier=NULL;
        while(curr!=NULL)
        {
            dernier=curr->next;
            curr->next=dad;
            dad=curr;
            curr=dernier;
        }
        list->next=dad;

}


//OK
void list_half_split(struct list *list, struct list *second)
{
    size_t longeur = list_len(list);
    if(longeur>1)
    {
        struct list *elm=list->next;
        for(int i =0;i<(longeur+1)/2;i++)
        {
            elm=elm->next;
            list=list->next;
        }
        second->next=elm;
        list->next=NULL;
    }
}

