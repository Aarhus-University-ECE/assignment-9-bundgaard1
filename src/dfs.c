/*
 * Search an expression using DFS.
 */

#include "dfs.h"

#include <assert.h>
#include <stdbool.h> /* bool, true, false */
#include <stdio.h>   /* scanf, printf */
#include <stdlib.h>  /* abort */

void DFT(node *root) {
    print_node(root);  // Print the value of the node.

    // Recursive step left first, the the right child.
    if (root->lchild != NULL) DFT(root->lchild);
    if (root->rchild != NULL) DFT(root->rchild);
    return;
}

node *make_node(int num, node *left, node *right) {
    node *new = malloc(sizeof(node));  // Make a new node
    new->lchild = left;  // Declare the correct values to new nodes
    new->rchild = right;
    new->num = num;
    new->visited = false;
    return new;  // Return pointer to the new node
}

void free_node(node *p) {
    if (p == NULL) return;  // If there is no node, we dont care
    free_node(p->lchild);   // Free the left node
    free_node(p->rchild);   // Free the right node
    free(p);
    return;
}

void print_node(node *p) {
    if (p == NULL)
        printf("NULL\n");
    else
        printf("%d, ", p->num);
}

void print_tree(node *p, int depth) {
    for (int i = 0; i < depth; i = i + 1) printf(" ");
    printf("| ");

    if (p == NULL)
        printf("NULL\n");
    else
        printf("[%d]\n", p->num);

    if (p->lchild) {
        print_tree(p->lchild, depth + 1);
    }

    if (p->rchild) print_tree(p->rchild, depth + 1);
}

stack *push(stack *topp, node *node) {
    stack *newS = (stack *)malloc(sizeof(stack));  // New  top stack

    newS->next = topp;  // Declare the values
    newS->node = node;

    return newS;  // return new stack
}

bool isEmpty(stack *topp) { return topp == NULL; }

node *top(stack *topp) { return topp->node; }

stack *pop(stack *topp) {
    assert(!isEmpty(topp));
    return topp->next;
}

void print_stack(stack *topp) {
    struct stack *temp = topp;

    while (temp != NULL) {
        print_node(temp->node);
        printf("\n");

        temp = temp->next;
    }

    printf("====\n");

    return;
}
