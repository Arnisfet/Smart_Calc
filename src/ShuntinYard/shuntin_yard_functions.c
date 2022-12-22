//
// Created by arnisfet on 17.12.22.
//
#include "shuntin_yard.h"


void check_func(char **pointer, const char *input, int *i)
{
	if (ft_strnstr(input + *i, "ln", 2))
		for (int j = 2; j != 0; j--)
		{
			**pointer = input[*i];
			(*pointer)++, (*i)++;
		}
}

void	shuntin_yard(const char *input, char *output)
{

	char *pointer = NULL;
	pointer = output;
	for (int i = 0; input[i]; i++)
	{
		if (is_num(input[i]))
		{
			*pointer = input[i];
			pointer++;
		}
		if (input[i] == 'c' || input[i] == 's' || input[i] == 't' || input[i] == 'c'
		 || input[i] == 'a' || input[i] == 'l')
		{
			check_func(&pointer, input, &i);
		}
	}
}


int main()
{
	List *top;
	char output[255];
	const char *input = "1+2*ln(x)+ 2 * 8";
	shuntin_yard(input, output);
	printf("%s\n", output);
}