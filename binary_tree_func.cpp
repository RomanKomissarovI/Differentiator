#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "binary_tree_func.h"

static const char signs[5] = {'+', '-', '*', '/', 'x'};
static const char* functions[7] = {"exp", "ln", "pow" ,"sqrt", "sin", "cos", "tg"};

Node* CreateNode(char type, char sign, Node_t val, Node* lnode, Node* rnode)
{
    Node* n = (Node*) calloc(1, sizeof(Node));
    n->type = type;
    n->sign = sign;
    n->value = val;
    n->left = lnode;
    n->right = rnode;
    return n;
}

Node* CopyNode(Node* node)
{
    Node* n = (Node*) calloc(1, sizeof(Node));
    n->type = node->type;
    n->sign = node->sign;
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

    if (node->type == FUNC)
    {
        if (node->sign == -1)
        {
            printf("-");
        }
        
        if (node->value == pow_f)
        {
            TreePrint(node->left);
            printf("^");
            TreePrint(node->right);
        }
        else
        {
            printf(" %s(", functions[node->value]);
            TreePrint(node->left);
            printf(") ");
        }
    }
    else
    {
        if (node->type == OP)
            printf("(");
        
        if (node->sign == -1)
        {
            printf("-");
        }

        if (node->left) TreePrint(node->left);

        if (node->type == OP || node->type == VAR)
        {
            printf(" %c ", signs[node->value]);
        }
        else printf(" " format_tree " ", node->value);

        if (node->right) TreePrint(node->right);

        if (node->type == OP)
            printf(")");
    }
}