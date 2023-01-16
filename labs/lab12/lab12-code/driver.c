/* COMP 211, Fall 2022
 * Lab 12
 *
 * Sets and hash tables
 */

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#include "set.h"

struct menu_opt {
    char* desc;
    void (*act)(void);
};

struct set *s = NULL;
struct dict *d = NULL;

void do_exit() { exit(0); }
void do_set_create() { s = set_create(); }
void do_set_delete_all() { set_delete_all(s); }
void do_set_add() {
    unsigned int u;
    printf("Enter key: ");
    scanf(" %u", &u);
    set_add(s, u);
}
void do_set_member() {
    unsigned int u;
    printf("Enter key: ");
    scanf(" %u", &u);
    printf("Key found? %u \n", set_member(s, u));
}
void do_set_delete() {
    unsigned int u;
    printf("Enter key: ");
    scanf(" %u", &u);
    set_delete(s, u);
}
void do_set_print() {
    printf("Calling set_print...\n");
    set_print(s);
    printf("Done calling set_print...\n");
}

int main(int argc, char **argv) {

    struct menu_opt menu[] = {
        {"Exit", do_exit},
        {"Set: Create empty set", do_set_create},
        {"Set: Add member", do_set_add},
        {"Set: Check membership", do_set_member},
        {"Set: Remove member", do_set_delete},
        {"Set: Delete all", do_set_delete_all},
        {"Set: Print", do_set_print},
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
        menu[choice].act();

        printf("Set contents: ");
        int n = set_size(s);
        unsigned int a[n];
        set_as_array(s, a);
        printf("{");
        for (int i=0; i<n; ++i) {
            printf("%d, ", a[i]);
        }
        printf("}\n");
    }

    return 0;
}
