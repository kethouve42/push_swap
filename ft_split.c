/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kethouve <kethouve@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 14:58:41 by kethouve          #+#    #+#             */
/*   Updated: 2024/01/16 17:51:46 by kethouve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_strlen(const char *s)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

char	*put_words(char const *s, int debut, int end)
{
	int		i;
	char	*word;

	i = 0;
	word = malloc(((end - debut) + 1) * sizeof(char));
	if (!word)
		return (0);
	while (debut < end)
	{
		word[i] = s[debut];
		i++;
		debut++;
	}
	word[i] = '\0';
	return (word);
}

int	tabs_size(char const *s, char c)
{
	int	i;
	int	count;
	int	j;

	i = 0;
	count = 0;
	j = 0;
	while (s[i])
	{
		if (s[i] != c && count == 0)
		{
			count = 1;
			j++;
		}
		else if (s[i] == c)
			count = 0;
		i++;
	}
	return (j);
}

char	**ft_split_arg(char const *s, char c)
{
	int			i;
	int			j;
	int			index;
	char		**dest;

	i = 0;
	j = 0;
	index = -1;
	dest = malloc((tabs_size(s, c) + 1) * sizeof(char *));
	if (!s || !dest)
		return (0);
	while (i <= ft_strlen(s))
	{
		if (s[i] != c && index < 0)
			index = i;
		else if ((s[i] == c || i == ft_strlen(s)) && index >= 0)
		{
			dest[j] = put_words(s, index, i);
			index = -1;
			j++;
		}
		i++;
	}
	dest[j] = NULL;
	return (dest);
}
