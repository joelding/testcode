#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(int argc, char *argv[])
{
	const unsigned int a[] = {12, 13, 20};
	unsigned int idx[2] = {255, 255};
	unsigned int cnt = 0;

	srand((unsigned int)time(NULL));
	printf("Usage: q to quit\n");
	
	printf("Got: ");
//	while ('q' != getchar()) {
	while (cnt++ < 10) {
		while (idx[0] == idx[1]) {
			idx[1] = rand() % (sizeof(a) / sizeof(unsigned int));
		}
		idx[0] = idx[1];
		printf("%d, ", a[idx[0]]);
	}
	printf("\n");
	return 0;
}

