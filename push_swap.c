/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kethouve <kethouve@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 15:58:30 by kethouve          #+#    #+#             */
/*   Updated: 2024/01/16 17:43:29 by kethouve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_ps(int ac, char **av, int split)
{
	int		i;
	int		max_index;
	t_list	data_list_a;

	data_list_a.lenght = 0;
	data_list_a.start = NULL;
	data_list_a.end = NULL;
	if (split == 1)
		i = 0;
	else
		i = 1;
	while (i < ac)
	{
		ft_lst_new(&data_list_a, ft_atoi(av[i]));
		i++;
	}
	if (!(check_list(&data_list_a)))
	{
		ft_del_lst(&data_list_a);
		write(1, "Error\n", 6);
		return ;
	}
	max_index = get_index(&data_list_a);
	begin_swap(&data_list_a, max_index);
	ft_del_lst(&data_list_a);
}

void	begin_swap(t_list *lst, int max_i)
{
	t_list	data_list_b;

	data_list_b.lenght = 0;
	data_list_b.start = NULL;
	data_list_b.end = NULL;
	if (!(check_sort(lst) && max_i > 0))
	{
		split_lst(lst, &data_list_b, max_i);
	}
	else
		return ;
}

void	split_lst(t_list *lst_a, t_list *lst_b, int max_i)
{
	t_num	*current;
	int		pivot;
	int		i;

	current = lst_a->start;
	i = max_i;
	while (lst_a->lenght > 3)
	{
		pivot = set_pivot(lst_a);
		if (current->index <= pivot && current->index < i - 2)
		{
			swap_p(lst_a, lst_b, 'b');
			check_b_order(lst_b, pivot);
		}
		else
			swap_r(lst_a, 'a');
		current = lst_a->start;
	}
	while (!(check_sort(lst_a)))
		sort_a(lst_a);
	quick_sort(lst_a, lst_b);
}

int	set_pivot(t_list *lst)
{
	t_num	*current;
	int		i;
	int		max;
	int		min;

	current = lst->start;
	max = current->index;
	min = current->index;
	i = 0;
	while (current != NULL)
	{
		if (current->index > max)
			max = current->index;
		if (current->index < min)
			min = current->index;
		current = current->next;
	}
	if (lst->lenght <= 100)
		i = (min + max) / 2;
	else
		i = min + 50;
	return (i);
}
