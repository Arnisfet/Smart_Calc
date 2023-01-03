//
// Created by arnisfet on 27.12.22.
//

#include "lexical_analyses.h"
#include "containers.h"




int main()
{
	Queue *list;
	list = NULL;
	error = 0;
	char *input = "23+sin(1)-(37)+ln-76/78*63.67877777^3";
	list = lexer(input, list);
	tokenaiser(&list);
	parser(&list);
	print_queue(&list);
	if (error == 0)
	{

	}
	while(list->size)
	{
		free(pop_queue(&list));
		list->size--;
	}
	free(list);
}
