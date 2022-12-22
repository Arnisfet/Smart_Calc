//
// Created by arnisfet on 18.12.22.
//

#include "shuntin_yard.h"

void	push_node(List **top, int number)
{
	List *tmp = NULL;
	if ((tmp = (List*)malloc(sizeof (List))) == NULL)
		exit(EXIT_FAILURE);
	tmp->number = number;
	tmp->next = *top;
	*top = tmp;
}

int pop_node(List **top)
{
	List *prev = NULL;
	int num = 0;
	if (!*top)
		exit (EXIT_FAILURE);
	prev = (*top);
	num = prev->number;
	(*top) = (*top)->next;
	free(prev);
	return (num);
}