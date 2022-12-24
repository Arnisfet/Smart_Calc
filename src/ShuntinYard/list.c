//
// Created by arnisfet on 18.12.22.
//

#include "shuntin_yard.h"

void	push_node(Deque **top, char *name)
{
	Deque *tmp = NULL;
	if ((tmp = (Deque*)malloc(sizeof (Deque))) == NULL)
		exit(EXIT_FAILURE);
	tmp->name = ft_strdup(name);
	tmp->next = *top;
	*top = tmp;
}

char *pop_node(Deque **top)
{
	Deque *prev = NULL;
	char *str = 0;
	if (!*top)
		exit (EXIT_FAILURE);
	prev = (*top);
	str = prev->name;
	(*top) = (*top)->next;
	free(prev);
	free (str);
	return (*top ? 1 : 0);
}

void print_list(Deque **top)
{
	Deque *pointer = NULL;
	pointer = *top;
	while(pointer)
	{
		printf("%s\n", pointer->name);
		pointer = pointer->next;
	}
}