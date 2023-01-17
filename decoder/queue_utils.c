#include "decoder.h"

static Node    *swap_node(Node *node_p1, Node *node_p2)
{
    Node* tmp;

    tmp = node_p2->next;
    node_p2->next = node_p1;
    node_p1->next = tmp;
    return (node_p2);
}

Node    **swap(Node **current, int *swapped)
{
    Node    *ptr_current;
    Node    *ptr_next;

    ptr_current = *current;
    ptr_next = ptr_current->next;
    if (ptr_current->frequency > ptr_next->frequency) {

        *current = swap_node(ptr_current, ptr_next);
        *swapped = TRUE;
    }
    current = &(*current)->next;
    return (current);
}

int sort_queue(Node **head, int count)
{
    Node    **current;
    int     i;
    int     j; 
    int     swapped;
 
    i = -1;
    while (++i <= count) {
        current = head;
        swapped = FALSE;
        j = -1;
        while (++j < count - i - 1) 
            current = swap(current, &swapped);
        if (!swapped)
            break;
    }
    return (0);
}

void free_tree(Node *root) 
{
  if (root == NULL)
    return;

  free_tree(root->left);
  free_tree(root->right);

  free(root);
  root = NULL;
}

void    add_to_queue(unsigned int *table, Node **head)
{
    int i = -1;

    while (++i < SIZE_TABLE)
        if (table[i] > 0)
            enqueue(head, new_node(i, table[i]));
}
