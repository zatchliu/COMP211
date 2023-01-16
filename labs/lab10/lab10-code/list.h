/* COMP 211, Fall 2022
 * Lab10
 *
 * Dummy head nodes and doubly linked lists
 */

#include <stdbool.h>

// Singly-linked node type
struct node {
    char data;
    struct node *next;
};

typedef struct node node;

// Singly-linked list type
struct list {
    // Initialize head to dummy node in create()
    node *head;
};

typedef struct list list;

// Doubly-linked node type
struct dnode {
    char data;
    struct dnode *next;
    struct dnode *prev;
};

typedef struct dnode dnode;

// Doubly-linked List type
struct dlist {
    // Initialize head and tail to dummy nodes in create()
    dnode *head;
    dnode *tail;
};

typedef struct dlist dlist;

// Singly-linked list functions
list create();
bool is_empty(list*);
void insert(list*, int, char);
char deletion(list*, int);
char getval(list*, int);
int size(list*) ;
void print(list*);

// Doubly-linked list functions
dlist dlist_create();
bool dlist_is_empty(dlist*);
void dlist_insert(dlist*, int, char);
char dlist_deletion(dlist*, int);
char dlist_getval(dlist*, int);
int dlist_size(dlist*) ;
void dlist_print(dlist*);
