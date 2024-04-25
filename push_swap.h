/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kethouve <kethouve@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 16:04:20 by kethouve          #+#    #+#             */
/*   Updated: 2024/01/17 14:19:44 by kethouve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include <stddef.h>

typedef struct s_number
{
	int				value;
	int				index;
	struct s_number	*prev;
	struct s_number	*next;
}	t_num;

typedef struct s_list
{
	int		lenght;
	t_num	*start;
	t_num	*end;
}	t_list;

long long int		ft_atoi(char *s);
int					main(int argc, char **argv);
int					ft_is_num(int ac, char **av, int i, int split);
int					check_list(t_list *lst);
int					get_index(t_list *lst);
int					tabs_size(char const *s, char c);
int					check_sort(t_list *lst_a);
int					sort_temp(t_list *lst);
int					set_pivot(t_list *lst);
t_list				*ft_lst_new(t_list *lst, int data);
void				ft_ps(int ac, char **av, int split);
void				ft_lst_add_front(t_list *lst, int data, int index);
void				ft_del_lst(t_list *lst);
void				ft_del_one_lst(t_list *lst);
void				begin_swap(t_list *lst, int max_i);
void				little_swap(t_list *lst);
void				swap_s(t_list *lst, char c);
void				swap_r(t_list *lst, char c);
void				swap_rr(t_list *lst, char c);
void				swap_p(t_list *lst_src, t_list *lst_dest, char c);
void				swap_ss(t_list *lst_a, t_list *lst_b);
void				swap_rr2(t_list *lst_a, t_list *lst_b);
void				swap_rrr(t_list *lst_a, t_list *lst_b);
char				**ft_split_arg(char const *s, char c);
void				check_b_order(t_list *lst, int index);
void				split_lst(t_list *lst_a, t_list *lst_b, int max_i);
void				set_index(t_list *lst_a, t_list *lst_t);
void				quick_sort(t_list *lst_a, t_list *lst_b);
void				sort_a(t_list *lst_a);
void				sort_a2(t_list *lst);
void				set_b(t_list *lst_b, int i);
void				quick_sort_100(t_list *lst_a, t_list *lst_b);

#endif
