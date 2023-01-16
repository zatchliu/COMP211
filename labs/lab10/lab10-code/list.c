/* COMP 211, Fall 2022
 * Lab10
 *
 * Dummy head nodes and doubly linked lists
 */

#include <stdio.h>
#include <stdlib.h>

#include "list.h"

//===============================================================
//
// Singly-linked list functions
//
//===============================================================
list create() {

    // Create dummy head node
    node *n = (node*)malloc(sizeof(node));
    n->data = '\0';
    n->next = NULL;

    // Add dummy head node to head of list
    list l;
    l.head = n;
    return l;
}

bool is_empty(list *l) {

    if (l->head->next == NULL) {
        return true;
    }
    return false;
}

void insert(list *l, int loc, char c) {

    // Create new node to add
    node *n = (node*)malloc(sizeof(node));
    n->data = c;

    // Insert node

    // FILL THIS OUT
    int i = 0;
    node*temp = l->head;
    while(temp->next != NULL && i < loc){
        temp = temp->next;
        i++;
    }
    n->next = temp->next;
    temp->next = n;


}

char deletion(list *l, int loc) {

    // Nothing to delete

    if(is_empty(l)){
        return -1;
    }


    // Delete node

    // FILL THIS OUT
    node*temp = l->head;
    int i = 0;
    while(temp->next != NULL && i<loc){
        temp = temp->next;
        i++;
    }
    if(temp->next == NULL){
        return -1;
    }
    node*del = temp->next;
    char ans = del->data;
    temp->next = del->next;
    free(del);

    return ans;
}

char getval(list *l, int loc) {

    // FILL THIS OUT
    int i = 0;
    node*temp = l->head;
    while(temp-> next != NULL && i<loc){
        temp = temp->next;
        i++;
    }
    return temp->next->data;

}

int size(list *l) {
    int count = 0;
    node*temp = l->head;
    while(temp->next != NULL){
        temp = temp->next;
        count++;
    }

    // FILL THIS OUT

    return count;
}

void print(list *l) {

    node *node = l->head->next;
    while (node != NULL) {
        printf("%c ", node->data);
        node = node->next;
    }
    printf("\n");
}

//===============================================================
//
// Doubly-linked list functions
//
//===============================================================
dlist dlist_create() {

    // Create dummy head node
    dnode *n1 = (dnode*)malloc(sizeof(dnode));
    n1->data = '\0';
    n1->prev = NULL;

    // Create dummy tail node
    dnode *n2 = (dnode*)malloc(sizeof(dnode));
    n2->data = '\0';
    n2->next = NULL;

    // Connect up head and tail
    n1->next = n2;
    n2->prev = n1;

    // Add dummy head node to head of list
    dlist l;
    l.head = n1;
    l.tail = n2;
    return l;
}

bool dlist_is_empty(dlist *l) {

    if (l->head->next->next == NULL) {
        return true;
    }
    return false;
}

void dlist_insert(dlist *l, int loc, char c) {

    // Create new node to add
    dnode *n = (dnode*)malloc(sizeof(dnode));
    n->data = c;

    // Insert node

    // FILL THIS OUT
    int i = 0;
    dnode*temp = l->head;
    while(temp->next-> != NULL && i < loc){
        temp = temp->next;
        i++;
    }
    n->next = temp->next;
    temp->next = n;
    n->next->prev = n;
    n->prev = temp;


}

char dlist_deletion(dlist *l, int loc) {

    // Nothing to delete

    // FILL THIS OUT
    if(dlist_is_empty){
        return -1;
    }

    // Delete node

    // FILL THIS OUT
    dnode*temp = l->head;
    int i = 0;
    while(temp->next->next != NULL && i<loc){
        temp = temp->next;
        i++;
    }
    if(temp->next == NULL){
        return -1;
    }
    dnode*del = temp->next;
    char ans = del->data;
    temp->next = del->next;
    del->next->prev = temp;
    free(del);

    return ans;

}

char dlist_getval(dlist *l, int loc) {

    // FILL THIS OUT
    return -1;
}

int dlist_size(dlist *l) {

    // FILL THIS OUT

    return -1;
}

void dlist_print(dlist *l) {

    // Print list forwards
    printf("printing list forwards\n");
    dnode *node = l->head->next;
    while (node->next != NULL) {
        printf("%c ", node->data);
        node = node->next;
    }
    printf("\n");

    // Print list backwards
    printf("printing list backwards\n");
    node = l->tail->prev;
    while (node->prev != NULL) {
        printf("%c ", node->data);
        node = node->prev;
    }
    printf("\n");
}
