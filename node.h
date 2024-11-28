#ifndef NODE_H
#define NODE_H

#ifndef format_tree
#define format_tree "%I64d"
#endif // format_tree

typedef long long Node_t;

enum Values
{
    add_v = 0,
    sub_v = 1,
    mul_v = 2,
    div_v = 3,
    var_v = 4,
};

enum Func
{
    exp_f = 0,
    ln_f = 1,
    pow_f = 2,
    sqrt_f = 3,
    sin_f = 4,
    cos_f = 5,
    tg_f = 6,
};

enum Types
{
    NUM = 1,
    VAR = 2,
    OP = 3,
    FUNC = 4,
};

struct Node
{
    char type;
    char sign;
    Node_t value;
    Node* left;
    Node* right;
};

#endif // NODE_H