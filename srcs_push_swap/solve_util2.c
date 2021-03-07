/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve_util2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: honlee <honlee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/04 12:39:34 by honlee            #+#    #+#             */
/*   Updated: 2021/03/04 13:55:59 by honlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/share.h"
#include "../includes/push_swap.h"

void			ft_order_min_r(t_stack *a, t_stack *b, size_t min_r)
{
	size_t		idx;

	idx = 0;
	while (idx < min_r)
	{
		ft_list_r(b, TRUE);
		idx++;
	}
	ft_list_move(b, a, TRUE);
	ft_list_r(a, TRUE);
}

void			ft_order_min_rr(t_stack *a, t_stack *b, size_t min_rr)
{
	size_t		idx;

	idx = 0;
	while (idx < min_rr)
	{
		ft_list_rr(b, TRUE);
		idx++;
	}
	ft_list_move(b, a, TRUE);
	ft_list_r(a, TRUE);
}

void			ft_order_max_r(t_stack *a, t_stack *b, size_t max_r)
{
	size_t		idx;

	idx = 0;
	while (idx < max_r)
	{
		ft_list_r(b, TRUE);
		idx++;
	}
	ft_list_move(b, a, TRUE);
	b->upper_cnt++;
}

void			ft_order_max_rr(t_stack *a, t_stack *b, size_t max_rr)
{
	size_t		idx;

	idx = 0;
	while (idx < max_rr)
	{
		ft_list_rr(b, TRUE);
		idx++;
	}
	ft_list_move(b, a, TRUE);
	b->upper_cnt++;
}

int				ft_get_next_pb(t_stack *a)
{
	t_list		*temp;
	size_t		idx;

	temp = *(a->head);
	a->min_r = a->size;
	a->min_rr = a->size;
	idx = 0;
	while (temp != 0)
	{
		if (temp->value <= a->max && temp->value >= a->min)
		{
			if (idx < a->min_r)
				a->min_r = idx;
			if (a->size - idx < a->min_rr)
				a->min_rr = a->size - idx;
		}
		idx++;
		temp = temp->back;
	}
	if (a->min_r < a->min_rr)
		return (a->min_r);
	return (a->min_rr);
}