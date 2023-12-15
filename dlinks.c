#include "monty.h"

/**
 * add_dnodeint - function that adds new node at begininning of a dbly,
 * linked list.
 * @head: pointer to pointer to head of list.
 * @n: data to be added.
 *
 * Return: the address of the new element, or NULL if it failed.
 */

stack_t *add_dnodeint(stack_t **head, const int n)
{
	stack_t *new_list;

	/*now we are going to creat new node*/
	new_list = malloc(sizeof(stack_t));

		/*if the code failes*/
		if (new_list == NULL)
			return (NULL);

	/*creat the pinters and data*/
	new_list->prev = NULL;
	new_list->n = n;
	new_list->next = *head;

	/* cheach if head is not empty*/
	if (*head != NULL)
	(*head)->prev = new_list;
	(*head) = new_list;
		return (new_list);
}


/**
 * add_dnodeint_end - function that adds node at the end of a list.
 * @head: pointer to pointer to head of list.
 * @n: data to be added.
 *
 * Return: address of the new element or NULL if it failed.
 */

int add_dnodeint_end(stack_t **head, const int n)
{
	stack_t *new_list, *trav;

	if (!head)
		return (1);
	/* creat the new node*/
	new_list = malloc(sizeof(stack_t));
	if (new_list == NULL)
	{
		fprintf(stderr, "Error: malloc failed");
		return (1);
	}

	new_list->n = n;
	new_list->next = NULL;

	/* chech if head is empty or not*/
	if (*head == NULL)
	{
		new_list->prev = NULL;
		*head = new_list;
		return (0);
	}
	else
	{
	/* now lest travers our list*/
		trav = *head;
	while (trav->next != NULL)
		trav = trav->next;
	trav->next = new_list;
	}
	new_list->prev = trav;
	return (0);
}

/**
 * delete_dnodeint_at_index - function that deletes the node at index of a,
 * linked list.
 * @head: pointer to pointer to the h of linked list
 *
 * Return: if it succeeded, -1 if it failed
 */
int delete_dnodeint_at_index(stack_t **head)
{
	stack_t *first;
	int index;

	first = *head;

	if (*head == NULL)
		return (-1);

	for (; index != 0; index--)
	{
		if (first == NULL)
			return (-1);
		first = first->next;
	}

	if (first == *head)
	{
		*head = first->next;
		if (*head != NULL)
			(*head)->prev = NULL;
	}

	else
	{
		first->prev->next = first->next;
		if (first->next != NULL)
			first->next->prev = first->prev;
	}

	free(first);
	return (1);
}
