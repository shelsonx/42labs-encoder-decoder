#include "encoder.h"

t_semaphore create_semaphore (int mode, int permission)
{
    t_semaphore semaphore;

    semaphore.sem_prod = sem_open(SEM_PRODUCER_FNAME, mode, permission, 0);
    if (semaphore.sem_prod == SEM_FAILED)
    {
        perror("sem_open/producer");
        exit(EXIT_FAILURE);
    }
    semaphore.sem_cons = sem_open(SEM_CONSUMER_FNAME, mode, permission, 1);
    if (semaphore.sem_cons == SEM_FAILED)
    {
        perror("sem_open/consumer");
        exit(EXIT_FAILURE);
    }
    return (semaphore);
}
