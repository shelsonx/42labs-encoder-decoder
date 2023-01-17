#include "decoder.h"

void    enqueue(Node **tail, Node *new_node)
{
    Node    *get_last;

    if (!*tail)
    {
        *tail = new_node;
        return ;
    }
    get_last = last_node(*tail);
    get_last->next = new_node;
}

Node    *dequeue(Node **head)
{
    Node    *tmp;

    if (!*head)
        return (*head);
    tmp = *head;
    *head = (*head)->next;
    return (tmp);
}

Node    *new_node(char character, int frequency)
{
    Node    *node;

    node = malloc(sizeof(Node));
    if (!node)
        return (NULL);
    node->character = character;
    node->frequency = frequency;
    node->next = NULL;
    node->left = NULL;
    node->right = NULL;
    return (node);
}

Node    *last_node(Node *last)
{
    if (!last)
        return (last);
    while (last->next != NULL)
        last = last->next;
    return (last);
}

int size_queue(Node *head)
{
	int		count;
	Node	*tmp;

	if (!head)
		return (0);
	count = 0;
	tmp = head;
	while (tmp)
	{
		tmp = tmp->next;
		count++;
	}
	return (count);
}
