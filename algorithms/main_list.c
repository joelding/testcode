#include "list.h"

int main(int argc, char *argv[])
{
	list_t list;
	struct tm tm;

	list_init(&list);
	list_get_time(&tm);
	list_insert(&list, &tm);
	list_get_time(&tm);
	list_insert(&list, &tm);
	list_dump(&list);

	return 0;
}

