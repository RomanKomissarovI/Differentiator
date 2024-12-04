#include <stdio.h>
#include <string.h>
#include "binary_tree_func.h"
#include "in_out.h"
#include "differenciator.h"
#include "recuresive_descent.h"

// как обрабатывать ошибки

int main()
{  
    //FILE* data_file = fopen("output.txt", "r");

    char s[1000];
    scanf("%[^\n]", s);
    int len = strlen(s);
    s[len] = '$';
    s[len + 1] = '\0';

    //Node* root = _POW(_x, _ADD(_x, _NUM(3)));
    
    Node* root = GetG(s);
    Node* d = Diff(root);

    TreePrint(root);
    printf("\n");
    TreePrint(d);

    //fclose(data_file);
    return 0;
}