#include <stdio.h>
#include "../includes/share.h"

void			printf_back_to_front(t_list *temp)
{
	if (temp->front != 0)
		printf_back_to_front(temp->front);
	printf("%d ",temp->value);
}

void			printf_front_to_back(t_list *temp)
{
	while (temp != NULL)
	{
		printf("%d ",temp->value);
		temp = temp->back;
	}
}

void			printf_stack(t_stack *stack)
{
	printf("%c >> ", stack->id);
	if (stack->size > 0)
	{
		//printf_back_to_front(*(stack->tail));
		printf_front_to_back(*(stack->head));
	}
	printf("\n");
}