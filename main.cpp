#include <stdio.h>
#include <string.h>
#include "binary_tree_func.h"
#include "in_out.h"
#include "differenciator.h"
#include "recuresive_descent.h"

int main()
{  
    FILE* data_file = fopen("output.txt", "r");

    char s[1000];
    scanf("%[^\n]", s);
    //const char* s = "5 + 3 $";

    //Node* root = _DIV(_ADD(_x, _NUM(3)), _SUB(_NUM(1000), _NUM(7)));
    //Node* root = _DIV(_x, _SUB(_NUM(1000), _NUM(7)));
    Node* root = GetG(s);
    Node* d = Diff(root);

    TreePrint(root);
    printf("\n");
    TreePrint(d);

    fclose(data_file);
    return 0;
}