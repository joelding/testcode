#include "list.h"

int main(int argc, char *argv[])
{
	list_t list;
	struct tm tm;
	int i;

	list_init(&list);

	for (i = 0; i < 7; ++i) {	
		list_get_time(&tm);
		list_insert(&list, &tm);
		list_dump(&list);
	}

	for (i = 0; i < 7; ++i) {	
		list_get_time(&tm);
		list_delete(&list, &tm);
		list_dump(&list);
	}

	return 0;
}

