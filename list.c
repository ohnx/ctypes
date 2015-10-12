/*
 * Generic linked list implementation.
 *
 * ohnx was here (2015)
 */
#include "list.h"

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define INITIAL_SIZE (256)
#define MAX_CHAIN_LENGTH (8)

/* We need to keep keys and values */
typedef struct _list_element {
    struct _list_element *prev;
    any_t data;
    struct _list_element *next;
} list_element;

/* A hashmap has some maximum size and current size,
 * as well as the data to hold. */
typedef struct _linked_list {
    int length;             /* to reduce time complexity */
    list_element *head;
    list_element *last;     /* to reduce time complexity */
} linked_list;

/*
 * Return an empty list, or NULL on failure.
 */
list_t list_new() {
    linked_list* l = (linked_list*) malloc(sizeof(linked_list));
    if(!l) return NULL;

    l->head = NULL;
    l->last = NULL;
    l->length = 0;

    return l;
}