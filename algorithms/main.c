#include <stdio.h>
#include "queue.h"

int main(int argc, char *argv[])
{
	que_t queue;
	int i, val;

	que_init(&queue);

	printf("queue is %sempty\n", que_is_empty(&queue) ? "" : "not ");
	printf("queue is %sfull\n", que_is_full(&queue) ? "" : "not ");

	for (i = 0; i < 5; ++i)
		que_enqueue(&queue, i);

	que_dump(&queue);

	que_dequeue(&queue, &val);
	printf("dequeue: %d\n", val);
	que_dequeue(&queue, &val);
	printf("dequeue: %d\n", val);
	
	que_dump(&queue);

	for (; i < 10; ++i)
		que_enqueue(&queue, i);

	que_dump(&queue);

	return 0;
}

