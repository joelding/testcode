#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[])
{
	char *p = NULL, str[80] = {0};//, *q;

	memcpy(str, argv[0], strlen(argv[0]));
	printf("%s\n", str);

//	p = strtok_r(str, "/", &q);
	p = strtok(str, "/");
	while (p) {
//		printf("%s\n", q);
//		p = strtok_r(NULL, "/", &q);
		printf("%s\n", p);
		p = strtok(NULL, "/");
	}

	return 0;
}

