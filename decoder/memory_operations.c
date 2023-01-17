#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/ipc.h>
#include <sys/shm.h>

#include "shared_memory.h"

#define IPC_ERROR (-1)

static int get_shared_block(char *filename, int size)
{
    key_t key;

    key = ftok(filename, 0);
    if (key == IPC_ERROR)
        return IPC_ERROR;
    return shmget(key, size, 0644 | IPC_CREAT);
}

unsigned int  *attach_memory_block(char *filename, int size)
{
    int             shared_block_id;
    unsigned int    *result;

    shared_block_id = get_shared_block(filename, size);
    if (shared_block_id == IPC_ERROR)
        return NULL;
    result = (unsigned int *) shmat(shared_block_id, NULL, 0);
    if (result == (unsigned int *) IPC_ERROR)
        return NULL;
    return result;
}

bool detached_memory_block(unsigned int *block)
{
    return (shmdt(block) != IPC_ERROR);
}

bool destroy_memory_block(char *filename)
{
    int shared_block_id;

    shared_block_id = get_shared_block(filename, 0);
    if (shared_block_id == IPC_ERROR)
        return NULL;
    return (shmctl(shared_block_id, IPC_RMID, NULL) != IPC_ERROR);
}
