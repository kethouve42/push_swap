/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kethouve <kethouve@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 13:18:37 by kethouve          #+#    #+#             */
/*   Updated: 2024/01/09 17:37:05 by kethouve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap_s(t_list *lst, char c)
{
	int	temp;
	int	temp2;

	temp = lst->start->next->value;
	temp2 = lst->start->next->index;
	lst->start->next->value = lst->start->value;
	lst->start->next->index = lst->start->index;
	lst->start->value = temp;
	lst->start->index = temp2;
	write(1, "s", 1);
	write(1, &c, 1);
	write(1, "\n", 1);
}

void	swap_p(t_list *lst_src, t_list *lst_dest, char c)
{
	t_num	*current;

	current = lst_src->start;
	ft_lst_add_front(lst_dest, current->value, current->index);
	ft_del_one_lst(lst_src);
	write(1, "p", 1);
	write(1, &c, 1);
	write(1, "\n", 1);
}

void	swap_r(t_list *lst, char c)
{
	t_num	*new_end;
	t_num	*new_debut;
	t_num	*prev_end;

	new_end = lst->start;
	new_debut = lst->start->next;
	prev_end = lst->end;
	lst->end = new_end;
	prev_end->next = lst->end;
	lst->end->prev = prev_end;
	lst->end->next = NULL;
	lst->start = new_debut;
	lst->start->prev = NULL;
	write(1, "r", 1);
	write(1, &c, 1);
	write(1, "\n", 1);
}

void	swap_rr(t_list *lst, char c)
{
	t_num	*new_end;
	t_num	*debut;
	t_num	*end;

	debut = lst->start;
	end = lst->end;
	new_end = lst->end->prev;
	end->next = debut;
	debut->prev = end;
	lst->start = end;
	lst->start->next = debut;
	lst->start->prev = NULL;
	lst->end = new_end;
	lst->end->next = NULL;
	write(1, "rr", 2);
	write(1, &c, 1);
	write(1, "\n", 1);
}
