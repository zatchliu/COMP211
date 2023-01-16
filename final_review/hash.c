/* COMP 211, Fall 2022
 * Lab 12
 *
 * Sets and hash tables
 */

#include <stdlib.h>

#include "set.h"

unsigned int hash(unsigned int key) {
    return key % NUM_BUCKET;
}

