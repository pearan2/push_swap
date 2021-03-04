/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_util1.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: honlee <honlee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/04 12:39:34 by honlee            #+#    #+#             */
/*   Updated: 2021/03/04 13:55:59 by honlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/share.h"

t_bool			is_num(const char *str)
{
	if (!str)
		return (FALSE);
	if (str[0] == '+' || str[0] == '-')
		str++;
	return (is_unum(str));
}

t_bool			is_unum(const char *str)
{
	size_t				idx;
	size_t				len;

	idx = 0;
	if (!str)
		return (FALSE);
	len = ft_strlen(str);
	if (len == 0)
		return (FALSE);
	if (ft_strlen(str) == 1 && str[0] == '0')
		return (TRUE);
	if (str[0] == '0')
		return (FALSE);
	while (str[idx] != 0)
	{
		if (!(str[idx] <= '9' && str[idx] >= '0'))
			return (FALSE);
		idx++;
	}
	return (TRUE);
}

long long		to_long_long(const char *str)
{
	size_t		idx;
	t_bool		is_minus;
	long long	ret;

	idx = 0;
	ret = 0;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			is_minus = TRUE;
		str++;
	}
	while (str[idx] != 0)
	{
		if (is_minus == TRUE)
			ret = ret * 10 - (str[idx] - '0');
		else
			ret = ret * 10 + (str[idx] - '0');
		if (ret < INT_MIN || ret > INT_MAX)
			return (ret);
		idx++;
	}
	return (ret);
}

t_bool			is_param_valid(int ac, char **av)
{
	int			idx;

	idx = 1;
	while (idx < ac)
	{
		if (is_num(av[idx]) == FALSE)
			return (FALSE);
		idx++;
	}
	return (TRUE);
}
