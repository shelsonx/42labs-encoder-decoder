#include "encoder.h"

static void init_data_compress(t_data_compress *data)
{
    data->file = get_file(COMPRESSED, C_M_WB);
    data->index = -1;
    data->move = 7;
    data->one_byte = 0;
}

static void str_to_byte(t_data_compress *data)
{
    data->mask = data->mask << data->move;
    data->one_byte = data->one_byte | data->mask;
}

static void save_and_reset(t_data_compress *data)
{
    fwrite(&data->one_byte, sizeof(unsigned char), 1, data->file);
    data->one_byte = 0;
    data->move = 7;
}

static void save_the_rest(t_data_compress *data)
{
    if (data->move != 7)
        fwrite(&data->one_byte, sizeof(unsigned char), 1, data->file);
}

void    compress(unsigned char *encoded)
{
    t_data_compress data;
    
    init_data_compress(&data);
    while (encoded[++data.index])
    {
        data.mask = 1;
        if (encoded[data.index] == '1')
            str_to_byte(&data);
        data.move--;
        if (data.move < 0)
            save_and_reset(&data);
    }
    save_the_rest(&data);
    fclose(data.file);
}
