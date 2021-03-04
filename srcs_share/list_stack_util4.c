/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_util4.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: honlee <honlee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/04 12:39:34 by honlee            #+#    #+#             */
/*   Updated: 2021/03/04 13:55:59 by honlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/share.h"

void			ft_list_s_3(t_stack *stack)
{
	t_list		*temp;
	t_list		*temp2;
	t_list		*temp3;

	temp = *(stack->head);
	temp2 = temp->back;
	temp3 = temp2->back;
	*(stack->head) = temp2;
	temp2->front = NULL;
	temp2->back = temp;
	temp->front = temp2;
	temp->back = temp3;
	temp3->front = temp;
}

t_bool			ft_is_dup_safe(t_stack *stack, int value)
{
	t_list		*list;

	list = *(stack->head);
	while (list != NULL)
	{
		if (list->value == value)
			return (FALSE);
		list = list->back;
	}
	return (TRUE);
}

int				ft_puterror_and_free1(t_stack *stack, const char *str, int opt)
{
	ft_free_stack(stack, opt);
	return (ft_puterror(str));
}

int				ft_puterror_and_free2(t_stack *a,
						t_stack *b, const char *str, int opt)
{
	ft_free_stack(a, opt);
	ft_free_stack(b, opt);
	return (ft_puterror(str));
}
