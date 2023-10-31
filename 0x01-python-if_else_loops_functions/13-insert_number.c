#include "lists.h"
#include <stdlib.h>
#include <unistd.h>

/**
 * insert_node - inserts a number in an ordered linked list
 * @head: double pointer to the linked list
 * @number: number to insert in the new node
 *
 * Return: address of the new node, or NULL
 */
listint_t *insert_node(listint_t **head, int number)
{
	listint_t *current = *head;
	listint_t *it = NULL;
	listint_t *temp = NULL;

	if (!head)
		return (NULL);

	it = malloc(sizeof(listint_t));
	if (!it)
		return (NULL);
	it->n = number;
	it->next = NULL;

	if (!*head || (*head)->n > number)
	{
		it->next = *head;
		return (*head = it);
	}
	else
	{
		while (current && current->n < number)
		{
			temp = current;
			current = current->next;
		}
		temp->next = it;
		it->next = current;
	}

	return (it);
}
