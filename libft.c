/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmontani <tmontani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 20:05:15 by tmontani          #+#    #+#             */
/*   Updated: 2024/07/11 14:44:54 by tmontani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	count_word(const char *str, char sep)
{
	size_t	i;
	int		count;

	i = 0;
	count = 0;
	if (str[i] == '\0')
		return (0);
	while (str[i] == sep)
	{
		i++;
	}
	while (str[i])
	{
		if (str[i] != sep && (str[i + 1] == sep || str[i + 1] == '\0'))
			count++;
		i++;
	}
	return (count);
}

static void	ft_free(char **array, int j)
{
	while (j >= 0)
	{
		free(array[j]);
		j--;
	}
}

static char	*fill_word(const char *str, size_t len)
{
	char	*word;
	size_t	i;

	i = 0;
	word = malloc(sizeof(char) * (len + 1));
	if (!word)
		return (NULL);
	while (i < len)
	{
		word[i] = str[i];
		i++;
	}
	word[i] = '\0';
	return (word);
}

static char	**getword(const char *str, char sep, char **array, size_t j)
{
	size_t	len;
	size_t	i;
	size_t	a;

	i = 0;
	a = 0;
	while (a < j)
	{
		len = 0;
		while (str[i] == sep)
			i++;
		while (str[i + len] != sep && str[i + len])
			len++;
		array[a] = fill_word(str + i, len);
		i = i + len;
		a++;
	}
	return (array);
}

char	**ft_split(char const *str, char sep)
{
	char	**array;
	size_t	j;

	j = count_word(str, sep);
	if (!str && !sep)
		return (0);
	array = (char **)malloc(sizeof(char *) * (j + 1));
	if (!array)
		return (NULL);
	if (str[0] == '\0')
	{
		array[0] = 0;
		return (array);
	}
	array = getword(str, sep, array, j);
	if (!array)
		ft_free(array, j);
	array[j] = NULL;
	return (array);
}
