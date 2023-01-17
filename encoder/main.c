#include "encoder.h"

void    init_encoder_data(t_encoder_data *data, char **argv)
{
    data->head = NULL;
    data->text =  get_text(argv);
    init_frequency_table(data->table);
    generate_frequency_table(data->table, data->text);
}

void    exit_encoder_data(t_encoder_data *data)
{
    free(data->encoded);
    free_dict(data->dict);
    free(data->text);
    free_tree(data->head);
}

void    make_tree(t_encoder_data *data)
{
    add_to_queue(data->table, &data->head);
    sort_queue(&data->head, size_queue(data->head));
    build_tree(&data->head);
}

void    make_compress(t_encoder_data *data)
{
    data->dict = get_dict(data->head);
    data->encoded = encoder(data->text, data->dict);
    compress(data->encoded);
}

int main(int argc, char **argv)
{

    t_encoder_data  data;
    t_semaphore     semaphore;
    unsigned int    *block;

    if(!valid_args(argc))
        return (1);
    init_encoder_data(&data, argv);
    make_tree(&data);
    make_compress(&data);
    semaphore = create_semaphore(0, 0);
    block = (unsigned int *) attach_memory_block(FILENAME, BLOCK_SIZE);
    sem_wait(semaphore.sem_cons);
    memcpy(block, data.table, sizeof(int *) * SIZE_TABLE); 
    sem_post(semaphore.sem_prod);
    sem_close(semaphore.sem_cons);
    sem_close(semaphore.sem_prod);
    detached_memory_block(block);
    exit_encoder_data(&data);
    return (0);
}
