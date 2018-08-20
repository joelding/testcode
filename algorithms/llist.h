#ifndef _LLIST_H_
#define  _LLIST_H_

#ifdef __cplusplus
extern "C" 
{
#endif

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

	typedef struct _listnode_t listnode_t;

	struct _listnode_t {
		struct tm time;
		listnode_t *next;
	};

	typedef struct {
		listnode_t *head;
	} list_t;

	int llist_init(list_t *thiz);
	void llist_destroy(list_t *thiz);
	void llist_dump(list_t *thiz);
	void llist_get_time(struct tm *);
	int llist_insert(list_t *, struct tm *);

#ifdef __cplusplus
}
#endif
#endif /* _LLIST_H_ */

