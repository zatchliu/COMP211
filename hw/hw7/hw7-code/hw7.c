/* Zachary Liu
 * COMP 211, Fall 2022, Wesleyan University
 * Homework #7
 *
 * More arrays
 */

#include <assert.h>
#include <stdbool.h>
#include <stdio.h>

#include "hw7.h"

buffer empty()
{
    buffer b;
    b.cursor = 0;
    b.back = 0;
    return b;
}

bool buf_ok(buffer* b){
    if ((b->cursor >=0 && b->cursor<=BUF_LEN) && (b->back>=0 &&b->back<=BUF_LEN)){
        return true;
    }
    return false;
}

void swap(buffer* b, int i, int j){
    int temp = b->values[i];
    b->values[i] = b->values[j];
    b->values[j] = temp;
}


void insert(buffer* b, char c)
{
    if(b->back == BUF_LEN){
        printf("Buffer out of space\n");
        return;
    }
    if(b->cursor == b->back+1){
        b->values[b->back] = c;
        b->back++;
        b->cursor++;
        return;
    }
    if(b->back == 0){
        b->values[0] = c;
        b->cursor++;
        b->back++;
        return;
    }
    int temp = b->cursor;
    for (int i = b->cursor; i < b->back; i++){
        swap(b, temp, i+1);
    }
    b->values[b->cursor] = c;
    b->cursor++;
    b->back++;
}

void delete_left(buffer* b)
{
    if(b->cursor == 0){
        return;
    }
    for (int i = b->cursor-1; i < b->back-1; i++){
        b->values[i] = b->values[i+1];
    }
    b->back--;
    b->cursor--;
    assert(buf_ok(b));
    return;
}

void delete_right(buffer* b)
{
    if (b->cursor == b->back){
        return;
    }
    for (int i = b->cursor; i < b->back-1; i++){
        b->values[i] = b->values[i+1];
    }
    b->back--;
    assert(buf_ok(b));
    return;
}

void move_left(buffer* b)
{
    if(b->cursor == 0){
        return;
    }
    b->cursor--;
    assert(buf_ok);
    return;
}

void move_right(buffer* b)
{
    if(b->cursor == b->back){
        return;
    }
    b->cursor++;
    assert(buf_ok);
    return;
}

void set(buffer* b, int n)
{
    b->cursor = n;
    assert(buf_ok);
    return;
}

void contents(buffer* b, char left[], char right[])
{
    left[b->cursor] = '\0';
    right[b->back - b->cursor] = '\0';
    for(int i = 0; i < b->cursor; i++){
        left[i] = b->values[i];
    }
    int j = 0;
    for(int i = b->cursor; i< b->back; i++){
        right[j] = b->values[i];
        j++;
    }
}

void print_buffer(buffer* b)
{
    for(int i = 0; i < BUF_LEN; i++){
        printf("%c ", b->values[i]);
    }
    printf("\n");
}
