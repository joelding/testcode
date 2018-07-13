#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[])
{
	char *endp;
	int is_hex = 0;

	if ((!strncmp(argv[1], "0x", 2)) || 
	    (!strncmp(argv[1], "0X", 2)))
		is_hex = 1;

	printf("string: %s\n", argv[1]);
	printf("digit: %d\n", atoi(argv[1]));
	if (is_hex)
		printf("1. digit: %ld\n", strtol(argv[1], &endp, 16));
	else
		printf("0, digit: %ld\n", strtol(argv[1], &endp, 10));
	
	return 0;
}

