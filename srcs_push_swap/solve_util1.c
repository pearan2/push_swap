/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve_util1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: honlee <honlee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/04 12:39:34 by honlee            #+#    #+#             */
/*   Updated: 2021/03/09 00:25:17 by honlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/share.h"
#include "../includes/push_swap.h"

void			ft_sort_int_arr(int *arr, size_t size)
{
	size_t		i;
	size_t		j;
	int			tmp;

	i = 0;
	while (i++ < size)
	{
		j = 0;
		while (++j < size)
		{
			if (arr[j - 1] > arr[j])
			{
				tmp = arr[j - 1];
				arr[j - 1] = arr[j];
				arr[j] = tmp;
			}
		}
	}
}

void			ft_under_value_pb(t_stack *a, t_stack *b, int bb)
{
	size_t			idx;
	size_t			cnt;
	size_t			next_step;

	cnt = 0;
	while (cnt++ < a->sep_num)
	{
		idx = 0;
		next_step = ft_get_next_pb(a);
		if (next_step == a->min_r)
		{
			while (idx++ < next_step)
				ft_list_r(a, TRUE);
		}
		else
		{
			while (idx++ < next_step)
				ft_list_rr(a, TRUE);
		}
		ft_list_move(a, b, TRUE);
	}
	if (a->is_first == FALSE)
		while ((*(a->tail))->value != bb)
			ft_list_rr(a, TRUE);
	a->is_first = FALSE;
}

void			ft_calc_min_max(t_stack *b)
{
	t_list			*list;
	size_t			idx;

	list = *(b->head);
	idx = 0;
	b->max = INT_MIN;
	b->min = INT_MAX;
	while (list != 0)
	{
		if (list->value <= b->min)
		{
			b->min = list->value;
			b->min_r = idx;
			b->min_rr = b->size - idx;
		}
		if (list->value >= b->max)
		{
			b->max = list->value;
			b->max_r = idx;
			b->max_rr = b->size - idx;
		}
		list = list->back;
		idx++;
	}
}

size_t			ft_get_min(t_stack *b)
{
	size_t		ret;

	ret = b->size;
	if (ret >= b->min_r)
		ret = b->min_r;
	if (ret >= b->min_rr)
		ret = b->min_rr;
	if (ret >= b->max_r)
		ret = b->max_r;
	if (ret >= b->max_rr)
		ret = b->max_rr;
	return (ret);
}

void			ft_rollback_pa(t_stack *a, t_stack *b)
{
	size_t		next_step;

	b->upper_cnt = 0;
	while (b->size != 0)
	{
		ft_calc_min_max(b);
		next_step = ft_get_min(b);
		if (next_step == b->min_r)
			ft_order_min_r(a, b, next_step);
		else if (next_step == b->min_rr)
			ft_order_min_rr(a, b, next_step);
		else if (next_step == b->max_r)
			ft_order_max_r(a, b, next_step);
		else
			ft_order_max_rr(a, b, next_step);
	}
}
