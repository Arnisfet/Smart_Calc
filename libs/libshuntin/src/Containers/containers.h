//
// Created by arnisfet on 17.12.22.
//

#ifndef SMART_CALC_CONTAINERS_H
#define SMART_CALC_CONTAINERS_H

#include <stdlib.h>
#include <stdio.h>
#include "libft.h"

#define is_num(c) ((c >= '0' && c <= '9'))

enum pars_tokens{
	NUMBER = 1,
	OPERATION,
	FUNCTION,
	BRACKET
};
/********* Stack of chars *************/
typedef struct StructStack
{
	char *name;
	enum pars_tokens token;
	int priority;
	struct StructStack *next;
} Stack;

/********* Stack of floats **************/
typedef struct FstructStack
{
	float	number;
	struct	FstructStack *next;
} FStack;


/************** Queue ******************/
typedef struct S_List
{
	char *name;
	struct S_List *next;
	enum pars_tokens token;
	int priority;
} Deque;

typedef struct S_Queue
{
	int size;
	Deque *first;
	Deque *last;
} Queue;

/************ Stack's functions *********/
void	print_stack(Stack *head);
void	push(Stack **head, char *name);
char	*pop(Stack **head);

void	fprint_stack(FStack *head);
void	fpush(FStack **head, float number);
float	fpop(FStack **head);

/*********** Queue's functions **********/
void init(Queue **pointer);
void insert_queue (Queue ***pointer, char *name);
void insert_queue_2 (Queue **pointer, char *name);// дааа..это я конечно молодец
char *pop_queue(Queue **pointer);
void	print_queue(Queue **pointer);

float	ft_atof(const char *str);

#endif //SMART_CALC_CONTAINERS_H
