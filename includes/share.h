/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   share.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: honlee <honlee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/04 12:39:34 by honlee            #+#    #+#             */
/*   Updated: 2021/03/08 22:13:11 by honlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHARE_H
# define SHARE_H

# define INT_MAX 2147483647
# define INT_MIN -2147483648
# define ERR_MSG "Error\n"
# include <unistd.h>
# include <stdlib.h>

typedef enum		e_bool
{
	TRUE,
	FALSE
}					t_bool;

typedef	struct		s_list
{
	struct s_list	*front;
	struct s_list	*back;
	int				value;
}					t_list;

typedef struct		s_stack
{
	char			id;
	t_list			**head;
	t_list			**tail;
	int				min;
	int				max;
	size_t			sep_num;
	size_t			size;
	size_t			min_r;
	size_t			min_rr;
	size_t			max_r;
	size_t			max_rr;
	size_t			upper_cnt;
	t_bool			is_first;
}					t_stack;

int					get_next_line(char **line);
t_list				*ft_list_new(int value);
void				ft_list_pf(t_stack *stack, t_list *new);
void				ft_list_pb(t_stack *stack, t_list *new);
void				ft_list_move(t_stack *a, t_stack *b, t_bool is_print);
void				ft_list_r(t_stack *stack, t_bool is_print);
void				ft_list_rr(t_stack *stack, t_bool is_print);
t_stack				*ft_free_stack(t_stack *stack, int opt);
t_stack				*ft_make_stack(char id);
void				ft_list_s(t_stack *stack, t_bool is_print);
size_t				ft_strlen(const char *str);
t_bool				is_num(const char *str);
t_bool				is_unum(const char *str);
long long			to_long_long(const char *str);
int					ft_puterror(const char *str);
int					ft_putstr(const char *str);
t_list				*ft_free_list(t_list *list);
t_bool				is_param_valid(int ac, char **av);
void				ft_list_s_all(t_stack *a, t_stack *b, t_bool is_print);
void				ft_list_r_all(t_stack *a, t_stack *b, t_bool is_print);
void				ft_list_rr_all(t_stack *a, t_stack *b, t_bool is_print);
t_bool				ft_list_is_sorted(t_stack *stack);
void				ft_list_s_3(t_stack *stack);
t_bool				ft_is_dup_safe(t_stack *stack, int value);
int					ft_puterror_and_free1(t_stack *stack,
						const char *str, int opt);
int					ft_puterror_and_free2(t_stack *a,
						t_stack *b, const char *str, int opt);
int					ft_putorder(const char *str, t_stack *stack);
void				printf_stack(t_stack *stack);

#endif
