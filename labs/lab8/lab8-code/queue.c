/*
 * Fall 2022, COMP 211: Lab 8
 * Structs, pointers and queues
 *
 * This file implements functions required for queue operations
 */
#include "queue.h"

//-----------------------------------------------------------------
// Functions for simple queue implementation using array
//-----------------------------------------------------------------
void queue_new(queue *Qptr)
{
    Qptr->front = 0;
    Qptr->back = 0;
}

bool queue_empty(queue *Qptr)
{
    if (Qptr->front ==0 && Qptr->back == 0){
        printf("Queue is empty\n");
        return true;
    }
    printf("Queue is not empty\n");
    return false;
}

void enqueue(queue *Qptr, int a){
    if(Qptr->back == MAX_QUEUE_LEN){
        printf(" Error: out of space in queue\n");
        return;
    }
    Qptr->data[Qptr->back] = a;
    Qptr->back++;
    printf("Adding element %d to queue\n", a);
}

int dequeue(queue *Qptr){
    if(queue_empty(Qptr)){
        printf("Error: queue is empty, cannot remove element from queue\n");
        return -1;
    }
    int ans = Qptr->front;
    printf("Dequeueing element %d from queue\n", ans);
    for (int i = 0; i < Qptr->back - 1; i++){
        Qptr->data[i] = Qptr->data[i+1];
    }
    Qptr->back--;
    return ans;
}

void queue_print(queue *Qptr){
    printf("Queue length is %d with contents: ", Qptr->back);
    for (int i = 0; i < Qptr->back; i++){
        printf(" %d", Qptr->data[i]);
    }
    printf("\n");

}

//-----------------------------------------------------------------
// Functions for queue implementation using circular array
//-----------------------------------------------------------------
void queue_new_circ(queue *Qptr)
{
    Qptr->front = 0;
    Qptr->back = 0;
}

bool queue_empty_circ(queue *Qptr)
{
    if(Qptr->front==Qptr->back){
        printf("Queue is empty\n");
        return true;
    }
    printf("Queue is NOT empty\n");
    return false;
}

bool queue_full_circ(queue *Qptr)
{
    if(Qptr->back==-1){
        printf("Queue is full\n");
        return true;
    }
    printf("Queue is NOT full");
    return false;
}

void enqueue_circ(queue *Qptr, char c)
{
    if(queue_full_circ(Qptr)){
        printf("Error: queue is full, cannot add element %c to queue\n", c);
        return;
    }
    printf("Adding element %c to queue\n", c);
    Qptr->data[Qptr->back] = c;
    Qptr->back = (Qptr->back+1) % MAX_QUEUE_LEN; //circles through array
    if(Qptr->back == Qptr->front){
        Qptr->back = -1; //if back circles back to front, then array is full
    }
    
}

char dequeue_circ(queue *Qptr)
{
    char ans = Qptr->data[Qptr->front];
    if(queue_empty_circ(Qptr)){
        printf("Error: queue is empty, cannot remove element from queue\n");
        return '\0';
    }
    printf("Dequeueing element %c from queue\n", Qptr->data[Qptr->front]);
    if(Qptr->back==-1){ //since element is being dequeued, queue is no longer full
        Qptr->back = Qptr->front;
    }
    Qptr->front++;
    return ans;
}

int get_qlen_circ(queue *Qptr)
{
  if(queue_full_circ(Qptr)){
    return MAX_QUEUE_LEN;
  }else if(queue_empty_circ(Qptr)){
    return 0;
  }else if(Qptr->front < Qptr->back){
    return Qptr->back - Qptr->front;
  }else{
    return ((MAX_QUEUE_LEN - Qptr->front) + Qptr->back);
  }
}

void queue_print_circ(queue *Qptr)
{
    int qlen = get_qlen_circ(Qptr);
    printf("\nQueue contents: \n");

    int j = 0;
    for (int i = 0; i < qlen; i++) {
        if (Qptr->front < Qptr->back) {
            j = Qptr->front + i;
        } else {
            if (i < (MAX_QUEUE_LEN - Qptr->front)) {
                j = Qptr->front + i;
            } else if (i == (MAX_QUEUE_LEN - Qptr->front)) {
                j = 0;
            } else {
                j++;
            }
        }
        printf("Q[%d]=%c ", j, Qptr->data[j]);
    }
    printf("\n\n");
}

