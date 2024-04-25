/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kethouve <kethouve@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 15:01:23 by kethouve          #+#    #+#             */
/*   Updated: 2023/12/05 15:07:25 by kethouve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

long long int	ft_atoi(char *s)
{
	long long int	i;
	long long int	result;
	long long int	valeur;
	long long int	count;

	i = 0;
	valeur = 1;
	result = 0;
	count = 0;
	while (s[i] == ' ' || (s[i] >= 9 && s[i] <= 13))
		i++;
	while (s[i] == '+' || s[i] == '-')
	{
		if (s[i] == '-')
			valeur = -1;
		i++;
		count++;
	}
	while (s[i] >= '0' && s[i] <= '9' && count < 2)
	{
		result = result * 10 + s[i] - 48;
		i++;
	}
	return (result * valeur);
}
