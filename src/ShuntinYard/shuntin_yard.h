//
// Created by arnisfet on 17.12.22.
//

#ifndef SMART_CALC_SHUNTIN_YARD_H
#define SMART_CALC_SHUNTIN_YARD_H

#include "../Stack/stack.h"
#include <cstring>
#define is_num(c) ((c >= '0' && c <= '9'))

enum tokens {
	TOKEN_NONE,
	TOKEN_NUMBER,
	TOKEN_PLUS,
	TOKEN_MINUS,
	TOKEN_MULT,
	TOKEN_DIV,
	TOKEN_LEFTP,
	TOKEN_RIGHTP
	};

typedef struct S_List
{
	int number;
	S_List *next;
} List;

//Functions of the list structure

void	push_node(List **top, int number);
int 	pop_node(List **top);

#endif //SMART_CALC_SHUNTIN_YARD_H
