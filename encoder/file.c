#include "encoder.h"

int amount_char_in_file(char *filename)
{
    FILE    *file;
    int     count;
    
    file = get_file(filename, C_M_R);
    count = 0;
    while (fgetc(file) != -1)
        count++;
    fclose(file);
    return (count);
}

void    load_file_to_str(char *filename, unsigned char *s)
{
    FILE    *file;
    int     i;
    char    character;

    file = get_file(filename, C_M_R);
    i = 0;
    while (!feof(file))
    {
        character = fgetc(file);
        if (character != -1)
            s[i] = character;
        i++;
    }
    fclose(file);
}
