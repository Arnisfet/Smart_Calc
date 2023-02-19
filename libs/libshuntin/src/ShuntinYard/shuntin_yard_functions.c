//
// Created by arnisfet on 27.12.22.
//

#include "lexical_analyses.h"
#include "containers.h"
#include <math.h>

/************ Алгоритм Сортировочной станции ************/

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

/********** Расчет полученных параметров **************/

float	calculating(Queue *list)
{
	Deque *tmp = NULL;
	FStack *fstack = NULL;
	float first = 0, second = 0, result = 0;

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
	result = fpop(&fstack);
	return (result);
}

/**************** Тело алгоритма *************/

float  result(char *input)
{
	Queue *list = NULL, *output = NULL;
	float result = 0;
	error = 0;

	list = lexer(input, list); // Бьем на лексемы
	tokenaiser(&list); // Токенизация лексем
	parser(&list); // Парсинг параметро на ошибки
//	printf("Первонаяальная очередь\n"
//		   "******************************************\n");
//	print_queue(&list);
	if (error == 0)
	{
		output = shutin_yard(&list);
		tokenaiser(&output);
//		printf("\nSecond очередь\n"
//			   "******************************************\n");
//		print_queue(&output);
		result = calculating(output);
		while(output->size) // Очистка выходной очереди
		{
			free(pop_queue(&output));
			output->size--;
		}
		free(output);
	}
	while(list->size) // Очистка изначальной очереди
	{
		free(pop_queue(&list));
		list->size--;
	}
	free(list);
	return (result);
}

//int main()
//{
//	char *input = "23.678+23.-ln(log(10))-200+sin(cos(tan(10)))+10 mod 43/27";
//	float i = result(input);
//	printf("\nResult: %f\n", i);
//
//}