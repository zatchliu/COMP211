/* Zachary Liu
 * COMP 211, Fall 2022
 * Homework 8
 *
 * Queues
 */

#include <assert.h>
#include <stdlib.h>

#include "comp211.h"
#include "hw8.h"

/*  Replace each function body with your definitions.
 */

bool is_linear(qnode *hd) {
    /* Uses two pointers to traverse a linked list
     * Fast travel 2 nodes at a time, while slow travels just one
     * If the pointers meet then there is a loop.
     * If either pointer hits null then is it linear
     */
    if(hd == NULL){
        return true;
    }

    qnode*slow = hd;
    qnode*fast = hd;

    while(fast != NULL){
        slow = slow->next;
        if(fast->next != NULL){
            fast = fast->next->next;
        }else{
            return true;
        }
        if(fast==slow){
            return false;
        }
    }
    return true;
}

queue create() {
    queue q;
    //creating dummy node
    qnode*dum = malloc(sizeof(qnode));
    dum->key = '\0';
    dum->next = NULL;
    //front and back both start off pointing to dummy node
    q.front = q.back = dum;
    q.size = 0;
    return q;
}

bool is_empty(queue *q) {
    // check if linked list is empty
    if(q->front->next == NULL){
        return true;
    }
    return false;
}

// There are no loops and operations are constant so should be O(1)
void enqueue(queue *q, char c) {
    // temp points to current back which is the previous node to where we want to enqueue
    qnode*temp = q->back;
    // create new node
    qnode*n = malloc(sizeof(qnode));
    n->key = c;
    // enqueues new node and points back to the newly inserted node
    q->back = n;
    temp->next = q->back;
    q->size++;
    //assert(is_linear(q->front));
    return;
}

// There are no loops and operations are constant so should be O(1)
char dequeue(queue *q) {
    // nothing to dequeue
    if(is_empty(q)){
        return -1;
    }
    // temp points to front which is the previous node to where we want to dequeue
    qnode*temp = q->front;
    // dequeue node
    qnode*del = temp->next;
    char ans = del->key;
    q->front->next = del->next;
    free(del);
    // resets back when there is only 1 item to dequeue
    if(is_empty(q)){
        q->back = q->front;
    }
    q->size--;
    //assert(is_linear(q->front));
    return ans;
}

// returns size field of queue which should have cost O(1)
int size(queue* q) {
    return q->size;
}

void as_array(queue* q, char A[]) {
    qnode*temp = q->front->next;
    int i = 0;
    while(temp != NULL){
        A[i] = temp->key;
        temp = temp->next;
        i++;
    }
    A[i] = '\0';
    //assert(is_linear(q->front));
    return;
}

void print(queue *q) {
    qnode*temp = q->front->next;
    printf("Q: ");
    while(temp != NULL){
        printf("%c ", temp->key);
        temp = temp->next;
    }
    printf("\n");
}
