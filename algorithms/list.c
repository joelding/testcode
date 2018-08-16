#include "list.h"

void list_init(list_t *thiz)
{
	int i;

	thiz->node[0].next = 0;

	for (i = 1; i < SIZE_DATA; ++i) {
		thiz->node[i].next = -1;
	}
}

void list_dump(list_t *thiz)
{
	int idx = thiz->node[0].next;

	printf("++++++++++++\n");
	while (idx > 0) {
		printf("[%d] %s", idx, asctime(&(thiz->node[idx].time)));
		idx = thiz->node[idx].next;
	}
	printf("------------\n");
}

void list_get_time(struct tm *tm)
{
	/* number of seconds since the Epoch 1970-01-01 00:00:00:00 +0000 (UTC) */
	time_t seconds = time((time_t *)NULL);

	seconds += (time_t) rand() % 3600;	
	memcpy(tm, localtime(&seconds), sizeof(struct tm));
	printf("new: %s", asctime(tm));
}

static int find_prev(list_t *thiz, struct tm *tm)
{
	int i = 0, j = 0;
	time_t ctime = mktime(tm), ptime;

	while (thiz->node[i].next != 0) {
		i = j;
		j = thiz->node[i].next;
		ptime = mktime(&(thiz->node[j].time));
	
		if (ptime >= ctime) break;

	}

	return (i);
}

int list_insert(list_t *thiz, struct tm *tm)
{
	int idx = 1, prev, tmp;

	/* insert */
	while (thiz->node[idx].next != -1) {
		++idx;

		if (idx >= SIZE_DATA) return -1; /* full */
	}

	memcpy(&(thiz->node[idx].time), tm, sizeof(struct tm));

	prev = find_prev(thiz, tm);
	tmp = thiz->node[prev].next;
	thiz->node[prev].next = idx;
	thiz->node[idx].next = tmp;
	
	return 0;
}

/* delete a record later than a given tm 
 */
int list_delete(list_t *thiz, struct tm *tm)
{
	int prev = find_prev(thiz, tm), curr;

	curr = thiz->node[prev].next;
	printf("delete [%d]\n", curr);
	thiz->node[prev].next = thiz->node[curr].next;
	thiz->node[curr].next = -1;

	return curr;
}

