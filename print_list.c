#include <stdio.h>
#include "sort.h"

/**
 * print_list - Prints a list of integers
 * @list:  been printed
 */

void print_list(const listint_t *list)
{
	int t = 0;

	while (list)
	{
		if (t > 0)
			printf(", ");
		printf("%d", list->n);
		++t;
		list = list->next;
	}
	printf("\n");
}
