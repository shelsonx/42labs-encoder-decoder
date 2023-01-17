#include "encoder.h"

unsigned char   *get_text(char **argv)
{
    unsigned char    *text;

    int amount = amount_char_in_file(argv[1]);
    text = calloc(amount + 1, sizeof(char));
    load_file_to_str(argv[1], text);
    return (text);
}

bool    valid_args(int argc)
{
    if (argc != 2)
    {
        if (argc == 1)
            printf("Invalid arguments!\nmissing filename!\n");
        else
            printf("Invalid arguments!\nmany filenames!\n");
        return (false);
    }
    return (true);
}

char    **get_dict(Node *root)
{
    char    **dict;

    int columns = get_tree_height(root);
    dict = alloc_dict(columns);
    generate_dict(dict, root, "", columns);
    return (dict);
}

void    init_frequency_table(unsigned int *table)
{
    int    i;

    i = -1;
    while (++i < SIZE_TABLE)
        table[i] = 0;
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
