#include "recuresive_descent.h"

// void SyntaxError()
// {
//     printf("SyntaxError")
// }

static int p = 0;
static int Max_Size_Name = 30;
static const char* functions[7] = {"exp", "ln", "pow" ,"sqrt", "sin", "cos", "tg"};

Node* GetG(const char* s)
{
    Node* val = GetE(s);
    if (!val) 
    {
        printf("SyntaxError in p == %d\n", p);
        return nullptr;
    }
    SkipSpaces(s);

    if (s[p] != '$')
    {
        printf("SyntaxError in p == %d: expected $, %c received\n", p, s[p]);
        exit(0);
    }
    
    p++;
    return val;
}

Node* GetE(const char* s)
{
    Node* val = GetT(s);
    if (!val) return nullptr;
    SkipSpaces(s);

    while (s[p] == '+' || s[p] == '-')
    {
        int op = s[p];
        p++;

        Node* val2 = GetT(s);
        if (!val2) return nullptr;
        SkipSpaces(s);

        if (op == '+')
        {
            val = _ADD(val, CopyNode(val2));
        }
        else if (op == '-')
        {
            val = _SUB(val, CopyNode(val2));
        }
        free(val2);
        SkipSpaces(s);
    }
    
    return val;
}

Node* GetT(const char* s)
{
    Node* val = GetPow(s);
    if (!val) return nullptr;
    SkipSpaces(s);

    while (s[p] == '*' || s[p] == '/')
    {
        int op = s[p];
        p++;

        Node* val2 = GetPow(s);
        if (!val2) return nullptr;
        SkipSpaces(s);

        if (op == '*')
        {
            val = _MUL(val, CopyNode(val2));
        }
        else if (op == '/')
        {
            val = _DIV(val, CopyNode(val2));
        }

        free(val2);
        SkipSpaces(s);
    }
    
    return val;
}

Node* GetPow(const char* s)
{
    Node* val = GetP(s);
    if (!val) return nullptr;
    SkipSpaces(s);

    while (s[p] == '^')
    {
        p++;

        Node* val2 = GetP(s);
        if (!val2) return nullptr;
        SkipSpaces(s);

        val = _POW(val, CopyNode(val2));

        free(val2);
        SkipSpaces(s);
    }
    
    return val;
}

Node* GetP(const char* s)
{
    SkipSpaces(s);
    
    if (s[p] == '(')
    {
        p++;
        Node* val = GetE(s);
        if (!val) return nullptr;
        SkipSpaces(s);

        if (s[p] != ')')
        {
            free(val);
            return nullptr;
            // printf("SyntaxError in p == %d: expected ')', %c received\n", p, s[p]);
            // exit(0);
        }
        p++;
        
        return val;
    }
    else
    {
        return GetArg(s);
    }
}

Node* GetArg(const char* s)
{
    char sign = 1;
    SkipSpaces(s);
    if (s[p] == '-')
    {
        p++;
        sign = -1;
    }
    Node* node = GetOperand(s);
    if (node)
    {
        node->sign = sign;
        return node;
    }

    node = GetFunc(s);
    if (node) node->sign = sign;
    return node;
}

Node* GetOperand(const char* s)
{
    Node* node = GetN(s);

    if (node) return node;

    return GetX(s);
}

Node* GetN(const char* s)
{
    Node* val = _NUM(0);
    SkipSpaces(s);
    int old_p = p;
    
    while ('0' <= s[p] && s[p] <= '9')
    {
        val->value = (val->value) * 10 + s[p] - '0';
        p++;
    }
    
    if (p == old_p)
    {
        free(val);
        return nullptr;
        // printf("SyntaxError in p == %d: expected a number, %c received\n", p, s[p]);
        // exit(0);
    }
    
    return val;
}

Node* GetX(const char* s)
{
    SkipSpaces(s);
    if (s[p] == 'x' && !isalpha(s[p + 1]) && s[p + 1] != '(')
    {
        p++;
        return _x;
    }
    return nullptr;
}

Node* GetFunc(const char* s)
{
    Node* node = GetFuncName(s);
    if (!node) return nullptr;
    SkipSpaces(s);

    if (s[p] == '(')
    {
        p++;
        Node* val = GetE(s);
        if (!val) return nullptr;
        SkipSpaces(s);

        if (s[p] != ')')
        {
            free(val);
            return nullptr;
        }

        p++;
        node->left = val;
        return node;
    }
    
    return nullptr;
}

Node* GetFuncName(const char* s)
{
    char* str = (char*) calloc(Max_Size_Name + 1, sizeof(char));
    int index = 0;
    SkipSpaces(s);

    while (index < Max_Size_Name && (('a' <= s[p] && s[p] <= 'z') || ('A' <= s[p] && s[p] <= 'Z')))
    {
        str[index++] = s[p++];
    }
    str[index] = '\0';

    for (int i = 0; i < Num_Func; ++i)
    {
        if (strcmp(str, functions[i]) == 0)
        {
            return CreateNode(FUNC, 1, i, nullptr, nullptr);
        }
    }

    return nullptr;
}

void SkipSpaces(const char* s)
{
    while (s[p] == ' ' || s[p] == '\t') p++;
}