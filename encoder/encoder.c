#include "encoder.h"

static int get_code_length(unsigned char *str, char **dict)
{
    int len;
    int i;

    len = 0;
    i = -1;
   while (str[++i])
        len+= strlen(dict[str[i]]);
    return (len);
}

unsigned char   *encoder(unsigned char *str, char **dict)
{
    unsigned char    *code;
    int     i;

    code = calloc(get_code_length(str, dict) + 1, sizeof(char));
    i = -1;
    while (str[++i])
        strcat((char *)code, dict[str[i]]);
    return (code);
}
