/* COMP 211, Fall 2022
 * Lab 12
 *
 * Sets and hash tables
 *
 * IMPORTANT: KEYS YOU ADD SHOULD BE INTEGERS, NOT CHARACTERS
*/

#include <assert.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "set.h"
#include "hash.h"
/*
//Buckets will be singly-linked lists with dummy head nodes.
typedef struct node node;

struct node {
    unsigned int key;
    node *next;
}node;
struct set {
    node *bucket[NUM_BUCKET];
    unsigned int size;
}set;
*/

/*  is_linear(hd) = true,  if hd is the head node of a linear sequence of nodes
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

/*  set_ok(t) = true if t satisfies the invariant specified in the written
 *  assignment.
 */

bool set_ok(set *t) {
    unsigned int sz = 0;

    for (unsigned int b = 0; b < NUM_BUCKET; b++) {
        // Check that each bucket is a linear collection of nodes.
        assert(is_linear(t->bucket[b]->next));

        for (node *n = t->bucket[b]->next; n != NULL; n = n->next) {
            // Check that each node has hash code b.
            assert(hash(n->key) == b);
            sz++;

            // Check that no other node in this bucket has key n->key.
            for (node *p = t->bucket[b]->next; p != NULL; p = p->next) {
                assert(p == n || p->key != n->key);
            }
        }
    }

    // Check that the number of non-dummy nodes is sz.
    assert(sz == t->size);
    return true;
}

set* set_create() {
    set *t = malloc (sizeof(set));
    for (int b = 0; b < NUM_BUCKET; b++) {
        // Create dummy head node for each list
        node *n = malloc (sizeof(node));
        n->key = 0;
        n->next = NULL;
        t->bucket[b] = n;
    }
    t->size = 0;
    return t;
}

unsigned int set_size(set* t) {
    return t->size;
}

bool set_member(set *t, unsigned int key) {
    for (node *n = t->bucket[hash(key)]->next; n != NULL; n = n->next) {
        if (n->key == key) {
            return true;
        }
    }
    return false;
}

void set_add(set *t, unsigned int key) {

    if (set_member(t, key)) return;
    unsigned int h = hash(key);
    node *n = malloc (sizeof(node));
    n->key = key;
    n->next = t->bucket[h]->next;
    t->bucket[h]->next = n;
    t->size = t->size + 1;

    assert(set_ok(t));
}


void set_delete(set *t, unsigned int key) {
    for (node *n = t->bucket[hash(key)]; n->next != NULL; n = n->next) {
        if (n->next->key == key) {
            node *del = n->next;
            n->next = del->next;
            free(del);
            t->size = t->size - 1;
            break;
        }
    }
}

void set_delete_all(set *t) {
    for (int b = 0; b < NUM_BUCKET; ++b) {
        while (t->bucket[b]->next != NULL) {
            node* p = t->bucket[b]->next;
            t->bucket[b]->next = p->next;
            free(p);
        }
    }
    t->size = 0;
}

void set_as_array(set* t, unsigned int xs[]) {
    int i = 0;
    for (unsigned int b = 0; b < NUM_BUCKET; ++b) {
        for (node* n = t->bucket[b]->next; n != NULL; n = n->next) {
            xs[i] = n->key;
            i = i + 1;
        }
    }
    return;
}

void set_print(set *t) {
    for (unsigned int b = 0; b < NUM_BUCKET; b++) {
        for (node *n = t->bucket[b]->next; n != NULL; n = n->next) {
            printf("b = %u, key = %u\n", b, n->key);
        }
    }
}
