#include "bst.h"

#include <stdio.h>
#include <stdlib.h>

struct bst_node *create_node(int value)
{
    struct bst_node *node = malloc(sizeof(struct bst_node));
    if (!node)
        return NULL;
    node->data = value;
    node->left = NULL;
    node->right = NULL;
    return node;
}

struct bst_node *add_node(struct bst_node *tree, int value)
{
    if (!tree)
        return create_node(value);
    else if (value < tree->data)
        tree->left = add_node(tree->left, value);
    else if (value > tree->data)
        tree->right = add_node(tree->right, value);
    return tree;
}

struct bst_node *delete_node(struct bst_node *tree, int value)
{
    if (!tree)
        return NULL;
    if (tree->data == value)
    {
        struct bst_node *node = NULL;
        if (tree->left == NULL && tree->right == NULL)
        {
            free(tree);
            return node;
        }
        if (tree->left != NULL && tree->right != NULL)
        {
            node = tree->left;
            while (node->right != NULL)
                node = node->right;
            tree->data = node->data;
            //node = tree;
            tree->left = delete_node(tree->left, tree->data);
            return tree;
        }
        else if (tree->left == NULL)
            node = tree->right;
        else if (tree->right == NULL)
            node = tree->left;
        else
            free(tree);
        return node;
    }
    else if (value < tree->data)
        tree->left = delete_node(tree->left, value);
    else
        tree->right = delete_node(tree->right, value);
    return tree;
}

const struct bst_node *find(const struct bst_node *tree, int value)
{
    if (!tree)
        return NULL;
    if (tree->data == value)
        return tree;
    if (value < tree->data)
        return find(tree->left, value);
    return find(tree->right, value);
}

void free_bst(struct bst_node *tree)
{
    if (tree != NULL)
    {
        free_bst(tree->left);
        free_bst(tree->right);
        free(tree);
    }
}
