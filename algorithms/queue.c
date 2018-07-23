#include <stdio.h>
#include "queue.h"

void que_init(que_t *thiz)
{
	thiz->head = thiz->tail = 0;
}

/* return 0: not empty; otherwize: empty
 */
int que_is_empty(que_t *thiz)
{
	return (thiz->head == thiz->tail);
}

/* return 0: not full; otherwize: full
 */
int que_is_full(que_t *thiz)
{
	unsigned int idx = thiz->tail;

	idx = (idx + 1) % BUFFER_SIZE;
	return (thiz->head == idx);
}

void que_dump(que_t *thiz)
{
	unsigned int i;

	for (i = 0; i < BUFFER_SIZE; ++i) {
		printf("%d: %d ", i, thiz->buf[i]);

		if (i == thiz->head)
			printf("H\n");
		else if (i == thiz->tail)
			printf("T\n");
		else
			printf("\n");
	}
}

void que_enqueue(que_t *thiz, int val)
{
	if (que_is_full(thiz)) {
		printf("queue is full\n");
		return;
	}
	
	thiz->tail = (thiz->tail + 1) % BUFFER_SIZE;
	thiz->buf[thiz->tail] = val;
}

void que_dequeue(que_t *thiz, int *val)
{
	if (que_is_empty(thiz)) {
		printf("queue is empty\n");
		return;
	}

	thiz->head = (thiz->head + 1) % BUFFER_SIZE;
	if (val) {
		*val = thiz->buf[thiz->head];
	}
}

