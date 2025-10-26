#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include "tree.h"
#include "phone.h"
int minPhones(Node *root) {
    if (root == NULL)
        return INT_MAX;

    int leftMin = minPhones(root->left);
    int rightMin = minPhones(root->right);

    int min = root->value;
    if (leftMin < min) min = leftMin;
    if (rightMin < min) min = rightMin;

    return min;
}
void findminphones(Node *root) {
    if (root == NULL) {
        printf("tree is empty\n");
        return;
    }
    int minValue = minPhones(root);
    printf("Minimum number of phones in the tree: %d\n", minValue);
}
