#include "TreeFunc.h"

int main()
{
    struct Node_t* root = MakeNode(NULL, 50);

    Insert(root, 30);
    Insert(root, 10);
    Insert(root, 70);
    Insert(root, 65);
    Insert(root, 80);
    Insert(root, 66);

    PrintInorder(root);

    TreeDtor(root);

    return 0;
}

Node_t* MakeNode(Node_t* parent, int value)
{
    Node_t* node = (Node_t*)calloc(1, sizeof(Node_t));

    if(node == NULL)
    {
        printf("calloc error");

        return NULL;
    }

    node->data = value;
    node->left = NULL;
    node->right = NULL;

    node->parent = parent;

    return node;
}

int Insert(Node_t* node, int value)
{
    assert(node);
    assert(value);

    if(value < node->data)
    {
        if(node->left != NULL)
        {
            Insert(node->left, value);
        }
        else
        {
            node->left = MakeNode(node->left, value);

            if(node->left == NULL)
            {
                return -1;
            }
        }
    }
    else
    {
        if(node->right != NULL)
        {
            Insert(node->right, value);
        }
        else
        {
            node->right = MakeNode(node->right, value);

            if(node->right == NULL)
            {
                return -1;
            }
        }
    }

    return 0;
}

int TreeDtor(Node_t* node)
{
    if(!node)
    {
        return 0;
    }

    TreeDtor(node->left);
    TreeDtor(node->right);

    free(node);

    node = NULL;

    return 0;

}

void PrintInorder(Node_t* node)
{
    if(!node) return;

    printf("(");

    if(node->left)
    {
        PrintInorder(node->left);
    }

    printf("%d", node->data);

    if(node->right)
    {
        PrintInorder(node->right);
    }

    printf(")");
}
