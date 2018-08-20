#include "llist.h"


int llist_init(list_t *thiz)
{
	thiz->head = NULL;
	
	thiz->head = (listnode_t *) malloc(sizeof(listnode_t));
	if (!(thiz->head)) return -1;

	memset(thiz->head, 0, sizeof(listnode_t));

	return 0;
}

void llist_destroy(list_t *thiz)
{
	listnode_t *p = thiz->head, *q;
	int idx = 0;

	q = p->next;
	while (q) {
		p = q;
		q = q->next;
		printf("free [%d] %s", idx++, asctime(&(p->time)));
		free(p);
	}

	free(thiz->head);
}

void llist_dump(list_t *thiz)
{
	listnode_t *p = thiz->head->next;
	int idx = 0;

	printf("++++++++++++\n");
	while (p) {
		printf("[%d] %s", idx++, asctime(&(p->time)));
		p = p->next;
	}
	printf("------------\n");
}

void llist_get_time(struct tm *tm)
{
	/* number of seconds since the Epoch 1970-01-01 00:00:00:00 +0000 (UTC) */
	time_t seconds = time((time_t *)NULL);

	seconds += (time_t) rand() % 3600;	
	memcpy(tm, localtime(&seconds), sizeof(struct tm));
	printf("new: %s", asctime(tm));
}

static listnode_t *find_prev(list_t *thiz, struct tm *tm)
{
	time_t ctime = mktime(tm), ptime;
	listnode_t *p = thiz->head, *q;

	q = p->next;
	while (q) {
		ptime = mktime(&(q->time));
	
		if (ptime >= ctime) break;
		
		p = q;
		q = p->next;
	}

	return (p);
}

int llist_insert(list_t *thiz, struct tm *tm)
{
	listnode_t *node = NULL, *prev;

	node = (listnode_t *)malloc(sizeof(listnode_t));
	if (!node) return -1;

	memcpy(&(node->time), tm, sizeof(struct tm));

	prev = find_prev(thiz, tm);
	node->next = prev->next;
	prev->next = node;

	return 0;
}


