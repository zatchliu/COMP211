/* Zachary Liu
 * COMP 211, Fall 2022
 * Homework 8
 *
 * Queues
 */

#include <stdbool.h>

/* A singly-linked node type.
 */
struct qnode {
    char key;
    struct qnode *next;
};

typedef struct qnode qnode;

/* A structure that represents a queue.  The queue that is represented is:
 *   FILL IN YOUR DESCRIPTION HERE.
 */
struct queue {

    // FILL IN THIS STRUCTURE DEFINITION.
    // front acts as head of linked list
    qnode* front;
    // back points to addr of last node in list or is set equal to head/front if list is empty
    qnode* back;
    int size;
};

/* **********
 * DO NOT MODIFY ANYTHING BELOW THIS LINE.
 * **********
 */

typedef struct queue queue;

/* is_linear(q) = true if qnode is either NULL or the head of a linear
 * singly-linked list, false otherwise.
 */
bool is_linear(qnode*);

/* create() = q, where q represents the empty queue.
 */
queue create();

/* is_empty(q) = true if q represents the empty queue, false otherwise.
 */
bool is_empty(queue*);

/* enqueue(q, c).
 *
 * Post-condition:  c is added at the end of q.
 *
 * This function must run in O(1) time.
 */
void enqueue(queue*, char);

/* dequeue(q).
 *
 * Pre-condition:  !is_empty(q).
 * Post-condition:  the front element of q is removed.
 *
 * This function must run in O(1) time.
 */
char dequeue(queue*);

/*  size(q) = the number of elements in the queue q.
 *
 *  This function may be O(n) time, where n is the number of elements in q,
 *  but for maximum credit, it must be O(1) time.
 */
int size(queue*);

/* as_array(q, A).
 *
 * Fill A with the elements of q and add a null character at the end.
 * For example, if q is the queue <a, b, c>, then A = "abc".
 *
 * This function will be used to test your code.
 *
 * Pre-condition:  size of A > size of q.
 * Post-condition:  if q is <x_0, x_1, x_2,..., x_{k-1}>, then
 *   A = [x_0, x_1, x_2,...,x_{k-1},'\0',...].
 */
void as_array(queue* q, char A[]);

/* print(q).
 *
 * Print a representation of the queue to the terminal.
 *
 * This function is used only by the driver program.  It will not be used to
 * test your code.
 */
void print(queue*);

