#ifndef TREE_H
#define TREE_H
typedef struct Node{
    int value;
    struct Node*left;
    struct Node*right;
}Node;
Node* createNode(int value);
Node* buildTree();
void freeTree(Node* root);
#endif
