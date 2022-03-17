#include "stack.h"

#include <stddef.h>
#include <stdlib.h>

struct stack *stack_push(struct stack *s, int e)
{
    if (s == NULL)
    {
        struct stack *head = malloc(sizeof(struct stack));
        head->data = e;
        head->next = NULL;
        return head;
    }
    else
    {
        struct stack *head = malloc(sizeof(struct stack));
        head->data = e;
        head->next = s;
        return head;
    }
}

struct stack *stack_pop(struct stack *s)
{
    if (s == NULL)
        return NULL;
    struct stack *head = s;
    s = s->next;
    free(head);
    return s;
}

int stack_peek(struct stack *s)
{
    return s->data;
}
