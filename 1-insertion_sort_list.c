#include "sort.h"

/**
 * insertion_sort_list - Sorts a doubly linked list of integers
 * in ascending order using the insertion sort algorithm
 *
 * @list: The doubly linked list to be sorted
 */

void insertion_sort_list(listint_t **list)
{
	listint_t *c, *p, *tmp;

	if (!list || !*list || !(*list)->next)
		return;

	c = (*list)->next;
	while (c)
	{
		p = c->prev;
		tmp = c->next;
		while (p && c->n < p->n)
		{
			if (p->prev)
				p->prev->next = c;
			if (c->next)
				c->next->prev = p;
			p->next = c->next;
			c->prev = p->prev;
			c->next = p;
			p->prev = c;

			if (!c->prev)
				*list = c;
			print_list(*list);
			p = c->prev;
		}
		c = tmp;
	}
}
