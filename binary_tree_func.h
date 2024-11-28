#ifndef BINARY_TREE_FUNC_H
#define BINARY_TREE_FUNC_H

#include "node.h"

#define _NUM(x) CreateNode(NUM, 1, x, nullptr, nullptr)
#define _x CreateNode(VAR, 1, var_v, nullptr, nullptr)

#define _ADD(a, b) CreateNode(OP, 1, add_v, a, b)
#define _SUB(a, b) CreateNode(OP, 1, sub_v, a, b)
#define _DIV(a, b) CreateNode(OP, 1, div_v, a, b)
#define _MUL(a, b) CreateNode(OP, 1, mul_v, a, b)

#define _EXP(a) CreateNode(FUNC, 1, exp_f, a, nullptr)
#define _LN(a) CreateNode(FUNC, 1, ln_f, a, nullptr)
#define _POW(a, b) CreateNode(FUNC, 1, pow_f, a, b)
#define _SQRT(a) CreateNode(FUNC, 1, sqrt_f, a, nullptr)
#define _SIN(a) CreateNode(FUNC, 1, sin_f, a, nullptr)
#define _COS(a) CreateNode(FUNC, 1, cos_f, a, nullptr)
#define _TG(a) CreateNode(FUNC, 1, tg_f, a, nullptr)

Node* CreateNode(char type, char sign, Node_t val, Node* lnode, Node* rnode);

Node* CopyNode(Node* node);

void TreePrint(Node* node);

#endif // BINARY_TREE_FUNC_H
