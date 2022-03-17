#include "variant.h"

#include <stdbool.h>
#include <stdio.h>
#include <string.h>
void variant_display(const struct variant *e)
{
    if (e->type == TYPE_INT)
        printf("%d\n", e->value.int_v);
    if (e->type == TYPE_FLOAT)
        printf("%f\n", e->value.float_v);
    if (e->type == TYPE_CHAR)
        printf("%c\n", e->value.char_v);
    if (e->type == TYPE_STRING)
        printf("%s\n", e->value.str_v);
}
/*
bool variant_equal(const struct variant *left, const struct variant *right)
{
    if (left.type == right.type)
    {
        if (left.type == TYPE_INT && left.value.int_v == right.value.int_v)
                return true;
        if (left.type == TYPE_FLOAT && left.value.float_v ==
right.value.float_v) return true; if (left.type == TYPE_CHAR &&
left.value.char_v == right.value.char_v) return true; if (left.type ==
TYPE_STRING)
        {
            int i = 0;
            while (left.value.str_v[i] && right.value.str_v[i])
            {
                if (left.value.str_v[i] != right.value.str_v[i])
                    return false;
                i++;
            }
            if (left.value.str_v[i] == right.value.str_v[i])
                return true;
        }
    }
    return false;
}
*/

bool variant_equal(const struct variant *left, const struct variant *right)
{
    if (left->type == right->type)
    {
        // int i = 0, j = 0;
        switch (left->type)
        {
        case TYPE_INT:
            if (left->value.int_v == right->value.int_v)
                return true;
            break;
        case TYPE_FLOAT:
            if (left->value.float_v == right->value.float_v)
                return true;
            break;
        case TYPE_CHAR:
            if (left->value.char_v == right->value.char_v)
                return true;
            break;
        default:
            if ((left->value.str_v == NULL && right->value.str_v != NULL)
                || (left->value.str_v != NULL && right->value.str_v == NULL))
                return true;
            if (left->value.str_v == NULL && right->value.str_v == NULL)
                return false;
            if (strcmp(left->value.str_v, right->value.str_v) == 0)
                return true;
            return false;
            break;
        }
    }
    return false;
}

/*
            while (left->value.str_v[i] != '\0'
                   && right->value.str_v[j] != '\0')
            {
                if (left->value.str_v[i] != right->value.str_v[j])
                    return false;
                i++;
                j++;
            }
            return (left->value.str_v[i] == right->value.str_v[j]);
            */

int variant_find(const struct variant *array, size_t len, enum type type,
                 union type_any value)
{
    const struct variant variant = { .type = type, .value = value };
    const struct variant *ptrvariant = &variant;
    size_t i = 0;
    for (; i < len; i++)
    {
        if (variant_equal(ptrvariant, &array[i]) == true)
            return i;
    }
    return -1;
}

float variant_sum(const struct variant *array, size_t len)
{
    float sum = 0;
    for (size_t i = 0; i < len; i++)
    {
        const struct variant *variant = &array[i];
        if (variant->type == TYPE_INT)
            sum += variant->value.int_v;
        else if (variant->type == TYPE_FLOAT)
            sum += variant->value.float_v;
        /*
        else
            continue;
            */
    }
    return sum;
}
