//
// Created by arnisfet on 27.12.22.
//

#include "lexical_analyses.h"
#include "containers.h"
#include <math.h>



Queue	*shutin_yard(Queue **list)
{
	Queue *output = NULL; // Output deque
	Stack *stack = NULL;
	char *buffer = NULL;

	output = (Queue *)malloc(sizeof (Queue));
	Deque *tmp = (*list)->first; // Iterator
	while(tmp)
	{
		if (tmp->token == NUMBER)
			insert_queue_2(&output, tmp->name);
		else if (tmp->token == FUNCTION)
		{
			push(&stack, tmp->name);
			stack->priority = tmp->priority;
			stack->token = tmp->token;
		}
		else if (tmp->token == OPERATION)
		{
			while(stack && stack->priority >= tmp->priority)
			{
				buffer = pop(&stack);
				insert_queue_2(&output, buffer);
				free(buffer);
			}
			push(&stack, tmp->name);
			stack->priority = tmp->priority;
			stack->token = tmp->token;
		}
		else if (tmp->name[0] == '(')
		{
			push(&stack, tmp->name);
			stack->priority = tmp->priority;
			stack->token = tmp->token;
		}
		else if (tmp->name[0] == ')')
		{
			while (stack->name[0] != '(')
			{
				buffer = pop(&stack);
				insert_queue_2(&output, buffer);
				free(buffer);
			}
			buffer = pop(&stack);
			free(buffer);
			if (stack && stack->token == FUNCTION)
			{
				buffer = pop(&stack);
				insert_queue_2(&output, buffer);
				free(buffer);
			}
		}
		tmp = tmp->next;
	}
	while (stack)
	{
		buffer = pop(&stack);
		insert_queue_2(&output, buffer);
		free(buffer);
	}
	return (output);
}

void	calculating(Queue *list)
{
	Deque *tmp = NULL;
	FStack *fstack = NULL;
	float first = 0, second = 0;

	tmp = list->first;
	while (tmp)
	{
		if (tmp->token == NUMBER)
			fpush(&fstack, ft_atof(tmp->name));
		else if (tmp->token == OPERATION || tmp->token == FUNCTION)
		{
			if (tmp->token == OPERATION)
			{
				if (tmp->name[0] == '+')
					fpush(&fstack, fpop(&fstack)+fpop(&fstack));
				else if (tmp->name[0] == '-')
					fpush(&fstack, -(fpop(&fstack)-fpop(&fstack)));
				else if (tmp->name[0] == '*')
					fpush(&fstack, fpop(&fstack)*fpop(&fstack));
				else if (tmp->name[0] == '/')
				{
					second = fpop(&fstack);
					first = fpop(&fstack);
					fpush(&fstack, first/second);
				}
				else if (tmp->name[0] == '^')
					fpush(&fstack, powf(fpop(&fstack),fpop(&fstack)));
				else if (ft_strncmp(tmp->name, "mod", 10) == 0)
				{
					second = fpop(&fstack);
					first = fpop(&fstack);
					fpush(&fstack, fmodf(first, second));
				}
			}
			else
			{
				if (ft_strncmp(tmp->name, "sin",10) == 0)
					fpush(&fstack, sinf(fpop(&fstack)));
				else if (ft_strncmp(tmp->name, "cos",10) == 0)
					fpush(&fstack, cosf(fpop(&fstack)));
				else if (ft_strncmp(tmp->name, "tan",10) == 0)
					fpush(&fstack, tanf(fpop(&fstack)));
				else if (ft_strncmp(tmp->name, "asin",10) == 0)
					fpush(&fstack, asinf(fpop(&fstack)));
				else if (ft_strncmp(tmp->name, "acos",10) == 0)
					fpush(&fstack, acosf(fpop(&fstack)));
				else if (ft_strncmp(tmp->name, "atan",10) == 0)
					fpush(&fstack, atanf(fpop(&fstack)));
				else if (ft_strncmp(tmp->name, "log",10) == 0)
					fpush(&fstack, log10f(fpop(&fstack)));
				else if (ft_strncmp(tmp->name, "ln",10) == 0)
					fpush(&fstack, logf(fpop(&fstack)));
				else if (ft_strncmp(tmp->name, "sqrt",10) == 0)
					fpush(&fstack, sqrtf(fpop(&fstack)));
			}
		}
		tmp = tmp->next;
	}
	printf("\nResult:\n");
	fprint_stack(fstack);
}

int main()
{
	Queue *list = NULL, *output = NULL;
	error = 0;
	char *input = "6.2 mod 2.3";
	list = lexer(input, list);
	tokenaiser(&list);
	parser(&list);
	printf("Первонаяальная очередь\n"
		   "******************************************\n");
	print_queue(&list);
	if (error == 0)
	{
		output = shutin_yard(&list);
		tokenaiser(&output);
		printf("\nSecond очередь\n"
			   "******************************************\n");
		print_queue(&output);
		calculating(output);
	}
	while(list->size)
	{
		free(pop_queue(&list));
		list->size--;
	}
	free(list);
}
