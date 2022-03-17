#include <err.h>
#include <string.h>

#include "htab.h"

#include <stdio.h>
#include <string.h>

//pour test
void print_hash(struct htab *ht)
{
	for(size_t i =0;i<ht->capacity;i++)
	{
		printf("0%ld",i);
		struct pair *tmp=ht->data[i].next;
		while(tmp!=NULL)
		{
			printf(" -> (0x%08x,%s,%p)",tmp->hkey,tmp->key,tmp->value);
			tmp=tmp->next;
		}
		printf("\n");
	}
}



//OK
uint32_t hash(char *key)
{
	char *mot=key;
	size_t length=0;
	while (*mot!='\0')
	{
	    length++;
	    mot++;
	}
	size_t i =0;
	uint32_t hash = 0;
	while (i != length) 
	{
	   hash += key[i++];
	   hash += hash << 10;
	   hash ^= hash >> 6;
	}
	hash += hash << 3;
	hash ^= hash >> 11;
	hash += hash << 15;
	// printf("0x%08x\n",hash );
	return hash;
}

//OK
struct htab *htab_new()
{
    struct htab *htab=(struct htab *)malloc(sizeof(struct htab));

    struct pair *pair=(struct pair *)calloc(4,sizeof(struct pair));

    if(htab==NULL||pair==NULL)
    {
    	errx(1,"Not enough memory!");
    }
    else
    {
    	htab->capacity=4;
    	htab->size=0;
    	htab->data=pair;
    }
}

//OK
void htab_clear(struct htab *ht)
{
	int i=0;
	for(size_t i=0;i<ht->capacity;i++)
	{
		struct pair *next=ht->data[i].next;
		struct pair *curr=next;
		ht->data[i].next=NULL;
		while (curr!=NULL)
		{
			next=curr->next;
			free(curr);
			curr=next;
		}
	}
    ht->size=0;
}

//OK
void htab_free(struct htab *ht)
{
    htab_clear(ht);
    free(ht->data);
    free(ht);
}

//à tester
struct pair *htab_get(struct htab *ht, char *key)
{
	uint32_t hashedkey=hash(key);
	uint32_t i = hashedkey%(uint32_t)ht->capacity;
    struct pair *curr=ht->data[i].next;
    while(curr!=NULL)
    {
	    if(curr->hkey==hashedkey)
	    {
	    	return curr;
	    }
	    curr=curr->next;
    }
    
    return NULL;
}


//OK normalement
int htab_insert(struct htab *ht, char *key, void *value)
{
	uint32_t cle = hash(key);
	uint32_t i=cle%(uint32_t)ht->capacity;
	struct pair *newpair=(struct pair *)malloc(sizeof(struct pair));
	if(newpair==NULL)
	{
		errx(1,"Not enough memory!");
	}
	else
	{
		newpair->hkey=cle;
		newpair->key=key;
		newpair->value=value;
		newpair->next=NULL;
	}
	if(ht->data[i].next==NULL)
	{
		ht->size++;
		ht->data[i].next=newpair;
	}
	else
	{
		struct pair *curr=ht->data[i].next;
		while(curr!=NULL)
		{
			if(curr->hkey==cle)
			{
				return 0;
			}
			curr=curr->next;
		}
		struct pair *tmp=ht->data[i].next;
		ht->data[i].next=newpair;
		newpair->next=tmp;
	}
    if((ht->size*100)/ht->capacity>75)
    {
    	ht->capacity*=2;
    	ht->size=0;
    	ht->data=(struct pair *)realloc(ht->data,ht->capacity*sizeof(struct pair));
    	for(size_t i=0;i<ht->capacity/2;i++)
    	{
    		struct pair *tmp=ht->data[i].next;
    		ht->data[i].next=NULL;
    		while(tmp!=NULL)
    		{
    			struct pair *curr=tmp->next;
    			tmp->next=NULL;
    			htab_insert(ht,tmp->key,tmp->value);
    			free(tmp);
    			tmp=curr;
    		} 
    	}
    }
    return 1;
}


//OK normalement
void htab_remove(struct htab *ht, char *key)
{
	uint32_t cle=hash(key);
	uint32_t i=cle%(uint32_t)ht->capacity;
	struct pair *dad=&ht->data[i];
	struct pair *tmp=ht->data[i].next;
	while(tmp!=NULL && tmp->hkey!=cle)
	{
		dad=tmp;
		tmp=tmp->next;
	}
	if(tmp!=NULL)
	{
		dad->next=tmp->next;
		free(tmp);
	}
	if(ht->data[i].next==NULL)
	{
		ht->size--;
	}
}


int main()
{

	struct htab *newht=htab_new();

	// htab_insert(newht,"France","Paris");
	// htab_insert(newht,"Spain","Madrid");
	// htab_insert(newht,"Jamaica","Kingston");
	// htab_insert(newht,"Cuba","Havana");
	// htab_insert(newht,"Iraq","Bagdad");
	// htab_insert(newht,"Iraq","Bagdad");
	// print_hash(newht);
	// htab_insert(newht,"Turkey","Ankara");
	// printf("\n");
	// print_hash(newht);
	// printf("\n");
	// printf("%s\n",htab_get(newht,"France")->key);
	// htab_remove(newht,"Spain");
	// htab_remove(newht,"Turkey");
	// htab_remove(newht,"Ira");
	// print_hash(newht);

	// printf("\n");

	// printf("%ld %ld\n",newht->size,newht->capacity);
	htab_clear(newht);
	// htab_free(newht);
	return 0;
}
