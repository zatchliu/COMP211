/* Zachary Liu
 * COMP 211, Fall 2022
 * Homework 9
 *
 * Linked lists and an editor buffer
 */

#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "comp211.h"
#include "hw9.h"

/* empty = an empty buffer.
 */
struct buffer *empty(void) {
    // create dummy head node
    struct node*dumHead = malloc(sizeof(struct node));
    dumHead->data = '\0';
    dumHead->prev = NULL;

    // create dummy tail node
    struct node*dumTail = malloc(sizeof(struct node));
    dumTail->data = '\0';
    dumTail->next = NULL;

    // connect up head and tail
    dumHead->next = dumTail;
    dumTail->prev = dumHead;

    // create buffer sets inital position of insertion point to dummy tail
    struct buffer*buf = malloc(sizeof(struct buffer));
    buf->head = dumHead;
    buf->tail = buf->insertPoint = dumTail;
    buf->size = 0;
    return buf;
}

/* is_linear(hd) checks if the linked list is linear going forwards
 */
bool is_linear_forward(struct buffer*buf){
    struct node*hd = buf->head->next;
    if(hd==buf->tail) return true;

    //checking linearity going forward
    struct node*slow = hd;
    struct node*fast = hd;
    while(fast != buf->tail && fast->next->next != buf->tail){
        slow = slow->next;
        if(fast->next != buf->tail){
            fast = fast->next->next;
        }else{
            return true;
        }
        if(fast == slow){
            return false;
        }
    }
    return true;
}

/*checks if the linked list is linear going backwards
 */
bool is_linear_backwards(struct buffer*buf){
    struct node*tl = buf->tail->prev;
    if(tl==buf->head) return true;

    //checking linearity going backwards
    struct node*slow = tl;
    struct node*fast = tl;
    while(fast != buf->head && fast->prev->prev != buf->head){
        slow = slow->prev;
        if(fast->prev != buf->head){
            fast = fast->prev->prev;
        }else{
            return true;
        }
        if(fast == slow){
            return false;
        }
    }
    return true;
}

/* check_node(buf) checks if every node satisfies back-and-forth property
 */
bool check_node(struct buffer*buf){
    struct node*temp = buf->head->next;
    while(temp != NULL){
        if(temp->prev->next != temp) return false;
        temp = temp->next;
    }
    return true;
}

/*buf_ok(buf) checks if buf is a valid buffer
 */
bool buf_ok(struct buffer*buf){
    assert(buf->size >= 0);
    assert(is_linear_backwards(buf));
    assert(is_linear_forward(buf));
    assert(check_node(buf));
    assert(buf->insertPoint != buf->head && buf->insertPoint != NULL);
    return true;
}

/* insert(buf, c) inserts c to the left of the insertion point of buf.  After
 * the insertion, the insert mark is to the right of c.
 */
void insert(struct buffer *buf, char c) {
    //create new node
    struct node*n = malloc(sizeof(struct node));
    n->data = c;

    //inserts node to left of insertion point of buf
    n->next = buf->insertPoint;
    n->prev = buf->insertPoint->prev;
    buf->insertPoint->prev->next = n;
    buf->insertPoint->prev = n;
    buf->size++;
    assert(buf_ok(buf));

}

/* delete_left(buf) deletes the character to the left of the insert mark.  If
 * there is no character to the left of the insert mark, this function has no
 * effect.
 */
void delete_left(struct buffer *buf) {
    // handles case when insertion is at very beginning
    if(buf->insertPoint->prev->prev == NULL){
        return;
    }

    // delete left node
    struct node*del = buf->insertPoint->prev;
    del->prev->next = buf->insertPoint;
    buf->insertPoint->prev = del->prev;
    free(del);
    buf->size--;
    assert(buf_ok(buf));
}

/* delete_right(buf) deletes the character to the right of the insert mark.  If
 * there is no character to the right of the insert mark, this function has no
 * effect.
 */
void delete_right(struct buffer *buf) {
    // handles case when insertion is at the end
    if(buf->insertPoint->next == NULL){
        return;
    }

    //delete right node
    struct node*del = buf->insertPoint;
    del->prev->next = del->next;
    del->next->prev = del->prev;
    buf->insertPoint = buf->insertPoint->next; //moving insertion point to right
    free(del);
    buf->size--;
    assert(buf_ok(buf));
}

/* move_left(buf) moves the insert mark one character to the left.  If there is
 * no character to the left of the insert mark, this functdion has no effect.
 */
void move_left(struct buffer *buf) {
    // Handles case when insert point is at the very beginning
    if (buf->insertPoint->prev->prev == NULL){
        return;
    }
    buf->insertPoint = buf->insertPoint->prev; //moves insert point left
    assert(buf_ok(buf));
}

/* move_right(buf) moves the insert mark one character to the right.  If there
 * is no character to the right of the insert mark, this functdion has no
 * effect.
 */
void move_right(struct buffer *buf) {
    //handles case when insertion is at the end
    if (buf->insertPoint->next == NULL){
        return;
    }
    buf->insertPoint = buf->insertPoint->next; // moves insert point right
    assert(buf_ok(buf));
}

/* set(buf, n) sets the insert mark so that it is to the left of the n-th
 * character.  Characters are 0-indexed, so set(buf, 0) sets the insert mark to
 * the beginning of the buffer.  n may be equal to the length of the buffer; in
 * this case, the insert mark is set to the right of the last character.
 *
 * Pre-condition:  0 <= n <= len(buf).
 */
void set(struct buffer *buf, int n) {
    assert(n <= buf->size && n >= 0);
    struct node*temp = buf->head;
    int i = 0;

    //looping to new insertion point
    while(temp->next->next != NULL && i < n){
        temp = temp->next;
        i++;
    }
    buf->insertPoint = temp->next; //sets new insertion point
    assert(buf_ok(buf));
}

/* contents(buf) = c, where c->left is the string to the left of the insert
 * mark and c->right is the string to the right of the insert mark.
 */
struct buffer_contents *contents(struct buffer *buf) {
    /* calloc initializes memory to 0 */
    struct buffer_contents* cnt = calloc(1, sizeof(struct buffer_contents));

    // finding the length of the left side
    struct node*leftSide = buf->head;
    int a = 0; // a is the length of the left side
    while(leftSide->next != buf->insertPoint){
        leftSide = leftSide->next;
        a++;
    }

    // finding the length of the right side
    struct node*rightSide = buf->insertPoint;
    int b = 0; // b is the length of the right side
    while(rightSide->next != NULL){
        b++;
        rightSide = rightSide->next;
    }

    cnt->left = calloc(a, sizeof(char));
    cnt->right = calloc(b, sizeof(char));

    //creating temp nodes for left and right
    struct node*l = buf->head->next;
    struct node*r = buf->insertPoint;

    // copying elements left of insertion into cnt->left
    int i = 0;
    while(l != r){
        cnt->left[i] = l->data;
        l = l->next;
        i++;
    }
    cnt->left[i] = '\0';

    // copying elements right of insertion into cnt->right
    int j = 0;
    while(r != buf->tail){
        cnt->right[j] = r->data;
        r = r->next;
        j++;
    }
    cnt->right[j] = '\0';
    return cnt;
}
