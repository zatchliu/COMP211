/*
 * Fall 2022, COMP 211: Lab 9
 *
 * Linked lists
 */

#include <stdbool.h>

/* A singly-linked node type.
 */
struct node {
    char data;
    struct node *next;
};

typedef struct node node;

/* A list type
 */
struct list {
    node *head;
};

typedef struct list list;

list create();
bool is_empty(list*);
void insert(list*, int, char);
char deletion(list*, int);
char getval(list*, int);
int size(list*);
void print(list*);
