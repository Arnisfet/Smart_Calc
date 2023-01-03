//
// Created by arnisfet on 17.12.22.
//

#ifndef SMART_CALC_PARCER_H
#define SMART_CALC_PARCER_H

#include "containers.h"
#include "libft.h"

int error;

Queue 	*lexer(const char *input, Queue *list);
void	parser(Queue **pointer);
void tokenaiser(Queue **pointer);
void tokenaiser_to_yard(Queue **pointer);

#endif //SMART_CALC_PARCER_H
