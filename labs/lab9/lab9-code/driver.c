/*
 * Fall 2022, COMP 211: Lab 9
 *
 * Driver code to work with list data structure.
 */

#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>

#include "list.h"

struct menu_opt {
    char* desc;
    void (*act)(void);
};

list l;

void do_exit() {  exit(0); }
void do_create() { l = create(); }
void do_print() {  print(&l); }

void do_insert() {
    char c;
    int loc;
    printf("Enter character: ");
    scanf(" %1c", &c);
    printf("Enter insertion point: ");
    scanf(" %d", &loc);
    insert(&l, loc, c);
}

void do_deletion() {
    int loc;
    printf("Enter deletion point: ");
    scanf(" %d", &loc);
    char c = deletion(&l, loc);
    if (c == -1) {
        printf("Cannot delete element, no value returned\n");
    } else {
        printf("Deleted element at index %d with value %c\n", loc, c);
    }
}

void do_getval() {
    int loc;
    printf("Enter index to return value for: ");
    scanf(" %d", &loc);

    char c = getval(&l, loc);
    if (c == -1) {
        printf("Index out of range, no value returned\n");
    } else {
        printf("Returned value %c\n", c);
    }
}

void do_size() {
    int sz = size(&l);
    printf("List size is %d\n", sz);
}

int main(int argc, char **argv) {

    struct menu_opt menu[] = {
        {"Exit", do_exit},
        {"Create list", do_create},
        {"Insert character", do_insert},
        {"Delete character", do_deletion},
        {"Get character", do_getval},
        {"Print list size", do_size},
        {"Print list", do_print}
    };

    // WARNING:  this method for computing the size of an array only works when
    // the array is declared on the stack.  In particular, it is not valid when
    // the array is allocated using malloc, calloc, etc.
    int n_menu = sizeof(menu)/sizeof(struct menu_opt);
    int choice;

    while (true) {

        for (int i=0; i<n_menu; ++i) {
            printf("(%d) %s\n", i, menu[i].desc);
        }

        printf("Enter choice: ");
        scanf(" %u", &choice);

        if (choice >= 0 && choice < n_menu) {
            menu[choice].act();
            printf("List contents:\n");
            do_print();
        }
    }
    return 0;
}
