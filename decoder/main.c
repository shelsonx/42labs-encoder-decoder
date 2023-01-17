#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "decoder.h"

void    make_decompress(unsigned int *block)
{
    Node    *head;
    int     outfile;

    head = NULL;
    outfile = open("../files/out", O_WRONLY | O_CREAT | O_TRUNC, 0777);
    add_to_queue(block, &head);
    sort_queue(&head, size_queue(head));
    build_tree(&head);
    outfile = open("../files/out", O_WRONLY | O_CREAT | O_TRUNC, 0777);
    decompress(head, outfile);
    close(outfile);
    free_tree(head);
}

int main(void)
{
    t_semaphore     semaphore;
    unsigned int    *block;
    
    sem_unlink(SEM_CONSUMER_FNAME);
    sem_unlink(SEM_PRODUCER_FNAME);
    semaphore = create_semaphore(O_CREAT, 0600);

    block = (unsigned int *) attach_memory_block(FILENAME, BLOCK_SIZE);
    printf("Read to received compressed data: \n"); 
    sem_wait(semaphore.sem_prod);
    printf("\nDecompress and send to ../files/out\n");
    make_decompress(block);
    sem_post(semaphore.sem_cons);
    sem_close(semaphore.sem_cons);
    sem_close(semaphore.sem_prod);
    detached_memory_block(block);
    return 0;
}
