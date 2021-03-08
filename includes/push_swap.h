/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: honlee <honlee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/04 12:39:34 by honlee            #+#    #+#             */
/*   Updated: 2021/03/09 00:27:42 by honlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

void				ft_sort_int_arr(int *arr, size_t size);
void				ft_under_value_pb(t_stack *a, t_stack *b, int bb);
void				ft_calc_min_max(t_stack *b);
size_t				ft_get_min(t_stack *b);
void				ft_rollback_pa(t_stack *a, t_stack *b);
void				ft_order_min_r(t_stack *a, t_stack *b, size_t min_r);
void				ft_order_min_rr(t_stack *a, t_stack *b, size_t min_rr);
void				ft_order_max_r(t_stack *a, t_stack *b, size_t max_r);
void				ft_order_max_rr(t_stack *a, t_stack *b, size_t max_rr);
int					ft_get_next_pb(t_stack *a);
int					solve_2_3(t_stack *a);
size_t				ft_set_max_min(t_stack *a);
int					solve_4_5(t_stack *a, t_stack *b);

#endif
