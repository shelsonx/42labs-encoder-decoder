#include "encoder.h"

void    generate_frequency_table(unsigned int *table, unsigned char *s)
{
    int i;

    i = -1;
    while (s[++i] != '\0')
        table[s[i]]++;
}
