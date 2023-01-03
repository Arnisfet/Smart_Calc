//
// Created by arnisfet on 27.12.22.
//

#include "lexical_analyses.h"
#include "containers.h"

void	shutin_yard(Queue **list)
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
			if (stack->token == FUNCTION)
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
	printf("Second очередь\n"
		   "******************************************\n");
	print_queue(&output);

//	printf("STACK\n"
//		   "******************************************\n");
//	print_stack(stack);
}


int main()
{
	Queue *list;
	list = NULL;
	error = 0;
	char *input = "87*37+3^2*sin(1+7+8)";
	list = lexer(input, list);
	tokenaiser(&list);
	parser(&list);
	printf("Первонаяальная очередь\n"
		   "******************************************");
	print_queue(&list);
	if (error == 0)
		shutin_yard(&list);
	while(list->size)
	{
		free(pop_queue(&list));
		list->size--;
	}
	free(list);
}
