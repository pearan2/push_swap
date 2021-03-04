/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_util2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: honlee <honlee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/04 12:39:34 by honlee            #+#    #+#             */
/*   Updated: 2021/03/04 13:55:59 by honlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/share.h"

void			ft_list_r(t_stack *stack)
{
	t_list		*temp;
	t_list		*temp2;

	if (stack->size <= 1)
		return ;
	temp = *(stack->head);
	temp2 = temp->back;
	temp->back = NULL;
	temp->front = *(stack->tail);
	(*(stack->tail))->back = temp;
	*(stack->head) = temp2;
	ft_list_pb(stack, temp);
}

void			ft_list_rr(t_stack *stack)
{
	t_list		*temp;
	t_list		*temp2;

	if (stack->size <= 1)
		return ;
	temp = *(stack->tail);
	temp2 = temp->front;
	temp2->back = NULL;
	temp->front = NULL;
	*(stack->tail) = temp2;
	ft_list_pf(stack, temp);
}

t_stack			*ft_free_stack(t_stack *stack, int opt)
{
	if (!stack)
		return (NULL);
	if (opt == 2)
		free(stack->tail);
	if (opt == 1 || opt == 2)
	{
		if (*(stack->head) != NULL)
			ft_free_list(*(stack->head));
		free(stack->head);
	}
	free(stack);
	return (NULL);
}

t_list			*ft_free_list(t_list *list)
{
	if (list->back != NULL)
		ft_free_list(list->back);
	free(list);
	return (NULL);
}

t_stack			*ft_make_stack(char id)
{
	t_stack		*ret;

	if (!(ret = malloc(sizeof(t_stack))))
		return (NULL);
	if (!(ret->head = malloc(sizeof(t_list *))))
		return (ft_free_stack(ret, 1));
	if (!(ret->tail = malloc(sizeof(t_list *))))
		return (ft_free_stack(ret, 2));
	ret->id = id;
	*(ret->head) = NULL;
	*(ret->tail) = NULL;
	ret->min = INT_MAX;
	ret->max = INT_MIN;
	ret->min_r = 0;
	ret->min_rr = 0;
	ret->max_r = 0;
	ret->max_rr = 0;
	return (ret);
}
