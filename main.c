#include<stdio.h>
#include<stdlib.h>
#include "phone.h"
#include "tree.h"
int main()
{
    Node *root=buildTree();
    findminphones(root);
    freeTree(root);
    return 0;
}
