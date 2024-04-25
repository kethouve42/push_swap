/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_errors.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kethouve <kethouve@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 14:54:56 by tken66            #+#    #+#             */
/*   Updated: 2024/01/16 17:43:43 by kethouve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_is_num(int ac, char **av, int i, int split)
{
	int	j;

	if (split == 1)
		j = 0;
	else
		j = 1;
	while (j < ac)
	{
		if (ft_atoi(av[j]) > 2147483647 || ft_atoi(av[j]) < -2147483648)
			return (write(1, "Error\n", 6), 0);
		while (av[j][i])
		{
			if (i > 10 || !((av[j][i] >= 48 && av[j][i] <= 57)
				|| av[j][i] == '-'))
				return (write(1, "Error\n", 6), 0);
			i++;
		}
		i = 0;
		j++;
	}
	return (1);
}

int	check_list(t_list *lst)
{
	t_num	*current;
	t_num	*next;

	current = lst->start;
	next = current->next;
	while (next != NULL && current != NULL)
	{
		while (current->value != next->value && next->next != NULL)
			next = next->next;
		if (current->value == next->value)
			return (0);
		current = current->next;
		next = current->next;
	}
	return (1);
}

int	check_sort(t_list *lst_a)
{
	t_num	*current;
	t_num	*next;

	current = lst_a->start;
	next = current->next;
	while (current != NULL && next != NULL)
	{
		if (current->value < next->value)
		{
			current = current->next;
			next = next->next;
		}
		else if (current->value > next->value)
			return (0);
	}
	return (1);
}
