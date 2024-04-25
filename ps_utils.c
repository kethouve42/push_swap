/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kethouve <kethouve@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 16:10:43 by kethouve          #+#    #+#             */
/*   Updated: 2024/01/09 18:01:04 by kethouve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*ft_lst_new(t_list *lst, int data)
{
	t_num	*new_node;

	new_node = (t_num *)malloc(sizeof(t_num));
	if (!new_node)
		return (NULL);
	new_node->value = data;
	new_node->next = NULL;
	if (lst->end == NULL)
	{
		lst->start = new_node;
		new_node->prev = NULL;
	}
	else
	{
		lst->end->next = new_node;
		new_node->prev = lst->end;
	}
	lst->lenght++;
	lst->end = new_node;
	new_node->index = 0;
	return (lst);
}

void	ft_lst_add_front(t_list *lst, int data, int index)
{
	t_num	*new_node;
	t_num	*current;

	current = lst->start;
	if (current == NULL)
	{
		ft_lst_new(lst, data);
		new_node = lst->start;
		new_node->index = index;
		return ;
	}
	new_node = (t_num *)malloc(sizeof(t_num));
	if (!new_node)
		return ;
	new_node->value = data;
	new_node->index = index;
	if (current != NULL)
	{
		new_node->prev = NULL;
		new_node->next = current;
		current->prev = new_node;
	}
	lst->start = new_node;
	lst->lenght += 1;
}

void	ft_del_lst(t_list *lst)
{
	t_num	*current;
	t_num	*next;

	current = lst->start;
	if (!lst)
		return ;
	while (current)
	{
		next = current->next;
		free(current);
		current = next;
	}
	lst->start = NULL;
	lst->end = NULL;
	lst->lenght = 0;
}

void	ft_del_one_lst(t_list *lst)
{
	t_num	*current;
	t_num	*next;

	current = lst->start;
	next = lst->start->next;
	if (!lst)
		return ;
	else
	{
		lst->start = next;
		free(current);
	}
	lst->lenght -= 1;
}

void	check_b_order(t_list *lst, int pivot)
{
	t_num	*current;

	current = lst->start;
	if (current->next != NULL)
	{
		if (current->index < pivot / 2)
			swap_r(lst, 'b');
		else if (current->index < current->next->index)
			swap_s(lst, 'b');
	}
}
