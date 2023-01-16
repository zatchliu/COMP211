/*
 * Fall 2022, COMP 211: Lab 9
 *
 * Linked lists
 */

#include <stdio.h>
#include <stdlib.h>

#include "list.h"

list create()
{
    list l;
    l.head = NULL;
    return l;
}

bool is_empty(list *l)
{
    if (l->head == NULL){
        return true;
    }
    return false;
}

void insert(list *l, int loc, char c)
{
    node *n = malloc(sizeof(node));
    n->data = c;
    if (is_empty(l) || loc == 0){
        l->head = n;
        n->next =  NULL;
        return;
    }
    node*temp = l-> head;
    int i = 0;
    while(temp->next != NULL && i < loc-1){
        temp = temp->next;
        i++;
    }
    n->next = temp->next;
    temp->next = n;


}

char deletion(list *l, int loc)
{/*
    if(is_empty(l)){
        return;
    }
    node * temp = malloc(sizeof(node));
    while(temp->next != NULL && i < loc-1){
*/
   return -1;
}

char getval(list *l, int loc)
{
   return -1;
}

int size(list *l)
{
   return -1;
}

void print(list *l)
{
    // List is empty, cannot print
    if (is_empty(l)) return;

    // List is not empty, print
    node *node = l->head;
    while (node != NULL) {
        printf("%c ", node->data);
        node = node->next;
    }
    printf("\n");
}
