#include <stdio.h>

int main(int argc, char *argv[])
{
	unsigned char a[5] = {0x42,};
	int i;

	for (i = 0; i < 5; ++i)
		printf("a[%d]=0x%02x\n", i, a[i]);

	return 0;
}

