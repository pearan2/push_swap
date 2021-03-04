/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string_util1.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: honlee <honlee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/04 12:39:34 by honlee            #+#    #+#             */
/*   Updated: 2021/03/04 13:55:59 by honlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/share.h"

size_t				ft_strlen(const char *str)
{
	size_t		ret;

	ret = 0;
	while (str[ret] != 0)
		ret++;
	return (ret);
}

int					ft_puterror(const char *str)
{
	write(2, str, ft_strlen(str));
	return (0);
}

int					ft_putstr(const char *str)
{
	write(1, str, ft_strlen(str));
	return (0);
}
