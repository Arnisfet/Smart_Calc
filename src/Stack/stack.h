//
// Created by arnisfet on 17.12.22.
//

#ifndef SMART_CALC_STACK_H
#define SMART_CALC_STACK_H

#include <stdlib.h>
#include <stdio.h>
#include "libft.h"

typedef struct StructStack
{
	char *name;
	struct StructStack *next;
} Stack;

void	print_stack(Stack *head);
void	push(Stack **head, char *name);
char	pop(Stack **head);

#endif //SMART_CALC_STACK_H
