#include "sort.h"

void swap(listint_t **list, listint_t *n1, listint_t *n2);

/**
 * cocktail_sort_list - Sorts a doubly linked list of integers
 * in ascending order using the Cocktail shaker sort algorithm
 *
 * @list: The doubly linked list to be sorted
 */
void cocktail_sort_list(listint_t **list)
{
	listint_t *tmp;
	int flag = 1;

	if (!list || !*list || !(*list)->next)
		return;

	while (flag)
	{
		flag = 0;
		tmp = *list;
		while (tmp->next)
		{
			if (tmp->n > tmp->next->n)
			{
				swap(list, tmp, tmp->next);
				print_list(*list);
				flag = 1;
			}
			else
				tmp = tmp->next;
		}
		if (!flag)
			break;
		flag = 0;
		while (tmp->prev)
		{
			if (tmp->n < tmp->prev->n)
			{
				swap(list, tmp->prev, tmp);
				print_list(*list);
				flag = 1;
			}
			else
				tmp = tmp->prev;
		}
	}
}


/**
 * swap - Swaps two nodes in a doubly linked list
 *
 * @list: The doubly linked list to be sorted
 * @n1: The first node to be swapped
 * @n2: The second node to be swapped
 */
void swap(listint_t **list, listint_t *n1, listint_t *n2)
{
	listint_t *tmp_n1_prev = n1->prev, *tmp_n2_next = n2->next;

	if (n1->prev)
		tmp_n1_prev->next = n2;
	else
		*list = n2;

	if (n2->next)
		tmp_n2_next->prev = n1;
	n1->next = tmp_n2_next;
	n2->next = n1;
	n1->prev = n2;
	n2->prev = tmp_n1_prev;
}
