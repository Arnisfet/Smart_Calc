//
// Created by arnisfet on 17.12.22.
//
#include "containers.h"

void	print_stack(Stack *head)
{
	if (!head)
		exit(EXIT_FAILURE);
	while(head)
	{
		printf("%s\n", head->name);
		head = head->next;
	}
}

void	push(Stack **head, char *name)
{
	Stack *p = NULL;
	if ((p = (Stack*)malloc(sizeof(Stack))) == NULL)
		exit (EXIT_FAILURE);
	p->next = *head;
	p->name = ft_strdup(name);
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
	free(tmp->name);
	free(tmp);
	return (value);
}



void init(Queue **pointer)
{
	(*pointer)->first = 0;
	(*pointer)->last = 0;
}

void insert_queue (Queue **pointer, char *name)
{
	Deque *tmp = NULL;
	if (!(*pointer))
	{
		printf("Queue doesn't exist!");
		exit(EXIT_FAILURE);
	}
	if ((*pointer)->last == 0 && (*pointer)->first == 0)
	{
		if((tmp = (Deque *) malloc(sizeof (Deque))) == NULL)
		{
			printf("The heap error!");
			exit(EXIT_FAILURE);
		}
		tmp->name = ft_strdup(name);
		tmp->next = NULL;
		(*pointer)->last = tmp;
		(*pointer)->first = (*pointer)->last;
		(*pointer)->size = 1;
	}
	else
	{
		if((tmp = (Deque *) malloc(sizeof (Deque))) == NULL)
		{
			printf("The heap error!");
			exit(EXIT_FAILURE);
		}
		tmp->name = ft_strdup(name);
		tmp->next = NULL;
		(*pointer)->last->next = tmp;
		(*pointer)->last = tmp;
		(*pointer)->size++;
	}
}

char *pop_queue(Queue **pointer)
{
	Deque *tmp = NULL;
	char *str = 0;
	if (!*pointer)
	{
		printf("Queue doesn't exist!");
		exit(EXIT_FAILURE);
	}
	if((*pointer)->first == NULL)
	{
		printf("The end of the queue!");
		exit(EXIT_FAILURE);
	}
	str = (*pointer)->first->name;
	tmp = (*pointer)->first;
	(*pointer)->first = (*pointer)->first->next;
	free(tmp);
	return (str);
}

void print_queue(Queue **pointer)
{
	Deque *tmp = NULL;
	tmp = (*pointer)->first;
	while(tmp)
	{
		printf("%s\n", tmp->name);
		tmp = tmp->next;
	}
}