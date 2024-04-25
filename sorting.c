/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kethouve <kethouve@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 16:46:18 by kethouve          #+#    #+#             */
/*   Updated: 2024/01/15 14:27:19 by kethouve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_a(t_list *lst_a)
{
	if ((lst_a->start->index > lst_a->end->index
			&& lst_a->start->next->index < lst_a->end->index)
		|| (lst_a->start->index > lst_a->start->next->index
			&& lst_a->end->index < lst_a->start->next->index))
		swap_r(lst_a, 'a');
	else if (lst_a->start->index < lst_a->start->next->index
		&& lst_a->start->index > lst_a->end->index)
		swap_rr(lst_a, 'a');
	else if (lst_a->start->index > lst_a->start->next->index
		|| (lst_a->start->index < lst_a->start->next->index
			&& lst_a->end->index < lst_a->start->next->index))
		swap_s(lst_a, 'a');
}

void	quick_sort(t_list *lst_a, t_list *lst_b)
{
	int		i;
	t_num	*current_b;

	if (lst_b->lenght > 100)
	{
		current_b = lst_b->start;
		while (lst_b->lenght != 0)
		{
			i = 0;
			while (current_b->index <= lst_a->start->index - 3
				&& current_b->next != NULL)
			{
				i++;
				current_b = current_b->next;
			}
			if (i >= 1)
				set_b(lst_b, i);
			else if (current_b->index >= lst_a->start->index - 3)
				swap_p(lst_b, lst_a, 'a');
			sort_a2(lst_a);
			current_b = lst_b->start;
		}
	}
	else
		quick_sort_100(lst_a, lst_b);
}

void	set_b(t_list *lst_b, int i)
{
	if (i >= 1 && i <= lst_b->lenght / 2)
	{
		if (i == 1)
			swap_s(lst_b, 'b');
		else
			swap_r(lst_b, 'b');
	}
	else if (i > 1 && i > lst_b->lenght / 2)
		swap_rr(lst_b, 'b');
}

void	sort_a2(t_list *lst)
{
	if (lst->start->index > lst->start->next->index)
		swap_s(lst, 'a');
	else if (lst->start->index < lst->start->next->index - 1)
		swap_r(lst, 'a');
	else if (lst->end->index == lst->start->index - 1)
		swap_rr(lst, 'a');
}

void	quick_sort_100(t_list *lst_a, t_list *lst_b)
{
	int		i;
	t_num	*current_b;

	while (lst_b->lenght != 0)
	{
		current_b = lst_b->start;
		i = 0;
		while (current_b->index < lst_a->start->index - 1
			&& current_b->next != NULL)
		{
			i++;
			current_b = current_b->next;
		}
		if (i >= 1)
			set_b(lst_b, i);
		else if (current_b->index == lst_a->start->index - 1)
			swap_p(lst_b, lst_a, 'a');
		current_b = lst_b->start;
	}
}
