//
// Created by arnisfet on 04.01.23.
//

#include "containers.h"

float	ft_atof(const char *str)
{
	double	res;
	double	res2;
	char	*c;
	int		len;

	c = (char *)str;
	res = (double)ft_atoi(c);
	while (*c && *c != '.')
		c++;
	if (*c == '.')
		c++;
	res2 = (double)ft_atoi(c);
	len = ft_strlen(c);
	while (len--)
		res2 /= 10;
	return (res + ((res > 0) ? res2 : -res2));
}

/*********************** STACK ***************************/
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

char	*pop(Stack **head)
{
	char *value;
	Stack *tmp;
	if (*head == NULL)
		exit(EXIT_FAILURE);
	value = ft_strdup((*head)->name);
	tmp = *head;
	*head = (*head)->next;
	free(tmp->name);
	free(tmp);
	return (value);
}


void	fprint_stack(FStack *head)
{
	if (!head)
		exit(EXIT_FAILURE);
	while(head)
	{
		printf("%f\n", head->number);
		head = head->next;
	}
}

void	fpush(FStack **head, float number)
{
	FStack *p = NULL;
	if ((p = (FStack*)malloc(sizeof(FStack))) == NULL)
		exit (EXIT_FAILURE);
	p->next = *head;
	p->number = number;
	*head = p;
}

float	fpop(FStack **head)
{
	FStack *tmp;
	float value;
	if (*head == NULL)
		exit(EXIT_FAILURE);
	value = (*head)->number;
	tmp = *head;
	*head = (*head)->next;
	free(tmp);
	return (value);
}