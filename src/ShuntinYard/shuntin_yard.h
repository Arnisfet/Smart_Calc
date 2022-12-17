//
// Created by arnisfet on 17.12.22.
//

#ifndef SMART_CALC_SHUNTIN_YARD_H
#define SMART_CALC_SHUNTIN_YARD_H

#include <cstring>
#define is_num(c) ((c >= '0' && c <= '9'))

struct S_List
{
	char name;
	S_List *next;
} List;

#endif //SMART_CALC_SHUNTIN_YARD_H
