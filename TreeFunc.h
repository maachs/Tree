#ifndef TREEFUNC_
#define TREEFUNC_

#include "Tree.h"

int Insert(Node_t* node, int value);

Node_t* MakeNode(Node_t* parent, int value);

int TreeDtor(Node_t* root);

void PrintInorder(Node_t* node);

#endif
