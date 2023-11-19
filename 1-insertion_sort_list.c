#include <stdio.h>
#include "sort.h"

/**
 * insertion_sort_list - Sorts a doubly linked list of integers
 * @list: Pointer to the head of the doubly linked list
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *current;

	current = (*list)->next;
	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;
	while (current != NULL)
	{
		listint_t *temp = current->next;

		while (current->prev != NULL && current->n < current->prev->n)
		{
			if (current->next != NULL)
				current->next->prev = current->prev;
			current->prev->next = current->next;
			current->next = current->prev;
			current->prev = current->prev->prev;
			current->next->prev = current;
			if (current->prev == NULL)
				*list = current;
			else
				current->prev->next = current;
			print_list(*list);
		}
		current = temp;
	}
}
