extern "C" {
#include <malloc.h>

#include <cstddef>

#include "dfs.h"
#include "search.h"
#include "sum.h"
}

// File for sandboxing and trying out code
int main(int argc, char** argv) {
    node* root = make_node(
        4,
        make_node(
            7,
            make_node(28, make_node(77, NULL, NULL), make_node(23, NULL, NULL)),
            make_node(86, make_node(3, NULL, NULL), make_node(9, NULL, NULL))),
        make_node(98, NULL, NULL));

    print_tree(root, 0);

    DFT(root);

    return 0;
}