/* varlen.c 
 *
 * reference: 
 * 	https://openhome.cc/Gossip/CGossip/Variable-lengthArgument.html
 * 	man stdarg
 */

#include <stdio.h>
#include <stdarg.h>

#if 1 
static void dbgprint(const char *fmt, ...)
{
	va_list args;
	char c, *s;
	int d;
	double f;

	va_start(args, fmt);

	while (*fmt)
	{
		switch (*fmt++)
		{
			case 's':
				s = va_arg(args, char *);
				printf("%s", s);
				break;
			case 'd':
				d = va_arg(args, int);
				printf("%d", d);
				break;
			case 'c':
				c = (char) va_arg(args, int);
				printf("%c", c);
				break;
			case 'f':
				f = (double) va_arg(args, double);
				printf("%f", (float) f);
				break;
			case '\n':
				printf("\n");
				break;
		}
	}

	va_end(args);
}
#endif

static void foo(int len, ...)
{
	int i;

	va_list args;
	va_start(args, len);
	for (i = 0; i < len; ++i)
	{
		printf("%.1f\n", va_arg(args, double));
	}

	va_end(args);
}

int main(int argc, char *argv[])
{
	printf("--- varlen --- \n");

#if 1
	dbgprint("%s\n", argv[0]);
	dbgprint("%d\n", -1);
	dbgprint("%f\n", 1.1);
#endif
	double x = 1.1, y = 2 * x, z = 3 * x;
	double a = 0.1, b = 0.2, c = 0.3;

	foo(3, x, y, z);
	foo(6, x, y, z, a, b, c);


	return 0;
}

