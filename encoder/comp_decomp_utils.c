#include "../encoder/encoder.h"

FILE    *get_file(char *filename, char *mode_open)
{
    FILE    *file = fopen(filename, mode_open);
    
    if (!file)
        perror("");
    return (file);
}
