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
