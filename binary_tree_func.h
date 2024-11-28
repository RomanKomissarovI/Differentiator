#ifndef BINARY_TREE_FUNC_H
#define BINARY_TREE_FUNC_H

#include "node.h"

#define _NUM(x) CreateNode(NUM, x, nullptr, nullptr)
#define _x CreateNode(VAR, var_v, nullptr, nullptr)

#define _ADD(a, b) CreateNode(OP, add_v, a, b)
#define _SUB(a, b) CreateNode(OP, sub_v, a, b)
#define _DIV(a, b) CreateNode(OP, div_v, a, b)
#define _MUL(a, b) CreateNode(OP, mul_v, a, b)

#define _EXP(a) CreateNode(FUNC, exp_f, a, nullptr)
#define _LN(a) CreateNode(FUNC, ln_f, a, nullptr)
#define _POW(a, b) CreateNode(FUNC, pow_f, a, b)
#define _SQRT(a) CreateNode(FUNC, sqrt_f, a, nullptr)
#define _SIN(a) CreateNode(FUNC, sin_f, a, nullptr)
#define _COS(a) CreateNode(FUNC, cos_f, a, nullptr)
#define _TG(a) CreateNode(FUNC, tg_f, a, nullptr)

Node* CreateNode(char type, Node_t val, Node* lnode, Node* rnode);

Node* CopyNode(Node* node);

void TreePrint(Node* node);

#endif // BINARY_TREE_FUNC_H
