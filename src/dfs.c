/*
 * Search an expression using DFS.
 */

#include "dfs.h"

#include <assert.h>
#include <stdbool.h> /* bool, true, false */
#include <stdio.h>   /* scanf, printf */
#include <stdlib.h>  /* abort */

void DFT(node *root) {
    print_node(root);
    if (root->lchild != NULL) DFT(root->lchild);
    if (root->rchild != NULL) DFT(root->rchild);
    return;
}

node *make_node(int num, node *left, node *right) {
    node *new = malloc(sizeof(node));
    new->lchild = left;
    new->rchild = right;
    new->num = num;
    new->visited = false;
    return new;
}

void free_node(node *p) {
    if (p == NULL) return;
    free_node(p->lchild);
    free_node(p->rchild);
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
    stack *newS = (stack *)malloc(sizeof(stack));

    newS->next = topp;
    newS->node = node;

    return newS;
}

bool isEmpty(stack *topp) { return topp == NULL; }

node *top(stack *topp) { return topp->node; }
// Utility function to pop topp
// element from the stack

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
