#include <stdio.h>
#include "stack.h"

int main(int argc, char *argv[])
{
	stack_t s;
	DATA_T i;

	stack_init(&s);

	stack_dump(&s);

	for (i = 0; i < 5; ++i) {
		stack_push(&s, i);
	}

	stack_dump(&s);

	stack_pop(&s, &i);
	stack_pop(&s, &i);
	printf("pop %d\n", i);
	stack_dump(&s);

	return 0;
}

