//
// Created by arnisfet on 28.12.22.
//

#include "lexical_analyses.h"

/* Варианты ошибок:
 * 	1. Две операции подряд
 * 	2. Не известный токен
 * 	3. Не корректное число
 * 	4. Отсутствие оператора после попадания аргумента*/

void tokenaiser(Queue **pointer)
{
	Deque *tmp = NULL;
	tmp = (*pointer)->first;
	while(tmp)
	{
		if (tmp->name[0] == '+')
			tmp->token = OPERATION, tmp->priority = 1;
		else if (tmp->name[0] == '*')
			tmp->token = OPERATION, tmp->priority = 2;
		else if (tmp->name[0] == '-' && !is_num(tmp->name[1]))
			tmp->token = OPERATION, tmp->priority = 1;
		else if (tmp->name[0] == '/')
			tmp->token = OPERATION, tmp->priority = 2;
		else if (tmp->name[0] == '^')
			tmp->token = OPERATION, tmp->priority = 3;
		else if (tmp->name[0] == 'm')
			tmp->token = OPERATION, tmp->priority = 2;
		else if (tmp->name[0] == 'c' || (tmp->name[0] == 's'
		&& tmp->name[1] == 'i') || (tmp->name[0] == 's' && tmp->name[1] == 'q')
		|| tmp->name[0] == 't' || (tmp->name[0] == 'a' && tmp->name[1] == 'q')
		|| (tmp->name[0] == 'a' && tmp->name[1] == 's')
		|| (tmp->name[0] == 'a' && tmp->name[1] == 't')
		|| (tmp->name[0] == 'l' && tmp->name[1] == 'n')
		|| (tmp->name[0] == 'l' && tmp->name[1] == 'o'))
			tmp->token = FUNCTION, tmp->priority = 4;
		else if (tmp->name[0] == '(')
			tmp->token = BRACKET, tmp->priority = 0;
		else if (tmp->name[0] == ')')
			tmp->token = BRACKET, tmp->priority = 0;
		else
			tmp->token = NUMBER, tmp->priority = 0;
		tmp = tmp->next;
	}
}

void	check_operations(Queue **pointer)
{
	Deque *tmp = NULL;
	int bracket = 0;

	tmp = (*pointer)->first;
	while (tmp)
	{
		if (tmp->token == BRACKET) // Условие для четности скобок
		{
			if (tmp->next && tmp->next->token == BRACKET)
				error = 7;
			bracket++;
		} // Остальные условия
		if (tmp->token == NUMBER && tmp->next && tmp->next->token == NUMBER)
			error = 2;
		else if (tmp->token == OPERATION && tmp->next && tmp->next->token == OPERATION)
			error = 3;
		else if (tmp->token == FUNCTION && tmp->next && tmp->next->token ==	FUNCTION)
			error = 4;
		else if (tmp->token == FUNCTION && tmp->next && tmp->next->token != BRACKET)
			error = 8;
		else if (tmp->token == FUNCTION && !tmp->next)
			error = 9;
		else if (tmp->token == OPERATION && !tmp->next)
			error = 10;
		tmp = tmp->next;
	}
	if (bracket % 2 != 0)
		error = 6;

}

void	parser(Queue **pointer) {
	check_operations(pointer);
	if (error == 2) {
		printf("Некорректное выражение: Два числа подряд.\n");
	}
	if (error == 3) {
		printf("Некорректное выражение: Два оператора подряд.\n");
	}
	if (error == 4) {
		printf("Некорректное выражение: Две функции подряд.\n");
	}
	if (error == 6) {
		printf("Некорректное выражение: Нечетное количество скобок\n");
	}
	if (error == 7) {
		printf("Некорректное выражение: Нулевой аргумент функции\n");
	}
	if (error == 8) {
		printf("Некорректное выражение: Функция без открывающей скобки\n");
	}
	if (error == 9) {
		printf("Некорректное выражение: Функция без открывающей скобки\n");
	}
	if (error == 10) {
		printf("Некорректное выражение: Оператор единстенный элемент или не "
			   "законченное выражение"
			   "\n");
	}
}
