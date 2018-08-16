#ifndef _LIST_H_
#define  _LIST_H_

/* USE_ARRAY: implementing linked list  
 */
#define USE_ARRAY	1

#ifdef __cplusplus
extern "C" 
{
#endif

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define SIZE_DATA	11

#if USE_ARRAY
	typedef struct {
		struct tm time;
		int next;
	} node_t;
	
	typedef struct {
		node_t node[SIZE_DATA];
	} list_t;

	void list_init(list_t *thiz);
	void list_dump(list_t *thiz);
	void list_get_time(struct tm *);
	int list_insert(list_t *, struct tm *);
	int list_delete(list_t *thiz, struct tm *);

#endif /* USE_ARRAY */

#ifdef __cplusplus
}
#endif

#endif /* _LIST_H_ */

