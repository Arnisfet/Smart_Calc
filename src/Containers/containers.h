//
// Created by arnisfet on 17.12.22.
//

#ifndef SMART_CALC_CONTAINERS_H
#define SMART_CALC_CONTAINERS_H

#include <stdlib.h>
#include <stdio.h>
#include "libft.h"

#define is_num(c) ((c >= '0' && c <= '9'))

enum tokens {
	TOKEN_NONE,
	TOKEN_NUMBER,
	TOKEN_PLUS,
	TOKEN_MINUS,
	TOKEN_FUNC,
	TOKEN_MOD,
	TOKEN_MULT,
	TOKEN_DIVISION,
	TOKEN_EXP,
	OPEN_BR,
	CLOSE_BR
};

enum pars_tokens{
	NUMBER = 1,
	OPERATION,
	FUNCTION,
	BRACKET
};

typedef struct StructStack
{
	char *name;
	struct StructStack *next;
} Stack;

typedef struct S_List
{
	char *name;
	struct S_List *next;
	enum pars_tokens token;
} Deque;

typedef struct S_Queue
{
	int size;
	Deque *first;
	Deque *last;
} Queue;

void	print_stack(Stack *head);
void	push(Stack **head, char *name);
char	*pop(Stack **head);

//Deque *list;
//Functions of the list structure

char *pop_queue(Queue **pointer);
void	print_queue(Queue **pointer);


void init(Queue **pointer);
void insert_queue (Queue ***pointer, char *name); // дааа..это я конечно молодец

#endif //SMART_CALC_CONTAINERS_H
