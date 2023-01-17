#include "encoder.h"
#include <locale.h>

void    print_queue(Node **head)
{
    setlocale(LC_ALL, "utf8");
    Node *current = *head;

    while (current)
    {
        printf("character =%c frequency= %d\n", current->character, current->frequency);
        current = current->next;
    }
    printf("\n");
}

void    print_tree(Node *head)
{
    setlocale(LC_ALL, "utf8");
    if (head->left)
        print_tree(head->left);
    if (is_leaf_node(head))
        printf("\t%c \t%d\n", head->character, head->frequency);
    if (head->right)
        print_tree(head->right);
}

void    print_dict(char **dict)
{
    setlocale(LC_ALL, "utf8");
    printf("\n\tDictionary\n");
    int i = -1;
    while (++i < SIZE_TABLE)
        if (strlen(dict[i]) > 0)
            printf("\t%3d: |%s| \t%c\n", i, dict[i], i);
}

void    print_frequency_table(unsigned int *table)
{
    printf("\tfrequency_table:\n");
    for (int i = 0; i < SIZE_TABLE; i++) {
        if (table[i] > 0)
            printf("\tDECIMAL: %-3d   |   FREQUENCY: %-3d   |   CHAR: %-3c\n", i, table[i], i);
    }
    printf("\n");
}