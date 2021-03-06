/* test whether a pre-test buffer can be altered by reading a file
 */

#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[])
{
	unsigned char uc[64];
	FILE *fp = NULL;
	int len, i;
	long sz;

	fp = fopen(argv[1], "r");

	/* get the files size */
	fseek(fp, 0L, SEEK_END);
	sz = ftell(fp);
	printf("file size %ld\n", sz);

	/* set file pointer to the start */
	rewind(fp);
//	fseek(fp, 0L, SEEK_SET);

	memset(uc, 0xff, 64);
	len = fread(uc, 1, 64, fp);
	printf("read length %d\n", len);

	for (i = 0; i < 64; ++i) {
		printf("%02x ", uc[i]);
		if (((i + 1) % 8) == 0) printf("\n");
	}

	memset(uc, 0xff, 64);
	len = fread(uc, 1, 64, fp);
	printf("read length %d\n", len);

	for (i = 0; i < 64; ++i) {
		printf("%02x ", uc[i]);
		if (((i + 1) % 8) == 0) printf("\n");
	}

	fclose(fp);

	return 0;
}

