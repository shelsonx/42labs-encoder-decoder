#include "encoder.h"

int get_tree_height(Node *root)
{
    int left;
    int right;

    left = 0;
    right = 0;
    if (root == NULL)
        return -1;
    left = get_tree_height(root->left) + 1;
    right = get_tree_height(root->right) + 1;
    if (left > right)
        return left;
    return right;
}

char    **alloc_dict(int columns)
{
    char    **dict;
    int     i;

    dict = malloc(sizeof(char *) * SIZE_TABLE + 1);
    i = -1;
    while (++i < SIZE_TABLE)
        dict[i] = calloc(columns, sizeof(char) + 1);
    return (dict);
}

void    generate_dict(char **dict, Node *root, char *path, int columns)
{
    char    left[columns];
    char    right[columns];

    if (is_leaf_node(root))
        strcpy(dict[root->character], path);
    else
    {
        strcpy(left, path);
        strcpy(right, path);
        strcat(left, "0");
        strcat(right, "1");
        generate_dict(dict, root->left, left, columns);
        generate_dict(dict, root->right, right, columns);
    }
}

void	free_dict(char **dict)
{
	int	i;

	if (!dict)
		return ;
	i = 0;
	while (dict[i])
	{
		if (dict[i])
		{
			free(dict[i]);
			dict[i] = NULL;
		}
		i++;
	}
	free(dict);
}
