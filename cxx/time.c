/* time.c: calc microseconds from start to end
 */

#include <stdio.h>
#include <unistd.h>
#include <sys/time.h>

int main(int argc, char *argv[])
{
	struct timeval start, end;
	unsigned long diff;

	gettimeofday(&start, NULL);
	
	sleep(1); /* unistd.h */
	usleep(50); /* unistd.h */

	gettimeofday(&end, NULL);
	
	
	diff = 1000000 * (end.tv_sec - start.tv_sec) + (end.tv_usec - start.tv_usec);

	printf("%ld useconds\n", diff);

	return 0;
}

