#ifndef RECURSIVE_DESCENT_H
#define RECURSIVE_DESCENT_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "node.h"
#include "binary_tree_func.h"

Node* GetG(const char* s);

Node* GetE(const char* s);

Node* GetT(const char* s);

Node* GetPow(const char* s);

Node* GetP(const char* s);

Node* GetArg(const char* s);

Node* GetOperand(const char* s);

Node* GetN(const char* s);

Node* GetX(const char* s);

Node* GetFunc(const char* s);

Node* GetFuncName(const char* s);

void SkipSpaces(const char* s);

#endif