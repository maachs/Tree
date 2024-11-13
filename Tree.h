#ifndef TREE_
#define TREE_

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

struct Node_t
{
    int     data;
    Node_t* left;
    Node_t* right;
    Node_t* parent;
};

#endif
