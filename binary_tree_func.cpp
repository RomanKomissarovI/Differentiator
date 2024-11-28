#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "binary_tree_func.h"

static const char signs[5] = {'+', '-', '*', '/', 'x'};

Node* CreateNode(char type, Node_t val, Node* lnode, Node* rnode)
{
    Node* n = (Node*) calloc(1, sizeof(Node));
    n->type = type;
    n->value = val;
    n->left = lnode;
    n->right = rnode;
    return n;
}

Node* CopyNode(Node* node)
{
    Node* n = (Node*) calloc(1, sizeof(Node));
    n->type = node->type;
    n->value = node->value;
    n->left = node->left;
    n->right = node->right;
    return n;
}

void TreePrint(Node* node)
{
    if (node == nullptr)
    {
        printf("Error node ptr in TreePrint\n");
        return;
    }

    printf("(");
    if (node->left) TreePrint(node->left);
    if (node->type == OP || node->type == VAR)
    {
        printf(" %c ", signs[node->value]);
    }
    else printf(" " format_tree " ", node->value);
    if (node->right) TreePrint(node->right);
    printf(")");
}