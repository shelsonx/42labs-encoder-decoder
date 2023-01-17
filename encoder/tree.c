#include "encoder.h"

void    build_tree(Node **root)
{
    Node    *first;
    Node    *second;
    Node    *tree_node;
    if ((*root)->next == NULL)
        return ;
    first = dequeue(root);
    second = dequeue(root);
    tree_node = new_node('*', (first->frequency + second->frequency));
    tree_node->left = first;
    tree_node->right = second;
    enqueue(root, tree_node);
    sort_queue(root, size_queue(*root));
    build_tree(root);
}

int is_leaf_node(Node *root)
{
    return (root->left == NULL && root->right == NULL);
}
