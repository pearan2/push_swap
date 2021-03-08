/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve_util3.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: honlee <honlee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/08 12:39:34 by honlee            #+#    #+#             */
/*   Updated: 2021/03/09 00:17:26 by honlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/share.h"
#include "../includes/push_swap.h"

size_t			ft_get_pos(t_stack *a, int num)
{
	t_list		*list;
	size_t		ret;

	ret = 0;
	list = *(a->head);
	while (list != 0)
	{
		if (list->value == num)
			return (ret);
		list = list->back;
		ret++;
	}
	return (ret);
}

size_t			ft_set_max_min(t_stack *a)
{
	t_list		*list;
	size_t		idx;
	size_t		ret;

	a->min = INT_MAX;
	a->max = INT_MIN;
	list = *(a->head);
	idx = 0;
	while (list != 0)
	{
		if (list->value < a->min)
			a->min = list->value;
		if (list->value > a->max)
		{
			a->max = list->value;
			ret = idx;
		}
		list = list->back;
		idx++;
	}
	return (ret);
}

int				solve_2_3(t_stack *a)
{
	size_t			max_pos;

	max_pos = ft_set_max_min(a);
	if (a->size == 2)
	{
		if (ft_list_is_sorted(a) == FALSE)
			ft_list_s(a, TRUE);
	}
	else
	{
		if (max_pos == 0)
			ft_list_r(a, TRUE);
		else if (max_pos == 1)
			ft_list_rr(a, TRUE);
		if (ft_list_is_sorted(a) == FALSE)
			ft_list_s(a, TRUE);
	}
	return (0);
}

int				solve_4_5(t_stack *a, t_stack *b)
{
	size_t			idx;
	size_t			iter;

	while (a->size != 3)
	{
		iter = 0;
		ft_set_max_min(a);
		idx = ft_get_pos(a, a->min);
		if (a->size - idx < idx)
			while (iter++ < a->size - idx)
				ft_list_rr(a, TRUE);
		else
			while (iter++ < idx)
				ft_list_r(a, TRUE);
		ft_list_move(a, b, TRUE);
	}
	solve_2_3(a);
	if (b->size == 2 && ((*(b->head))->value < (*(b->tail))->value))
		ft_list_s(b, TRUE);
	while (b->size != 0)
		ft_list_move(b, a, TRUE);
	return (0);
}
