#include "decoder.h"

static void init_data_decompress(t_data_decompress *data, Node *root, int fd_out)
{
    data->file = get_file(COMPRESSED, C_M_RB);
    data->index = 7;
    data->one_byte = 0;
    data->mask = 1;
    data->curr_node = root;
    data->fd_out = fd_out;
}

static unsigned int is_one(t_data_decompress *data)
{
    unsigned char mask;

    mask = (1 << data->index);
    return (data->one_byte & mask);
}

static void traversing(t_data_decompress *data)
{
     if (is_one(data))
        data->curr_node = data->curr_node->right;
    else
        data->curr_node = data->curr_node->left;
}

static void save_and_reset(t_data_decompress *data, Node *root)
{
    write(data->fd_out, &data->curr_node->character, sizeof(char));
    data->curr_node = root;
}

void    decompress(Node *root, int fd_out)
{
    t_data_decompress data;

    init_data_decompress(&data, root, fd_out);
    while (fread(&data.one_byte, sizeof(unsigned char), 1, data.file))
    {
        for (data.index = 7; data.index >= 0; data.index--)
        {
            traversing(&data);
            if (is_leaf_node(data.curr_node))
                save_and_reset(&data, root);
        }
    }
    fclose(data.file);
}
