#include <stdio.h>
#include <stdlib.h>
#include "tree.h"
typedef struct QueueNode{
Node*data;
struct QueueNode *next;
}QueueNode;

typedef struct Queue {
    QueueNode *front;
    QueueNode *rear;
} Queue;
void enqueue(Queue *q, Node *data) {
    QueueNode *temp = (QueueNode *)malloc(sizeof(QueueNode));
    temp->data = data;
    temp->next = NULL;
    if (q->rear == NULL) {
        q->front = q->rear = temp;
        return;
    }
    q->rear->next = temp;
    q->rear = temp;
}
Node* dequeue(Queue *q) {
    if (q->front == NULL)
        return NULL;
    QueueNode *temp = q->front;
    Node *data = temp->data;
    q->front = q->front->next;
    if (q->front == NULL)
        q->rear = NULL;
    free(temp);
    return data;
}
Node* createNode(int value) {
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->value = value;
    newNode->left = newNode->right = NULL;
    return newNode;
}
Node* buildTree() {
    int n;
    if (scanf("%d", &n) != 1 || n <= 0) {
        printf("Invalid number of nodes.\n");
        return NULL;
    }
    int *arr = (int *)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    // If the first value is -1, tree is empty
    if (arr[0] == -1) {
        free(arr);
        return NULL;
    }
    Node *root = createNode(arr[0]);
    Queue q = {NULL, NULL};
    enqueue(&q, root);

    int i = 1;
    while (i < n) {
        Node *current = dequeue(&q);
        if (current == NULL) break;

        // Left child
        if (i < n && arr[i] != -1) {
            current->left = createNode(arr[i]);
            enqueue(&q, current->left);
        }
        i++;
        if (i < n && arr[i] != -1) {
            current->right = createNode(arr[i]);
            enqueue(&q, current->right);
        }
        i++;
    }
    free(arr);
    return root;
}
void freeTree(Node *root) {
    if (root == NULL)
      return;
    freeTree(root->left);
    freeTree(root->right);
    free(root);
}
