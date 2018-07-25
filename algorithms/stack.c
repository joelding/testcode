#include <stdio.h>
#include "stack.h"

void stack_init(stack_t *thiz)
{
	thiz->top = -1;
}

/* return 0: not empty; otherwise: empty
 */
int stack_is_empty(stack_t *thiz)
{
	return (thiz->top == -1);
}

/* return 0: not full; otherwise: full
 */
int stack_is_full(stack_t *thiz)
{
	return (thiz->top == (BUFFER_SIZE - 1));
}

void stack_dump(stack_t *thiz)
{
	unsigned int i;

	for (i = 0; i < BUFFER_SIZE; ++i) {
		printf("%d: %d ", i, thiz->buf[i]);

		if (i == thiz->top)
			printf("T\n");
		else
			printf("\n");
	}

	printf("----------\n");
}

void stack_push(stack_t *thiz, DATA_T val)
{
	if (stack_is_full(thiz)) {
		printf("stack is full\n");
		return;
	}
	
	thiz->top += 1;
	thiz->buf[thiz->top] = val;
}

void stack_pop(stack_t *thiz, DATA_T *val)
{
	if (stack_is_empty(thiz)) {
		printf("stack is empty\n");
		return;
	}

	if (val) {
		*val = thiz->buf[thiz->top];
	}
	
	thiz->top -= 1;
}

