#ifndef DECODER_H
# define DECODER_H

# include <stdio.h>
# include <stdlib.h>
# include <string.h>
#include <fcntl.h>
# include <unistd.h>
# include "shared_memory.h"
# define SIZE_TABLE 256
# define COMPRESSED "../files/compressed"
# define C_M_RB "rb"
# define C_M_WB "wb"
# define C_M_R "r"

enum	e_boolean {FALSE, TRUE};

typedef struct node
{
    unsigned char   character;
    int             frequency;
    struct node     *left;
    struct node     *right;
    struct node     *next;
} Node;

typedef struct s_data_compress
{
    int             index;
    int             move;
    unsigned char   one_byte;
    unsigned char   mask;
    char            *encoded;
    FILE            *file;
}   t_data_compress;

typedef struct s_data_decompress
{
    int             index;
    int             fd_out;
    unsigned char   one_byte;
    unsigned char   mask;
    struct node     *curr_node;
    FILE            *file;
}   t_data_decompress;


typedef struct s_semaphore
{
    sem_t   *sem_prod;
    sem_t   *sem_cons;
}   t_semaphore;

//QUEUE
void    enqueue(Node **tail, Node *new_node);
Node    *dequeue(Node **head);
Node    *new_node(char character, int frequency);
Node    *last_node(Node *last);
int     size_queue(Node *head);

//QUEUE UTILS
int     sort_queue(Node **head, int count);
void    add_to_queue(unsigned int *table, Node **head);
void    free_tree(Node *root);

//TREE
void    build_tree(Node **head);

//TABLE
void    generate_frequency_table(unsigned int *table, unsigned char *s);

//DICT
int     get_tree_height(Node *root);
char    **alloc_dict(int columns);
int     is_leaf_node(Node *root);
void    generate_dict(char **dict, Node *root, char *path, int columns);
void	free_dict(char **dict);

//ENCODER
unsigned char    *encoder(unsigned char *str, char **dict);

//DECODER
char    *decoder(unsigned char *encoded, Node *root);

//COMPRESS
void    compress(unsigned char *encoded);

//DECOMPRESS
void    decompress(Node *root, int fd_out);

//COMP_DECOMP_UTILS
FILE    *get_file(char *filename, char *mode_open);

//FILE
int     amount_char_in_file(char *filename);
void    load_file_to_str(char *filename, unsigned char *s);

//SEMAPHORE
t_semaphore create_semaphore (int mode, int permission);
#endif