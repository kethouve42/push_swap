/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kethouve <kethouve@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 16:18:34 by kethouve          #+#    #+#             */
/*   Updated: 2024/01/16 17:51:54 by kethouve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	char	**splitted;
	int		i;

	i = 0;
	if (argc == 1)
		return (0);
	if (argc == 2)
	{
		splitted = ft_split_arg(argv[1], ' ');
		if ((ft_is_num((tabs_size(argv[1], ' ')), splitted, 0, 1)))
			ft_ps((tabs_size(argv[1], ' ')), splitted, 1);
		while (splitted[i] != NULL)
		{
			free(splitted[i]);
			i++;
		}
		free(splitted);
		return (0);
	}
	else if (!(ft_is_num(argc, argv, 0, 0)))
		return (0);
	else
		ft_ps(argc, argv, 0);
	return (0);
}
