/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_util3.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: honlee <honlee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/04 12:39:34 by honlee            #+#    #+#             */
/*   Updated: 2021/03/04 13:55:59 by honlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/share.h"

void			ft_list_s(t_stack *stack)
{
	t_list		*temp;
	t_list		*temp2;

	if (stack->size <= 1)
		return ;
	if (stack->size == 2)
	{
		temp = *(stack->head);
		temp2 = *(stack->tail);
		temp2->front = NULL;
		temp2->back = temp;
		temp->back = NULL;
		temp->front = temp2;
		*(stack->head) = temp2;
		*(stack->tail) = temp;
	}
	else
		ft_list_s_3(stack);
}

void			ft_list_s_all(t_stack *a, t_stack *b)
{
	ft_list_s(a);
	ft_list_s(b);
}

void			ft_list_r_all(t_stack *a, t_stack *b)
{
	ft_list_r(a);
	ft_list_r(b);
}

void			ft_list_rr_all(t_stack *a, t_stack *b)
{
	ft_list_rr(a);
	ft_list_rr(b);
}

t_bool			ft_list_is_sorted(t_stack *stack)
{
	int			before_value;
	int			now_value;
	t_list		*temp;

	before_value = INT_MIN;
	if (stack->size <= 1)
		return (TRUE);
	temp = *(stack->head);
	while (temp != 0)
	{
		now_value = temp->value;
		if (before_value > now_value)
			return (FALSE);
		before_value = now_value;
		temp = temp->back;
	}
	return (TRUE);
}