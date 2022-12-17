//
// Created by arnisfet on 17.12.22.
//
#include "stack.h"

void	print_stack(Stack *head)
{
	if (!head)
		exit(EXIT_FAILURE);
	while(head)
	{
		printf("%c\n", head->name);
		head = head->next;
	}
}

void	push(Stack **head, char name)
{
	Stack *p = NULL;
	if ((p = (Stack*)malloc(sizeof(Stack))) == NULL)
		exit (EXIT_FAILURE);
	p->next = *head;
	p->name = name;
	*head = p;
}

char	pop(Stack **head)
{
	char value;
	Stack *tmp;
	if (*head == NULL)
		exit(EXIT_FAILURE);
	value = (*head)->name;
	tmp = *head;
	*head = (*head)->next;
	free(tmp);
	return (value);
}