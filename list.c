/*
 * Generic list implementation.
 * This is a single-linked list to save memory.
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

/*
 * Add an element to the list at 0-start index. Return LIST_OK or LIST_OMEM
 */
int list_addAt(list_t in, unsigned int index, any_t value) {
    
}

/*
 * Add an element to the end of the list. Return LIST_OK or LIST_OMEM
 */
int list_append(list_t in, any_t value) {
    return list_add(in, value);
}
int list_add(list_t in, any_t value) {
    /* cast generic list type to custom type */
    linked_list *l = (linked_list *) in;
    /* allocate memory for new list element */
    list_element *toAdd = (list_element *) malloc(sizeof(list_element));

    /* out of memory */
    if(toAdd == NULL) return LIST_OMEM;

    /* set next element to null */
    toAdd->next = NULL;

    /* set current tail element's next to new element */
    (l->tail)->next = toAdd;

    /* set new tail of list to new element */
    l->tail = toAdd;

    /* increment size */
    l->length++;

    return LIST_OK;
}

/*
 * Add an element to the head of the list. Return LIST_OK or LIST_OMEM
 */
int list_push(list_t in, any_t value) {
    /* cast generic list type to custom type */
    linked_list *l = (linked_list *) in;
    /* allocate memory for new list element */
    list_element *toAdd = (list_element *) malloc(sizeof(list_element));

    /* out of memory */
    if(toAdd == NULL) return LIST_OMEM;

    /* set next element of new element to head of list */
    toAdd->next = l->head;

    /* set new head of list to new element */
    l->head = toAdd;

    /* increment size */
    l->length++;

    return LIST_OK;
}

/*
 * Get the first element of the list and put it in value.
 * Return LIST_OK or LIST_NONE
 */
int list_pop(list_t in, any_t *value) {
    /* cast generic list type to custom type */
    linked_list *l = (linked_list *) in;
    list_element *temp;

    /* empty list */
    if(l->head == NULL) return LIST_NONE;

    /* use temporary variable */
    temp = l->head;
    /* store value in given variable */
    *value = temp->data;
    /* set new head */
    l->head = temp->next;
    /* decrease length */
    l->length--;
    /* free temp */
    free(temp);

    return LIST_OK;
}

/*
 * Remove the element at specified 0-start index in the list
 * and store it in value.
 * Return LIST_OK or LIST_NONE if none found
 */
int list_popAt(list_t in, unsigned int index, any_t *value) {}

/*
 * Remove the element at specified 0-start index in the list
 * Return LIST_OK or LIST_NONE if none found
 */
int list_removeAt(list_t in, unsigned int index) {}

/*
 * Remove the first element equal to specified element in list
 * Return LIST_EMPTY if none found, or removed count if some were removed.
 */
int list_remove(list_t in, any_t value) {}

/*
 * Get an element from the list at 0-start index.
 * Return LIST_OK or LIST_NONE
 * value is set to NULL on error.
 */
int list_getAt(list_t in, unsigned int index, any_t *value) {
    /* cast generic list type to custom type */
    linked_list *l = (linked_list *) in;
    int i = 0;

    /* There is no way the index is valid. */
    if(l->length =< index) return LIST_NONE;

    /* iterate until we hit the right index value */
    while(curr != NULL) {
        /* is i equal to the index ? */
        if(i == index) {
            /* we've found the correct pointer, now replace the data */
            *value = curr->data;
            return LIST_OK;
        }
        /* nope, keep going */
        curr = curr->next;
        i++;
    }
    /* something is terribly wrong with the list. */
    return LIST_NONE;
}

/*
 * Set an element from the list at 0-start index.
 * Return LIST_OK or LIST_NONE if the index is too far
 */
int list_setAt(list_t in, unsigned int index, any_t value) {
    /* cast generic list type to custom type */
    linked_list *l = (linked_list *) in;
    int i = 0;

    /* There is no way the index is valid. */
    if(l->length =< index) return LIST_NONE;

    /* iterate until we hit the right index value */
    while(curr != NULL) {
        /* is i equal to the index ? */
        if(i == index) {
            /* we've found the correct pointer, now replace the data */
            curr->data = value;
            return LIST_OK;
        }
        /* nope, keep going */
        curr = curr->next;
        i++;
    }
    /* something is terribly wrong with the list. */
    return LIST_NONE;
}

/*
 * Convert the list into an array
 * arrayptr set to NULL if list is empty, or array if it isn't
 * Return length of array or LIST_NONE if list is empty
 */
int list_toArray(list_t in, any_t *arrayptr) {
    /* cast generic list type to custom type */
    linked_list *l = (linked_list *) in;
    int i = 0;

    /* length should be final array length */
    arrayptr = (any_t) malloc(sizeof(any_t) * l->length);

    /* iterate until we hit the end */
    while(curr != NULL) {
        /* *(arrayptr+i) = data in list element */
        i[arrayptr] = curr->data;
        curr = curr->next;
        i++;
    }

    /* i should be length anyways */
    return i;
}

/*
 * Get the current length of a list
 */
int list_length(list_t in) {
    /* cast generic list type to custom type */
    linked_list *l = (linked_list *) in;
    return l->length;

}
int list_size(list_t in) {
    return list_length(in);
}

/*
 * check if list is empty
 */
bool list_isEmpty(list_t in) {
    return list_size(in)==0;
}

/*
 * empty list
 */
void list_empty(list_t in) {
    /* cast generic list type to custom type */
    linked_list *l = (linked_list *) in;
    list_element *curr = l->head;
    list_element *temp;

    /* iterate until we hit the end */
    while(curr != NULL) {
        temp = curr->next;
        free(curr);
        curr = temp;
    }

    /* set size to 0 */
    l->length = 0;
}

/*
 * Iteratively call f with argument (item, data) for
 * each element data in the list. The function must
 * return a map status code. If it returns anything other
 * than LIST_OK the traversal is terminated. f must
 * not reenter any hashmap functions, or deadlock may arise.
 */
int list_iterate(list_t in, PFany f, any_t item) {}

/*
 * Add an array to the end of the list.
 * Return LIST_OK or LIST_OMEM
 */
int list_addArray(list_t in, any_t *array, unsigned int arrayLen) {}

/*
 * Add a list to the end of the list.
 * Return LIST_OK or LIST_OMEM
 */
int list_addList(list_t in, list_t appendList) {}

/*
 * Check if the list contains something equal to item
 * Return true or false/1 or 0, respectively
 */
bool list_contains(list_t in, any_t item) {}

/*
 * get the index of an item in the list
 * Return index or LIST_NONE
 */
int list_indexOf(list_t in, any_t item) {}

/*
 * Free the list and every item in it
 */
void list_freeAll(list_t in) {
    list_empty(in);
    list_free(in);
}

/*
 * Free the list -> only frees list object itself
 */
void list_free(list_t in) {
    /* cast generic list type to custom type */
    linked_list *l = (linked_list *) in;
    free(l);
}
