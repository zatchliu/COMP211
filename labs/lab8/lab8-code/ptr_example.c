/*
 * Fall 2022, COMP 211: Lab 8
 *
 * This file gives examples of working with pointers
 */

#include <stdio.h>

struct time {
  unsigned int hour;
  unsigned int minute;
  double second;
};

// Swap function with pointers (addresses) as parameters rather than values
void swap(int *p1, int *p2)
{
    int temp = *p1;
    *p1 = *p2;
    *p2 = temp;
}

// Here we are creating a new struct t containing the values of struct passed
// Unlike arrays, this is really creating a copy of the struct
void add_seconds(struct time t, double s)
{
    t.second += s;
    printf("2. seconds = %0.5f\n", t.second);
}

// Here we are passing a pointer to our struct, storing the address in t
void add_seconds_ptr(struct time *t, double s)
{
    (*t).second += s;
    printf("4. seconds = %0.5f\n", (*t).second);
}

int main()
{
    //------------------------------------------------------------------------
    // Pointers
    //------------------------------------------------------------------------

    // Declaration of variable of type int pointer.  I.e. p is a pointer to a
    // variable of type int, indicated by the use of * before p.
    int *p;

    // Declaration of variable of type int.
    int v = 5;

    // Assign address of v to be the value of pointer variable p. Putting an &
    // in front of a variable name returns the address where the variable
    // is located in memory.
    p = &v;

    // Example printout:
    // v = 5, &v = 0x7fff507d39bc, p = 0x7fff507d39bc &p = 0x7fff507d39c0, *p = 5
    printf("\n1. v = %d, &v = %p, p = %p &p = %p, *p = %d \n", v, &v, p, &p, *p);

    // Access memory location of variable that p is pointing at by putting * in
    // front of p.  Since p contains the address of v, then *p accesses the
    // memory where the value of v is stored. Here, we are assigning the value
    // of 10 to this memory location. Because  this  memory  location is the
    // memory where the value of v is stored, we are actually changing the
    // value of v to 10.
    *p = 10;

    // Example printout:
    // v = 10, &v = 0x7fff507d39bc, p = 0x7fff507d39bc, &p = 0x7fff507d39c0, *p = 10
    printf("2. v = %d, &v = %p, p = %p, &p = %p, *p = %d \n\n", v, &v, p, &p, *p);

    //------------------------------------------------------------------------
    // Pointers and function arguments
    //------------------------------------------------------------------------

    int v1 = 3, v2 = 5;

    // Example printout:  v1 = 3, v2 = 5
    printf("1. v1 = %d, v2 = %d\n", v1, v2);

    // Swap function that takes addresses as parameters
    swap (&v1, &v2);

    // Example printout: v1 = 5, v2 = 3
    printf("2. v1 = %d, v2 = %d\n\n", v1, v2);

    //------------------------------------------------------------------------
    // Pointers and arrays
    //------------------------------------------------------------------------

    // Recall that the value of an array is an address, so when we pass an
    // array to a function, we are always passing the address, we are not
    // making a copy of the array.  Arrays are the only data type in C for
    // which this is true.
    int vs[10];
    vs[3] = 3;

    // Store address of first element of array in p.
    p = &vs[0];

    // Assign 0 to memory location at address stored in p. Effectively assigns
    // the value of 0 to vs[0].
    *p = 0;

    // Example printout: vs[0] = 0, vs[3] = 3, p = 0x7fff5363f9a0, vs = 0x7fff5363f9a0
    printf("1. vs[0] = %d, vs[3] = %d, p = %p, vs = %p\n", vs[0], vs[3], p, vs);

    // Swap function that takes addresses as parameters
    swap(p, &vs[3]);

    // Example printout: vs[0] = 3, vs[3] = 0, p = 0x7fff5363f9a0, vs = 0x7fff5363f9a0
    printf("2. vs[0] = %d, vs[3] = %d, p = %p, vs = %p\n\n", vs[0], vs[3], p, vs);

    //------------------------------------------------------------------------
    // Pointers and structs
    //------------------------------------------------------------------------

    struct time class_start = {10, 20, 0.0};
    struct time class_end;
    class_end.second = 0.0;
    class_end.minute = 40;
    class_end.hour = 11;

    printf("%p\n", &class_start);
    printf("%d\n", class_start); // this is value of first variable in struct
    printf("%p\n", &class_start.hour);
    printf("%p\n", &class_start.second);
    printf("%p\n", &class_start.minute);

    printf("1. seconds = %0.5f\n", class_start.second);
    add_seconds(class_start, 10);
    printf("3. seconds = %0.5f\n", class_start.second);
    add_seconds_ptr(&class_start, 10);
    printf("5. seconds = %0.5f\n", class_start.second);

    return 1;
}
