#include "containers.h"


/********************* Queue *************************/

void init(Queue **pointer)
{
	(*pointer)->first = 0;
	(*pointer)->last = 0;
}

void insert_queue (Queue ***pointer, char *name)
{
	Deque *tmp = NULL;
	if (!(*pointer))
	{
		printf("Queue doesn't exist!");
		exit(EXIT_FAILURE);
	}
	if ((**pointer)->last == 0 && (**pointer)->first == 0)
	{
		if((tmp = (Deque *) malloc(sizeof (Deque))) == NULL)
		{
			printf("The heap error!");
			exit(EXIT_FAILURE);
		}
		tmp->name = ft_strdup(name);
		tmp->next = NULL;
		tmp->token = 0;
		tmp->priority = 0;
		(**pointer)->last = tmp;
		(**pointer)->first = (**pointer)->last;
		(**pointer)->size = 1;
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
		tmp->token = 0;
		tmp->priority = 0;
		(**pointer)->last->next = tmp;
		(**pointer)->last = tmp;
		(**pointer)->size++;
	}
}

void insert_queue_2 (Queue **pointer, char *name)
{
	Deque *tmp = NULL;
	if (!pointer)
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
		tmp->token = 0;
		tmp->priority = 0;
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
		tmp->token = 0;
		tmp->priority = 0;
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
		printf("%s ", tmp->name);
		tmp = tmp->next;
	}
}