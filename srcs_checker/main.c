/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: honlee <honlee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/04 12:39:34 by honlee            #+#    #+#             */
/*   Updated: 2021/03/08 22:12:37 by honlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/share.h"

t_bool				order_mapper(char *od, t_stack *a, t_stack *b)
{
	if (od[0] == 's' && od[1] == 'a' && od[2] == 0)
		ft_list_s(a, FALSE);
	else if (od[0] == 's' && od[1] == 'b' && od[2] == 0)
		ft_list_s(b, FALSE);
	else if (od[0] == 's' && od[1] == 's' && od[2] == 0)
		ft_list_s_all(a, b, FALSE);
	else if (od[0] == 'p' && od[1] == 'a' && od[2] == 0)
		ft_list_move(b, a, FALSE);
	else if (od[0] == 'p' && od[1] == 'b' && od[2] == 0)
		ft_list_move(a, b, FALSE);
	else if (od[0] == 'r' && od[1] == 'a' && od[2] == 0)
		ft_list_r(a, FALSE);
	else if (od[0] == 'r' && od[1] == 'b' && od[2] == 0)
		ft_list_r(b, FALSE);
	else if (od[0] == 'r' && od[1] == 'r' && od[2] == 'a' && od[3] == 0)
		ft_list_rr(a, FALSE);
	else if (od[0] == 'r' && od[1] == 'r' && od[2] == 'b' && od[3] == 0)
		ft_list_rr(b, FALSE);
	else if (od[0] == 'r' && od[1] == 'r' && od[2] == 'r' && od[3] == 0)
		ft_list_rr_all(a, b, FALSE);
	else if (od[0] == 'r' && od[1] == 'r' && od[2] == 0)
		ft_list_r_all(a, b, FALSE);
	else
		return (FALSE);
	return (TRUE);
}

int					do_loop(t_stack *a, t_stack *b)
{
	int				ret;
	char			*line;
	t_bool			mapper_ret;

	while ((ret = get_next_line(&line)) > 0)
	{
		mapper_ret = order_mapper(line, a, b);
		free(line);
		line = 0;
		if (mapper_ret == FALSE)
			return (ft_puterror_and_free2(a, b, ERR_MSG, 2));
	}
	mapper_ret = order_mapper(line, a, b);
	free(line);
	line = 0;
	if (b->size == 0 && ft_list_is_sorted(a) == TRUE)
	{
		ft_free_stack(a, 2);
		ft_free_stack(b, 2);
		return (ft_putstr("OK\n"));
	}
	return (ft_putstr("KO\n"));
}

int					main(int ac, char **av)
{
	t_stack			*a;
	t_stack			*b;
	int				idx;
	long long		ret;

	idx = 1;
	if (ac == 1)
		return (0);
	if (is_param_valid(ac, av) == FALSE)
		return (ft_puterror(ERR_MSG));
	if (!(a = ft_make_stack('a')))
		return (ft_puterror(ERR_MSG));
	if (!(b = ft_make_stack('b')))
		return (ft_puterror_and_free1(a, ERR_MSG, 2));
	while (idx < ac)
	{
		ret = to_long_long(av[idx]);
		if (ret < INT_MIN || ret > INT_MAX || ft_is_dup_safe(a, ret) == FALSE)
			return (ft_puterror_and_free2(a, b, ERR_MSG, 2));
		ft_list_pb(a, ft_list_new((int)ret));
		idx++;
	}
	return (do_loop(a, b));
}
