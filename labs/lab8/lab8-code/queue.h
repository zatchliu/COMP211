/*
 * Fall 2022, COMP 211: Lab 8
 * Structs, pointers and queues
 */

#include <stdbool.h>
#include <stdio.h>

#define MAX_QUEUE_LEN 10

typedef struct queue_header {
    int data[MAX_QUEUE_LEN];
    int front;
    int back;
} queue;

/* You can define a new type using a typedef: this way you can use queue in the
 * same way you would use int, rather than needing to type struct in front.
 * This makes your code cleaner

struct queue_header {
    char data[MAX_QUEUE_LEN];
    int front;
    int back;
};

typedef struct queue_header queue;
*/

// Functions for simple queue implementation using array
void queue_new(queue *Qptr);
bool queue_empty(queue *Qptr);
void enqueue(queue *Qptr, int a);
int dequeue(queue *Qptr);
void queue_print(queue *Qptr);

// Functions for queue implementation using circular array
void queue_new_circ(queue *Qptr);
bool queue_empty_circ(queue *Qptr);
bool queue_full_circ(queue *Qptr);
void enqueue_circ(queue *Qptr, char c);
char dequeue_circ(queue *Qptr);
void queue_print_circ(queue *Qptr);
