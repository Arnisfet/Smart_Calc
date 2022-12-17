//
// Created by arnisfet on 17.12.22.
//
#include "shuntin_yard.h"
#include "../Stack/stack.h"



void	shuntin_yard(const char *input)
{
	const char *strbegin = input;
	const char *strend = input + strlen(input);
	char number[12];
	char c;

	while (strbegin < strend)
	{
		c = *strbegin;
		if (c != ' ')
		{
			if (is_num(c))
			{
				*output = c;
				output++;
			}
		}
		strbegin++;
	}
	printf("%s\n", output);
}


int main()
{
	const char *input = "1 + 2 * 8";
	shuntin_yard(input);
}