#ifndef SHARED_MEMORY_H
#define SHARED_MEMORY_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/sem.h>

#include <sys/types.h>
#include <sys/stat.h>
#include <sys/shm.h>

#include <fcntl.h>
#include <sys/mman.h>

#include <unistd.h>
#include <sys/types.h>

#include <stdbool.h>
#include <semaphore.h>
#include <sys/sem.h>


unsigned int  *attach_memory_block(char *filename, int size);
bool detached_memory_block(unsigned int *block);
bool destroy_memory_block(char *filename);

#define BLOCK_SIZE 4096
#define FILENAME "/bin/ls"

#define SEM_PRODUCER_FNAME "/prod"
#define SEM_CONSUMER_FNAME "/cons"
#endif