/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_stack_util1.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: honlee <honlee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/04 12:39:34 by honlee            #+#    #+#             */
/*   Updated: 2021/03/09 00:12:56 by honlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/share.h"

t_list			*ft_list_new(int value)
{
	t_list		*ret;

	if (!(ret = malloc(sizeof(t_list))))
		return (NULL);
	ret->value = value;
	ret->back = NULL;
	ret->front = NULL;
	return (ret);
}

void			ft_list_pf(t_stack *stack, t_list *new)
{
	t_list		*temp;

	temp = *(stack->head);
	if (new)
	{
		if (stack->size == 0)
		{
			*(stack->head) = new;
			*(stack->tail) = new;
			stack->size = 1;
		}
		else
		{
			temp->front = new;
			new->back = temp;
			*(stack->head) = new;
			stack->size++;
		}
	}
}

void			ft_list_pb(t_stack *stack, t_list *new)
{
	t_list		*temp;

	temp = *(stack->tail);
	if (new)
	{
		if (stack->size == 0)
		{
			*(stack->head) = new;
			*(stack->tail) = new;
			stack->size = 1;
		}
		else
		{
			new->front = temp;
			temp->back = new;
			*(stack->tail) = new;
			stack->size++;
		}
	}
}

void			ft_list_move(t_stack *a, t_stack *b, t_bool is_print)
{
	t_list		*temp;
	t_list		*temp2;

	if (is_print == TRUE)
		ft_putorder("p", b);
	if (a->size == 0 || a->head == NULL || *(a->head) == NULL)
		return ;
	if (a->size == 1)
	{
		temp = *(a->head);
		ft_list_pf(b, temp);
		temp->front = NULL;
		*(a->head) = NULL;
		a->size = 0;
		return ;
	}
	temp = *(a->head);
	temp2 = temp->back;
	temp2->front = NULL;
	temp->back = NULL;
	temp->front = NULL;
	ft_list_pf(b, temp);
	*(a->head) = temp2;
	a->size--;
}
