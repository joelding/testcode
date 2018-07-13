#include <stdio.h>

/* When attached to an enum definition, it indicates that the smallest integral 
 * type should be used. 
 */

typedef enum __attribute__ ((__packed__))
{
	STATE_0,
	STATE_1,
	STATE_2,
} state_t;

/* This attribute, attached to struct or union type definition, specifies that 
 * each member (other than zero-width bit-fields) of the structure or union is 
 * placed to minimize the memory required.
 */

typedef struct __attribute__ ((__packed__)) _struct_t
{
	char c;
	int i;
	struct _struct_t *p;
	state_t state;
} struct_t;

int main(int argc, char *argv[])
{
	printf("sizeof(char) = %lu\n", sizeof(char));
	printf("sizeof(int) = %lu\n", sizeof(int));
	printf("sizeof(struct _struct_t *) = %lu\n", sizeof(struct _struct_t *));
	printf("sizeof(state_t) = %lu\n", sizeof(state_t));
	printf("sizeof(struct_t) = %lu\n", sizeof(struct_t));
	return 0;
}

