#include "llist.h"

int main(int argc, char *argv[])
{
	list_t list;
	struct tm tm;
	int i;

	llist_init(&list);

	for (i = 0; i < 7; ++i) {	
		llist_get_time(&tm);
		llist_insert(&list, &tm);
		llist_dump(&list);
	}

	llist_destroy(&list);

	return 0;
}

