/* purpose: to get a character from stdin while removing the rest
 */

#include <stdio.h>

int main(int argc, char * argv[])
{
	char c;

	while (1) {
		printf("Input a character: ");
		scanf("%c", &c);
		while ('\n' != getchar());

		switch (c) {
			case 'q':
				goto _exit;
				break;

			default:
				printf("received: %c\n", c);
				break;
		}
	}

_exit:

	return 0;
}

