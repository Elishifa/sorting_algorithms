#include "sort.h"

/**
 * list_len - func returns list length
 * @list: list
 * Return: length
 */

size_t list_len(listint_t *list)
{
	size_t len;

	len = 0;
	while (list)
	{
		len++;
		list = list->next;
	}
	return (len);
}

/**
 * switch_nodes - function swaps nodes at pointer p with the following node
 * @list: list
 * @p: ptr to node
 */
void switch_nodes(listint_t **list, listint_t **p)
{
	listint_t *one, *two, *three, *four;

	one = (*p)->prev;
	two = *p;
	three = (*p)->next;
	four = (*p)->next->next;
	two->next = four;
	if (four)
		four->prev = two;
	three->next = two;
	three->prev = two->prev;
	if (one)
		one->next = three;
	else
		*list = three;
	two->prev = three;
	*p = three;
}

/**
 *  cocktail_sort_list - funcsort doubly linked-list sorting
 * @list: ptr to list
 */

void cocktail_sort_list(listint_t **list)
{
	listint_t *q;
	int sorted = 0;

	if (!list || !*list || list_len(*list) < 2)
		return;
	q = *list;
	while (!sorted)
	{
		sorted = 1;
		while (q->next)
		{
			if (q->n > q->next->n)
			{
				sorted = 0;
				switch_nodes(list, &q);
				print_list(*list);
			}
			else
				q = q->next;
		}
		if (sorted)
			break;
		q = q->prev;
		while (q->prev)
		{
			if (q->n < q->prev->n)
			{
				sorted = 0;
				q = q->prev;
				switch_nodes(list, &q);
				print_list(*list);
			}
			else
				q = q->prev;
		}
	}
}
