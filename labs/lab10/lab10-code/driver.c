/*
 * COMP 211, Fall 2022
 * Lab 10
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
dlist d;

void do_exit() { exit(0); }
void do_create() { l = create(); }
void do_print() { print(&l); }
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

void do_create_dlist() { d = dlist_create(); }
void do_print_dlist() { dlist_print(&d); }
void do_insert_dlist() {
    char c;
    int loc;
    printf("Enter character: ");
    scanf(" %1c", &c);
    printf("Enter insertion point: ");
    scanf(" %d", &loc);
    dlist_insert(&d, loc, c);
}
void do_deletion_dlist() {
    int loc;
    printf("Enter deletion point: ");
    scanf(" %d", &loc);
    char c = dlist_deletion(&d, loc);
    if (c == -1) {
        printf("Cannot delete element, no value returned\n");
    } else {
        printf("Deleted element at index %d with value %c\n", loc, c);
    }
}
void do_getval_dlist() {
    int loc;
    printf("Enter index to return value for: ");
    scanf(" %d", &loc);

    char c = dlist_getval(&d, loc);
    if (c == -1) {
        printf("Index out of range, no value returned\n");
    } else {
        printf("Returned value %c\n", c);
    }
}
void do_size_dlist() {
    int sz = dlist_size(&d);
    printf("List size is %d\n", sz);
}

int main(int argc, char **argv) {

    struct menu_opt menu[] = {
        {"Exit", do_exit},
        {"Create list (singly)", do_create},
        {"Insert character (singly)", do_insert},
        {"Delete character (singly)", do_deletion},
        {"Get character (singly)", do_getval},
        {"Print list size (singly)", do_size},
        {"Print list (singly)\n", do_print},
        {"Create list (doubly)", do_create_dlist},
        {"Insert character (doubly)", do_insert_dlist},
        {"Delete character (doubly)", do_deletion_dlist},
        {"Get character (doubly)", do_getval_dlist},
        {"Print list size (doubly)", do_size_dlist},
        {"Print list (doubly)\n", do_print_dlist}
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
        scanf("%u", &choice);
        if (choice >= 0 && choice < 7) {
            menu[choice].act();
            printf("Singly linked list contents:\n");
            do_print();
        } else if (choice >= 6 && choice < n_menu) {
            menu[choice].act();
            printf("Doubly linked list contents:\n");
            do_print_dlist();
        }

    }
    return 0;
}
