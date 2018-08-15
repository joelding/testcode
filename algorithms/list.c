#include "list.h"

void list_init(list_t *thiz)
{
	int i;

	for (i = 0; i < SIZE_DATA; ++i) {
		thiz->data[i].next = -1;
	}
}

void list_dump(list_t *thiz)
{
	int idx = thiz->data[0].next;

	while (idx > -1) {
		printf("[%d] %s", idx, asctime(&(thiz->data[idx].time)));
		idx = thiz->data[idx].next;
	}
}

void list_get_time(struct tm *tm)
{
	/* number of seconds since the Epoch 1970-01-01 00:00:00:00 +0000 (UTC) */
	time_t seconds = time((time_t *)NULL);

	seconds += 100; /* offset */
	seconds += (time_t) rand() % 10000;	
	memcpy(tm, localtime(&seconds), sizeof(struct tm));
	printf("%s\n", asctime(tm));
}

int list_insert(list_t *thiz, struct tm *tm)
{
	int i = 1;

	/* insert */
	while (thiz->data[i].next != -1) {
		++i;

		if (i >= SIZE_DATA) return -1; /* full */
	}

	memcpy(&(thiz->data[i].time), tm, sizeof(struct tm));

	/* update the index */
/* time_t mktime(struct tm *tm)
*/
	if (thiz->data[0].next == -1) { /* empty list */
		thiz->data[0].next = i;
	} else {
	}
	
	return 0;
}
