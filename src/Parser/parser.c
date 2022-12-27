//
// Created by arnisfet on 17.12.22.
//
#include "parser.h"


void check_func(char *pointer, const char *input, int *i)
{
	char *string = NULL;
	if (ft_strnstr(input + *i, "ln", 2))
	{
		string = ft_substr(input, *i, 2);
		insert_queue(&list, string);
	}
	else if (ft_strnstr(input + *i, "log", 3))
	{
		string = ft_substr(input, *i, 3);
		insert_queue(&list, string);
	}
	else if (ft_strnstr(input + *i, "sqrt", 4))
	{
		string = ft_substr(input, *i, 4);
		insert_queue(&list, string);
	}
	else if (ft_strnstr(input + *i, "atan", 4))
	{
		string = ft_substr(input, *i, 4);
		insert_queue(&list, string);
	}
	else if (ft_strnstr(input + *i, "asin", 4))
	{
		string = ft_substr(input, *i, 4);
		insert_queue(&list, string);
	}
	else if (ft_strnstr(input + *i, "acos", 4))
	{
		string = ft_substr(input, *i, 4);
		insert_queue(&list, string);
	}
	else if (ft_strnstr(input + *i, "tan", 3))
	{
		string = ft_substr(input, *i, 3);
		insert_queue(&list, string);
	}
	else if (ft_strnstr(input + *i, "sin", 3))
	{
		string = ft_substr(input, *i, 3);
		insert_queue(&list, string);
	}
	else if (ft_strnstr(input + *i, "cos", 3))
	{
		string = ft_substr(input, *i, 3);
		insert_queue(&list, string);
	}
	else if (ft_strnstr(input + *i, "mod", 3))
	{
		string = ft_substr(input, *i, 3);
		insert_queue(&list, string);
	}
	free(string);
}

/***** This function add integers in the deque *****/

void	add_member(const char *input, int *i) {
	int start_point = *i;
	int end_point = 0;
	char *string = NULL;

	if (*i == 0 && input[*i] == '-') // Condition for the case like -123
		(*i)++;
	while (is_num(input[*i]))
		(*i)++;
	end_point = *i;
	if (end_point - start_point == 1 || end_point - start_point == 0)
		string = ft_substr(input, start_point, 1);
	else
		string = ft_substr(input, start_point, end_point - start_point);
	insert_queue(&list, string);
	free(string);
	if ( end_point - start_point != 0)
		(*i)--;
}

void	lexer(const char *input, char *output)
{
	char *pointer = NULL;
	pointer = output;
	for (int i = 0; input[i]; i++)
	{
		if (is_num(input[i]))
		{
			add_member(input, &i);
		}
		if (input[i] == 'c' || input[i] == 's' || input[i] == 't' || input[i] == 'c'
		 || input[i] == 'a' || input[i] == 'l' || input[i] == 'm')
			check_func(pointer, input, &i);
		if (input[i] == '+' || input[i] == '-' || input[i] == '*' || input[i]
		== '/')
		{
			if (i == 0 && input[i] == '+')
				continue ;
			if (i == 0 && input[i] == '-') // Condition for the case like -123
			{
				add_member(input, &i);
				continue ;
			}
			add_member(input, &i);
		}
	}
}


int main()
{
	list = NULL;
	stack = NULL;
	char output[255];
	const char *input = "-37+ln-76";
	list = (Queue *)malloc(sizeof (Queue));
	lexer(input, output);
	print_queue(&list);
	while(list->size)
	{
		free(pop_queue(&list));
		list->size--;
	}
	free(list);
}