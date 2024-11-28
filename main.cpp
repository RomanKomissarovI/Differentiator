#include <stdio.h>
#include <string.h>
#include "binary_tree_func.h"
#include "in_out.h"
#include "differenciator.h"
#include "recuresive_descent.h"

int main()
{  
    //FILE* data_file = fopen("output.txt", "r");

    //char s[1000];
    //scanf("%[^\n]", s);

    Node* root = _MUL(_x, _SIN(_LN(_x)));
    
    //Node* root = GetG(s);
    Node* d = Diff(root);

    TreePrint(root);
    printf("\n");
    TreePrint(d);

    //fclose(data_file);
    return 0;
}