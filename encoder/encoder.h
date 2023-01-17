#ifndef ENCODER_H
# define ENCODER_H

# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>
# include <stdbool.h>

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

typedef struct s_semaphore
{
    sem_t   *sem_prod;
    sem_t   *sem_cons;
}   t_semaphore;

typedef struct s_encoder_data
{
    struct node     *head;
    unsigned char   *text;
    unsigned char   *encoded;
    unsigned int    table[SIZE_TABLE];
    char            **dict;

}   t_encoder_data;

//QUEUE
void    enqueue(Node **tail, Node *new_node);
Node    *dequeue(Node **head);
Node    *new_node(char character, int frequency);
Node    *last_node(Node *last);
int     size_queue(Node *head);

//QUEUE UTILS
int     sort_queue(Node **head, int count);
void    add_to_queue(unsigned int *table, Node **head);
void	free_queue(Node **head);

//TREE
void    build_tree(Node **head);
int     is_leaf_node(Node *root);

//TABLE
void    generate_frequency_table(unsigned int *table, unsigned char *s);

//DICT
int     get_tree_height(Node *root);
char    **alloc_dict(int columns);
void    generate_dict(char **dict, Node *root, char *path, int columns);
void	free_dict(char **dict);

//ENCODER
unsigned char    *encoder(unsigned char *str, char **dict);

//COMPRESS
void    compress(unsigned char *encoded);

//COMP_DECOMP_UTILS
FILE    *get_file(char *filename, char *mode_open);

//FILE
int     amount_char_in_file(char *filename);
void    load_file_to_str(char *filename, unsigned char *s);

//SEMAPHORE
t_semaphore create_semaphore (int mode, int permission);

//PRINTS
void    print_queue(Node **head);
void    print_tree(Node *head);
void    print_dict(char **dict);
void    print_frequency_table(unsigned int *table);

//UTILS
unsigned char   *get_text(char **argv);
bool            valid_args(int argc);
char            **get_dict(Node *root);
void            init_frequency_table(unsigned int *table);
void            free_tree(Node *root);
#endif