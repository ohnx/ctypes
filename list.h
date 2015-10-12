/*
 * Generic list manipulation functions
 *
 * ohnx was here (2015)
 */

#include "common.h"

#ifndef __LIST_H__
#define __LIST_H__

#define LIST_NONE -3   /* Empty list or nothing found */
#define LIST_OMEM -1    /* Out of Memory */
#define LIST_OK 0       /* OK */

/*
 * list_t is a pointer to an internally maintained data structure.
 * Clients of this package do not need to know how lists are
 * represented.  They see and manipulate only list_t's.
 */
typedef any_t list_t;

/*
 * Return an empty hashmap. Returns NULL if empty.
*/
extern list_t list_new();

/*
 * Add an element to the list at 0-start index. Return LIST_OK or LIST_OMEM
 */
extern int list_addAt(list_t in, unsigned int index, any_t value);

/*
 * Add an element to the end of the list. Return LIST_OK or LIST_OMEM
 */
extern int list_append(list_t in, any_t value);
extern int list_add(list_t in, any_t value);

/*
 * Add an element to the head of the list. Return LIST_OK or LIST_OMEM
 */
extern int list_push(list_t in, any_t value);

/*
 * Get the first element of the list and put it in value.
 * Return LIST_OK or LIST_NONE
 */
extern int list_pop(list_t in, any_t *value);

/*
 * Remove the element at specified 0-start index in the list
 * and store it in value.
 * Return LIST_OK or LIST_NONE if none found
 */
extern int list_popAt(list_t in, unsigned int index, any_t *value);

/*
 * Remove the element at specified 0-start index in the list
 * Return LIST_OK or LIST_NONE if none found
 */
extern int list_removeAt(list_t in, unsigned int index);

/*
 * Remove the first element equal to specified element in list
 * Return LIST_EMPTY if none found, or removed count if some were removed.
 */
extern int list_remove(list_t in, any_t value);

/*
 * Get an element from the list at 0-start index.
 * Return LIST_OK or LIST_NONE
 * value is set to NULL on error.
 */
extern int list_getAt(list_t in, unsigned int index, any_t *value);

/*
 * Set an element from the list at 0-start index.
 * Return LIST_OK or LIST_NONE if the index is too far
 */
extern int list_setAt(list_t in, unsigned int index, any_t value);

/*
 * Convert the list into an array
 * arrayptr set to NULL if list is empty, or array if it isn't
 * Return length of array or LIST_NONE if list is empty
 */
extern int list_toArray(list_t in, any_t *arrayptr);

/*
 * Get the current length of a list
 */
extern int list_length(list_t in);
extern int list_size(list_t in);

/*
 * check if list is empty
 */
extern bool list_isEmpty(list_t in);

/*
 * empty list
 */
extern void list_empty(list_t in);

/*
 * Iteratively call f with argument (item, data) for
 * each element data in the list. The function must
 * return a map status code. If it returns anything other
 * than LIST_OK the traversal is terminated. f must
 * not reenter any hashmap functions, or deadlock may arise.
 */
extern int list_iterate(list_t in, PFany f, any_t item);

/*
 * Add an array to the end of the list.
 * Return LIST_OK or LIST_OMEM
 */
extern int list_addArray(list_t in, any_t *array, unsigned int arrayLen);

/*
 * Add a list to the end of the list.
 * Return LIST_OK or LIST_OMEM
 */
extern int list_addList(list_t in, list_t appendList);

/*
 * Check if the list contains something equal to item
 * Return true or false/1 or 0, respectively
 */
extern bool list_contains(list_t in, any_t item);

/*
 * get the index of an item in the list
 * Return index or LIST_NONE
 */
extern int list_indexOf(list_t in, any_t item);

/*
 * Free the list and every item in it
 */
extern void list_freeAll(list_t in);

/*
 * Free the list -> only frees list object itself
 */
extern void list_free(list_t in);

#endif /* __LIST_H__ */
