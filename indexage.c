/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   indexage.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kethouve <kethouve@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 14:21:39 by kethouve          #+#    #+#             */
/*   Updated: 2024/01/09 15:15:29 by kethouve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_index(t_list *lst)
{
	t_list	data_list_temp;
	t_num	*current;
	int		max;

	data_list_temp.lenght = 0;
	data_list_temp.start = NULL;
	data_list_temp.end = NULL;
	current = lst->start;
	while (current != NULL)
	{
		ft_lst_new(&data_list_temp, current->value);
		current = current->next;
	}
	max = sort_temp(&data_list_temp);
	set_index(lst, &data_list_temp);
	ft_del_lst(&data_list_temp);
	return (max);
}

int	sort_temp(t_list *lst)
{
	t_num	*current;
	int		temp;

	current = lst->start;
	while (current != NULL)
	{
		if (current->next != NULL && current->next->value < current->value)
		{
			temp = current->value;
			current->value = current->next->value;
			current->next->value = temp;
			current = lst->start;
		}
		else
			current = current->next;
	}
	current = lst->start;
	temp = 0;
	while (current != NULL)
	{
		current->index = temp;
		temp++;
		current = current->next;
	}
	return (temp - 1);
}

void	set_index(t_list *lst_a, t_list *lst_t)
{
	t_num	*current;
	t_num	*current_temp;

	current = lst_a->start;
	current_temp = lst_t->start;
	while (current_temp != NULL)
	{
		if (current->value == current_temp->value)
		{
			current->index = current_temp->index;
			current = lst_a->start;
			current_temp = current_temp->next;
		}
		else
			current = current->next;
	}
}
