/* COMP 211, Fall 2022
 * Lab 12
 *
 * Sets and hash tables
 */

#include <assert.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "set.h"
#include "hash.h"

/* Buckets will be singly-linked lists with dummy head nodes.
 */
typedef struct node node;

struct node {
    unsigned int key;
    node *next;
};

struct set {
    node *buckets[NUM_BUCKET];
    unsigned int size;
};


/*  is_linear(hd) = true,  if hd head node of linear sequence of nodes
 *                  false, otherwise.
 */
bool is_linear(node *hd) {
    if (hd == NULL) return true;

    node *tort = hd;
    node *hare = hd;

    while (hare != NULL && hare->next != NULL) {
        hare = hare->next->next;
        tort = tort->next;
        if (hare == tort) {
            return false;
        }
    }
    return true;
}

/*  set_ok(t) = true if t satisfies invariant
 */
bool set_ok(set *t) {
    unsigned int sz = 0;
    for (unsigned int b = 0; b < NUM_BUCKET; b++) {
        /* Check each bucket is linear collection of nodes */
        assert(is_linear(t->buckets[b]->next));

        for (node *n = t->buckets[b]->next; n != NULL; n = n->next) {
            /* Check each node has hash code b */
            assert(hash(n->key) == b);
            sz++;

            /* Check no other node in bucket has key n->key */
            for (node *p = t->buckets[b]->next; p != NULL; p = p->next) {
                assert(p == n || p->key != n->key);
            }
        }
    }
    /* Check that number of non-dummy nodes is sz */
    assert(sz == t->size);
    return true;
}

set* set_create() {
    set *t = malloc (sizeof(set));

    //  INIT SET HERE
    for (int i = 0; i<=NUM_BUCKET; i++){
        list*l = list_create();
        s->bucket[i] = l
    }
    s->size = 0;

    return t;
}

unsigned int set_size(set* t) {
    return 0;
}

bool set_member(set *t, unsigned int key) {
    for (node*n=s->bucket[hash(key)->head->next; n!=NULL; n=n->next]){
        if(n->val==key){
            return true;
        }
    }
    return false;
}

void set_add(set *t, unsigned int key) {
    if(set_member(t, key)){
        return;
    }
    int h = hash(key);
    node*n = malloc(sizeof(node));
    n->key = key;
    n->next = s->bucket[h]->head->next;
    s->bucket->head->next = n;
}

void set_delete(set *t, unsigned int key) {
    if(!set_member(t,key)){
        return;
    }
    int h = hash(key);
    node*del = s->bucket[h]->head;

}

void set_delete_all(set *t) {
}

void set_as_array(set* t, unsigned int A[]) {
    int i = 0;
    for (unsigned int b = 0; b < NUM_BUCKET; ++b) {
        for (node* n = t->buckets[b]->next; n != NULL; n = n->next) {
            A[i] = n->key;
            i++;
        }
    }
}

void set_print(set *t) {
    for (unsigned int b = 0; b < NUM_BUCKET; b++) {
        for (node *n = t->buckets[b]->next; n != NULL; n = n->next) {
            printf("b = %u, key = %u\n", b, n->key);
        }
    }
}
