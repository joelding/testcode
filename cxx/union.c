#include <stdio.h>

typedef union {
	struct {
		unsigned char a: 5;
		unsigned char c: 3;
	} bit;
	unsigned char b8;
} byte_t;

int main(int argc, char *argv[])
{
	byte_t var;

	//var.bit.a = 0x1f;
	var.bit.c = 0x7;
	printf("%x\n", var.b8);
	printf("sizeof(var) = %lu\n", sizeof(var));
//	printf("sizeof(var.bit.c) = %lu\n", sizeof(var.bit.c));

	return 0;
}

