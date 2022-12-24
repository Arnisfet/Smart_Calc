//
// Created by arnisfet on 17.12.22.
//

#ifndef SMART_CALC_SHUNTIN_YARD_H
#define SMART_CALC_SHUNTIN_YARD_H

#include "stack.h"
#include "libft.h"
#define is_num(c) ((c >= '0' && c <= '9'))

enum tokens {
	TOKEN_NONE,
	TOKEN_NUMBER,
	TOKEN_PLUS,
	TOKEN_MINUS,
	TOKEN_FUNC,
	TOKEN_MOD,
};

typedef struct S_List
{
	char *name;
	struct S_List *next;
} Deque;

Deque *list;
Stack *stack;
//Functions of the list structure

void	push_node(Deque **top, char *name);
char	*pop_node(Deque **top);
void	print_list(Deque **top);


#endif //SMART_CALC_SHUNTIN_YARD_H
