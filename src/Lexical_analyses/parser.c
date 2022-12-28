//
// Created by arnisfet on 28.12.22.
//

#include "lexical_analyses.h"


void tokenaiser(Queue **pointer)
{
	Deque *tmp = NULL;
	tmp = (*pointer)->first;
	while(tmp)
	{
		if (tmp->name[0] == '+')
			tmp->token = TOKEN_PLUS;
		else if (tmp->name[0] == '*')
			tmp->token = TOKEN_MULT;
		else if (tmp->name[0] == '-' && !is_num(tmp->name[1]))
			tmp->token = TOKEN_MINUS;
		else if (tmp->name[0] == '/')
			tmp->token = TOKEN_DIVISION;
		else if (tmp->name[0] == '^')
			tmp->token = TOKEN_EXP;
		else if (tmp->name[0] == 'm')
			tmp->token = TOKEN_MOD;
		else if (tmp->name[0] == 'c' || (tmp->name[0] == 's'
		&& tmp->name[1] == 'i') || (tmp->name[0] == 's' && tmp->name[1] == 'q')
		|| tmp->name[0] == 't' || (tmp->name[0] == 'a' && tmp->name[1] == 'q')
		|| (tmp->name[0] == 'a' && tmp->name[1] == 's')
		|| (tmp->name[0] == 'a' && tmp->name[1] == 't')
		|| (tmp->name[0] == 'l' && tmp->name[1] == 'n')
		|| (tmp->name[0] == 'l' && tmp->name[1] == 'o'))
			tmp->token = TOKEN_FUNC;
		else if (tmp->name[0] == '(')
			tmp->token = OPEN_BR;
		else if (tmp->name[0] == ')')
			tmp->token = CLOSE_BR;
		else
			tmp->token = TOKEN_NUMBER;
		tmp = tmp->next;
	}
}

void parser(Queue **pointer)
{

}

int main()
{
	Queue *list;
	list = NULL;
	char output[255];
	char *input = "-23+sin(1)-(37)+ln-76/78*63^3";
	list = lexer(input, output, list);
	tokenaiser(&list);
	print_queue(&list);
	while(list->size)
	{
		free(pop_queue(&list));
		list->size--;
	}
	free(list);
}