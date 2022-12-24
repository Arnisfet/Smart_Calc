//
// Created by arnisfet on 17.12.22.
//
#include "shuntin_yard.h"


void check_func(char **pointer, const char *input, int *i)
{
	char *string = NULL;
	if (ft_strnstr(input + *i, "ln", 2))
	{
		string = ft_substr(input, *i, 2);
		push_node(&list, string);
	}
	else if (ft_strnstr(input + *i, "log", 3))
	{
		string = ft_substr(input, *i, 3);
		push_node(&list, string);
	}
	else if (ft_strnstr(input + *i, "sqrt", 4))
	{
		string = ft_substr(input, *i, 4);
		push_node(&list, string);
	}
	else if (ft_strnstr(input + *i, "atan", 4))
	{
		string = ft_substr(input, *i, 4);
		push_node(&list, string);
	}
	else if (ft_strnstr(input + *i, "asin", 4))
	{
		string = ft_substr(input, *i, 4);
		push_node(&list, string);
	}
	else if (ft_strnstr(input + *i, "acos", 4))
	{
		string = ft_substr(input, *i, 4);
		push_node(&list, string);
	}
	else if (ft_strnstr(input + *i, "tan", 3))
	{
		string = ft_substr(input, *i, 3);
		push_node(&list, string);
	}
	else if (ft_strnstr(input + *i, "sin", 3))
	{
		string = ft_substr(input, *i, 3);
		push_node(&list, string);
	}
	else if (ft_strnstr(input + *i, "cos", 3))
	{
		string = ft_substr(input, *i, 3);
		push_node(&list, string);
	}
	else if (ft_strnstr(input + *i, "mod", 3))
	{
		string = ft_substr(input, *i, 3);
		push_node(&list, string);
	}
	free(string);
}

void	add_number(const char *input, int *i) {
	int start_point = *i;
	int end_point = 0;
	char *string = NULL;
	while (is_num(input[*i]))
		(*i)++;
	end_point = *i;
	if (end_point - start_point == 1)
		string = ft_substr(input, start_point, 1);
	else
		string = ft_substr(input, start_point, end_point - start_point);
	push_node(&list, string);
	free(string);
	(*i)--;
}

void	shuntin_yard(const char *input, char *output)
{

	char *pointer = NULL;
	pointer = output;
	for (int i = 0; input[i]; i++)
	{
		if (is_num(input[i]))
		{
			add_number(input, &i);
		}
		if (input[i] == 'c' || input[i] == 's' || input[i] == 't' || input[i] == 'c'
		 || input[i] == 'a' || input[i] == 'l' || input[i] == 'm')
		{
			check_func(&pointer, input, &i);
		}

	}
}


int main()
{
	list = NULL;
	stack = NULL;
	char output[255];
	const char *input = "ln+12345+1+";
	shuntin_yard(input, output);
	print_list(&list);
	while(pop_node(&list))
		;
}