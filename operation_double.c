/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation_double.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kethouve <kethouve@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 12:49:05 by kethouve          #+#    #+#             */
/*   Updated: 2024/01/09 17:40:02 by kethouve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap_ss(t_list *lst_a, t_list *lst_b)
{
	int	temp;
	int	temp2;

	temp = lst_a->start->next->value;
	temp2 = lst_a->start->next->index;
	lst_a->start->next->value = lst_a->start->value;
	lst_a->start->next->index = lst_a->start->index;
	lst_a->start->value = temp;
	lst_a->start->index = temp2;
	swap_s(lst_b, 's');
}

void	swap_rr2(t_list *lst_a, t_list *lst_b)
{
	t_num	*new_end;
	t_num	*new_debut;
	t_num	*prev_end;

	new_end = lst_a->start;
	new_debut = lst_a->start->next;
	prev_end = lst_a->end;
	lst_a->end = new_end;
	prev_end->next = lst_a->end;
	lst_a->end->prev = prev_end;
	lst_a->end->next = NULL;
	lst_a->start = new_debut;
	lst_a->start->prev = NULL;
	swap_r(lst_b, 's');
}

void	swap_rrr(t_list *lst_a, t_list *lst_b)
{
	t_num	*new_end;
	t_num	*debut;
	t_num	*end;

	debut = lst_a->start;
	end = lst_a->end;
	new_end = lst_a->end->prev;
	end->next = debut;
	debut->prev = end;
	lst_a->start = end;
	lst_a->start->next = debut;
	lst_a->start->prev = NULL;
	lst_a->end = new_end;
	lst_a->end->next = NULL;
	swap_rr(lst_b, 'r');
}
