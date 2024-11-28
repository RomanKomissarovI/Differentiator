#include "recuresive_descent.h"

// void SyntaxError()
// {
//     printf("SyntaxError")
// }

static int p = 0;

Node* GetG(const char* s)
{
    Node* val = GetE(s);
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
    SkipSpaces(s);


    while (s[p] == '+' || s[p] == '-')
    {
        int op = s[p];
        p++;

        Node* val2 = GetT(s);
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
    Node* val = GetP(s);
    SkipSpaces(s);

    while (s[p] == '*' || s[p] == '/')
    {
        int op = s[p];
        p++;

        Node* val2 = GetP(s);
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

Node* GetP(const char* s)
{
    SkipSpaces(s);
    
    if (s[p] == '(')
    {
        p++;
        Node* val = GetE(s);

        SkipSpaces(s);

        if (s[p] != ')')
        {
            printf("SyntaxError in p == %d: expected ')', %c received\n", p, s[p]);
            exit(0);
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
    SkipSpaces(s);

    if ('0' <= s[p] && s[p] <= '9')
    {
        return GetN(s);
    }
    if (s[p] == 'x')
    {
        p++;
        return _x;
    }
    printf("SyntaxError in p == %d: expected a number or variable, %c received\n", p, s[p]);
    exit(0);
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
        printf("SyntaxError in p == %d: expected a number, %c received\n", p, s[p]);
        exit(0);
    }
    
    return val;
}

void SkipSpaces(const char* s)
{
    while (s[p] == ' ' || s[p] == '\t') p++;
}