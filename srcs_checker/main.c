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

t_bool				order_mapper(char *od, t_stack *a, t_stack *b)
{
	if (od[0] == 's' && od[1] == 'a')
		ft_list_s(a);
	else if (od[0] == 's' && od[1] == 'b')
		ft_list_s(b);
	else if (od[0] == 's' && od[1] == 's')
		ft_list_s_all(a, b);
	else if (od[0] == 'p' && od[1] == 'a')
		ft_list_move(b, a);
	else if (od[0] == 'p' && od[1] == 'b')
		ft_list_move(a, b);
	else if (od[0] == 'r' && od[1] == 'a')
		ft_list_r(a);
	else if (od[0] == 'r' && od[1] == 'b')
		ft_list_r(b);
	else if (od[0] == 'r' && od[1] == 'r' && od[2] == 'a')
		ft_list_rr(a);
	else if (od[0] == 'r' && od[1] == 'r' && od[2] == 'b')
		ft_list_rr(b);
	else if (od[0] == 'r' && od[1] == 'r' && od[2] == 'r')
		ft_list_rr_all(a, b);
	else if (od[0] == 'r' && od[1] == 'r')
		ft_list_r_all(a, b);
	else
		return (FALSE);
	printf_stack(a);
	printf_stack(b);
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
			return (ft_puterror(ERR_MSG));
	}
	mapper_ret = order_mapper(line, a, b);
	free(line);
	line = 0;
	if (b->size == 0 && ft_list_is_sorted(a) == TRUE)
		return (ft_putstr("OK\n"));
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
		return (ft_puterror(ERR_MSG));
	while (idx < ac)
	{
		ret = to_long_long(av[idx]);
		if (ret < INT_MIN || ret > INT_MAX)
			return (ft_puterror(ERR_MSG));
		ft_list_pb(a, ft_list_new((int)ret));
		idx++;
	}
	return (do_loop(a, b));
}
