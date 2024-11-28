#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include "in_out.h"
#include "binary_tree_func.h"

// static const int Max_Len_Size = 100;

// Node* TreeFileInput(FILE* input)
// {
//     Node* node = CreateNode("");
//     char* s = (char*) calloc(Max_Len_Size, sizeof(char)); 
    
//     fscanf(input, "%[^\n]", s);
//     int l = 0, r = 0;
//     fscanf(input, "%d %d\n", &l, &r);

//     node->data = (char*) calloc(strlen(s), sizeof(char));
//     strcpy(node->data, s);

//     free(s);

//     if (l == 1)
//     {
//         node->left = TreeFileInput(input);
//     }
//     if (r == 1)
//     {
//         node->right = TreeFileInput(input);
//     }

//     return node;
// }

// void TreeFileOut(FILE* output, Node* node, int depth)
// {
//     assert(output != 0);

//     //MakeIndent(output, depth);

//     fprintf(output, format_tree "\n", node->data);
//     fprintf(output, "%d %d\n", (node->left != nullptr), (node->right != nullptr));

//     if (node->left != nullptr || node->right != nullptr)
//     {
//         //MakeIndent(output, depth);
//         TreeFileOut(output, node->left, depth + 1);
//         TreeFileOut(output, node->right, depth + 1);
//         //MakeIndent(output, depth);
//     }
// }

// void MakeIndent(FILE* output, int depth)
// {
//     for (int i = 0; i < depth; ++i)
//     {
//         fprintf(output, "\t");
//     }
// }