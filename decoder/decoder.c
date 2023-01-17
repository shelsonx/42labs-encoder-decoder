#include "decoder.h"

static char *char_to_str(char c)
{
    char    str[2];
    char    *ptr_str;

    str[0] = c;
    str[1] = '\0';
    ptr_str = str;
    return (ptr_str);
}

char    *decoder(unsigned char *encoded, Node *root)
{
    Node    *current_root;
    char    *decoded;
    int     i;

    decoded = calloc(strlen((char *)encoded), sizeof(char));
    i = -1;
    current_root = root;
    while (encoded[++i])
    {
        if (encoded[i] == '0')
            current_root = current_root->left;
        else
            current_root = current_root->right;
        if (is_leaf_node(current_root))
        {
            strcat(decoded, char_to_str(current_root->character));
            current_root = root;
        }
    }
    return (decoded);
}
