/*
 * ctypes common header
 *
 * ohnx was here (2015)
 */
#ifndef __CTYPES_COMMON_H__
#define __CTYPES_COMMON_H__

#define _CTYPES_VERSION     1

#define bool              int
#define true                1
#define false               0

/*
 * any_t is a void pointer.  This allows you to put arbitrary structures in
 * the hashmap.
 */
typedef void *any_t;

/*
 * PFany is a pointer to a function that can take two any_t arguments
 * and return an integer. Returns status code..
 */
typedef int (*PFany)(any_t, any_t);

#endif /* __CTYPES_COMMON_H__ */
