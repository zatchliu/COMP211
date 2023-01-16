/* COMP 211, Fall 2022
 * Lab 12
 *
 * Sets and hash tables
 */

#include <stdbool.h>

#define NUM_BUCKET 101

/* The set type.
 *
 * A set represents a finite mathematical set of unsigned integers.
 *
 *
typedef struct node{

}
typedef struct list{
    node*head;
}list;

typedef struct set{
    list*bucket[NUM_BUCKET];
    unsigned int size = 0;
} set;
*/

/* Buckets will be singly-linked lists with dummy head nodes.
 */
//typedef struct node node;

typedef struct node {
    unsigned int key;
    struct node *next;
}node;

/*  Invariant:  see written solutions.
 */
typedef struct set {
    node *bucket[NUM_BUCKET];
    unsigned int size;
}set;

/* set_create() = s, where s is the empty set.
 */
set* set_create();

/*  set_size(s) = the number of elements in s.
 *
 *  For full credit, this function must be constant-time.
 */
unsigned int set_size(set* s);

/*  set_member(s, x) = true,  if x is an element of s
 *                   = false, otherwise.
 */
bool set_member(set* s, unsigned int key);

/*  set_add(s, x).
 *
 *  Post-condition:  x is a member of s.
 *
 *  If x is a member of s when this function is called, then this function has
 *  no effect.
 */
void set_add(set* s, unsigned int key);

/*  set_delete(s, x).
 *
 *  Post-condition:  x is not a member of s.
 *
 *  If x is not a member of s when this function is called, then this function
 *  has no effect.
 */
void set_delete(set* s, unsigned int key);

/*  set_delete_all(s).
 *
 *  Post-condition:  s represents the empty set.
 */
void set_delete_all(set* s);

/*  set_as_array(s, xs).
 *
 *  Pre-condition:  xs has size at least set_size(s).
 *
 *  Post-condition:  s = {xs[0],...,xs[set_size(s) - 1]}.  Informally:  xs
 *  is filled with the elements of s.  xs may be filled in any order.
 *
 */
void set_as_array(set* s, unsigned int xs[]);

/*  set_print(s).
 *
 *  Post-condition:  A representation of s is printed to the terminal.
 *
 *  This function is for your use only.  We will not use set_print in testing
 *  your implementation.
 */
void set_print(set* s);

/*  The dictionary type.
 *
 *  A dictionary is a function from unsigned integer keys to character values.
 *  We think of a dictionary as a set of key-value pairs (k, v), where k is
 *  an unsigned integer and v a char.  For a given key k, there is at most
 *  one key-value pair of the form (k, v) in a dictionary.
 */
typedef struct dict dict;

/*  dict_create() = d, where d represents the empty dictionary (no keys).
 */
dict* dict_create();

/*  dict_size(d) = the number of key-values pairs in d.
 */
unsigned int dict_size(dict *t);

/*  dict_find(d, k) = true,  if there is a key-value pair (k, v) in d for
 *                           some v.
 *                  = false, otherwise.
 */
bool dict_find(dict *t, unsigned int key);

/*  dict_getval(d, k) = v, where (k, v) is in d.
 *
 *  Pre-condition:  there is some pair of the form (k, v) in d.
 */
char dict_getval(dict *t, unsigned int key);

/*  dict_add(d, k, v).
 *
 *  Post-condition:  the key-value pair (k, v) is added to d.  If there
 *  is already a key-value pair with key k in d, it is replaced with (k, v).
 */
void dict_add(dict *t, unsigned int key, char value);

/*  dict_delete(d, k).
 *
 *  Post-condition:  there is no key-value pair of the form (k, v) for any v
 *  in d.  If there is no such key-value pair in d when this function is called,
 *  this function has no effect.
 */
void dict_delete(dict *t, unsigned int key);

/*  dict_keys(d, ks).
 *
 *  Post-condition:  the keys of d are {ks[0],...,ks[dict_size(d)-1]}.
 *  Informally:  ks is filled with the keys of d.  ks may be filled in
 *  any order.
 */
void dict_keys(dict *t, unsigned int ks[]);

/*  dict_delete_all(d).
 *
 *  Post-condition:  d is the empty dictionary (i.e., all key-value pairs are
 *  removed from d).
 */
void dict_delete_all(dict *d);

/*  dict_as_array(s, ks).
 *
 *  Pre-condition:  ks has size at least dict_size(s).
 *
 *  Post-condition:  the keys of d is {ks[0],...,ks[dict_size(s) - 1]}.
 *  Informally:  ks is filled with the keys of d.  ks may be filled in
 *  any order.
 */
void dict_as_array(dict* s, unsigned int ks[]);

/*  dict_print(d).
 *
 *  Post-condition:  A representation of d is printed to the terminal.
 *
 *  This function is for your use only.  We will not use dict_print in testing
 *  your implementation.
 */
void dict_print(dict *t);

/* hash(k).
 */
unsigned int hash(unsigned int key);
