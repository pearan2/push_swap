/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: honlee <honlee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/04 12:39:34 by honlee            #+#    #+#             */
/*   Updated: 2021/03/04 13:55:59 by honlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/share.h"
#include "../includes/push_swap.h"

static int			solve(t_stack *a, t_stack *b, size_t cs, int *arr)
{
	size_t			idx;
	int				bb;
	size_t			after_sort_num;
	size_t			before_sort_num;

	bb = 0;
	after_sort_num = 0;
	before_sort_num = 0;
	while (!(b->size == 0 && ft_list_is_sorted(a) == TRUE))
	{
		after_sort_num += cs;
		if (after_sort_num > a->size)
			after_sort_num = a->size;
		a->sep_num = after_sort_num - before_sort_num;
		a->max = arr[after_sort_num - 1];
		ft_under_value_pb(a, b, (*(a->tail))->value);
		ft_rollback_pa(a, b);
		idx = 0;
		while (idx < b->upper_cnt)
		{
			ft_list_r(a, TRUE);
			idx++;
		}
		a->min = a->max + 1;
		before_sort_num = after_sort_num;
	}
	return (0);
}

static int			do_solve(t_stack *a, t_stack *b)
{
	size_t			idx;
	int				*arr;
	t_list			*temp;

	if (!(arr = malloc(sizeof(int) * a->size)))
		return (ft_puterror_and_free2(a, b, ERR_MSG, 2));
	idx = 0;
	temp = *(a->head);
	while (idx < a->size)
	{
		arr[idx] = temp->value;
		idx++;
		temp = temp->back;
	}
	ft_sort_int_arr(arr, a->size);
	if (a->size <= 1)
		return (0);
	else if (a->size <= 3)
		return (solve_2_3(a, b));
	else if (a->size <= 6)
		return (solve_4_6(a, b));
	else if (a->size <= 100)
		return (solve(a, b, (a->size / 2) + 1, arr));
	else if (a->size <= 500)
		return (solve(a, b, (a->size / 4) + 1, arr));
	else
		return (solve(a, b, (a->size / 8) + 1, arr));
}

int					main(int ac, char **av)
{
	t_stack			*a;
	t_stack			*b;
	int				idx;
	long long		ret;

	idx = 0;
	if (ac == 1)
		return (0);
	if (is_param_valid(ac, av) == FALSE || !(a = ft_make_stack('a')))
		return (ft_puterror(ERR_MSG));
	if (!(b = ft_make_stack('b')))
		return (ft_puterror_and_free1(a, ERR_MSG, 2));
	while (++idx < ac)
	{
		ret = to_long_long(av[idx]);
		if (ret < INT_MIN || ret > INT_MAX || ft_is_dup_safe(a, ret) == FALSE)
			return (ft_puterror_and_free2(a, b, ERR_MSG, 2));
		if (ret < a->min)
			a->min = ret;
		ft_list_pb(a, ft_list_new((int)ret));
	}
	return (do_solve(a, b));
}
