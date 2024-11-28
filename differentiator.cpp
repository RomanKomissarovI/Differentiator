#include <stdio.h>
#include <assert.h>
#include "differenciator.h"
#include "binary_tree_func.h"

#define S(x) Simplification(x)

Node* Diff(Node* node)
{
    if (node->type == NUM) return _NUM(0);
    if (node->type == VAR) return _NUM(1);
    if (node->type == OP) 
    {
        switch (node->value)
        {
            case add_v: return S(_ADD(Diff(node->left), Diff(node->right)));
            case sub_v: return S(_SUB(Diff(node->left), Diff(node->right)));
            case mul_v: return S(_ADD(S(_MUL(Diff(node->left), S(node->right))),
                                  S(_MUL(S(node->left), Diff(node->right)))));
            case div_v: return S(_DIV(S(_SUB(S(_MUL(Diff(node->left), S(node->right))), S(_MUL(S(node->left), Diff(node->right))))),
                                  S(_MUL(S(node->right), S(node->right)))));
            default: 
                printf("Error input data\n");
                return _NUM(0);
        }
    }
    if (node->type == FUNC)
    {
        switch (node->value)
        {
            case exp_f: return S(_MUL(node, Diff(node->left)));
            case ln_f: return S(_DIV(Diff(node->left), node->left));
            case pow_f: return Diff(_EXP(_MUL(_LN(node->left), node->right)));
            case sqrt_f: return S(_DIV(Diff(node->left), _MUL(node, _NUM(2))));
            case sin_f: return S(_MUL(Diff(node->left), _COS(node->left)));
            case cos_f: return  S(_MUL(_MUL(Diff(node->left), _SIN(node->left)), _NUM(-1)));
            case tg_f: return S(_DIV(Diff(node->left), _POW(_COS(node->left), _NUM(2))));
            default: 
                printf("Error input data\n");
                return _NUM(0);
        }
    }
    else
    {
        printf("Error input data\n");
        return _NUM(0);
    }
}

Node* Simplification(Node* oper)
{
    assert(oper != nullptr);
    if (oper->type != OP)
    {
        return oper;
    }

    if (((oper->value == mul_v || oper->value == div_v) && (oper->left->type == NUM && oper->left->value == 0)) ||
                                  (oper->value == mul_v && oper->right->type == NUM && oper->right->value == 0))
    {
        return _NUM(0);
    }
    
    if ((oper->value == add_v || oper->value == sub_v) && (oper->right->type == NUM && oper->right->value == 0)) // унарный оператор
    {
        return oper->left;
    }
    
    if (NodeEqual(oper->left, oper->right))
    {
        if (oper->value == add_v)
        {
            if (oper->left->type == NUM)
            {
                return _NUM(oper->left->value + oper->right->value);
            }
        }
        if (oper->value == mul_v)
        {
            if (oper->left->type == NUM)
            {
                return _NUM(oper->left->value * oper->right->value);
            }
        }
        if (oper->value == sub_v)
        {
            if (oper->left->type == NUM)
            {
                return _NUM(oper->left->value - oper->right->value);
            }
        }
        if (oper->value == div_v)
        {
            if (oper->left->type == NUM)
            {
                Node_t lv = oper->left->value;
                Node_t rv = oper->right->value;

                if (lv % rv == 0)
                {
                    return _NUM(lv / rv);
                }
                Node_t gcd = Gcd(lv, rv);
                return _DIV(_NUM(lv / gcd), _NUM(rv / gcd));
            }
        }
    }

    return oper;
}

Node_t Gcd(Node_t a, Node_t b)
{
    if (b == 0)
        return a;
    return Gcd(b, a % b);
}

char NodeEqual(Node* node1, Node* node2)
{
    if ((!node1) && (!node2)) return 1;
    if (node1->type == node2->type && (node2->type == NUM || node2->type == VAR)) return 1;
    if ((node1->type == node2->type) && (node2->type == add_v || node2->type == mul_v))
    {
        return (NodeEqual(node1->left, node2->left) && NodeEqual(node1->right, node2->right)) || 
               (NodeEqual(node1->right, node2->left) && NodeEqual(node1->left, node2->right));
    }
    if (node1->type == node2->type)
    {
        return NodeEqual(node1->left, node2->left) && NodeEqual(node1->right, node2->right);
    }

    return 0;
}