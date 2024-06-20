/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmontani <tmontani@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 14:02:14 by tmontani          #+#    #+#             */
/*   Updated: 2024/06/20 13:14:28 by tmontani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		i++;
	}
	return (i);
}

int	check_col(char **map)
{
	int	lines;
	int	len;
	
	len = ft_strlen(map[0]) - 1;
	lines = 0;
	while (map[lines])
	{
		if (map[lines][0] != '1' || map[lines][len] != '1')
			return (0);
		lines++;
	}
	return (1);
}

int	check_lines(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] != '1')
			return (0);
		i++;
	}
	return (1);
}

int	check_walls(map *map_info)
{
	int	lines;

	lines = 0;
	if (!check_lines(map_info->map_array[0]))
		return (0);
	while (map_info->map_array[lines])
		lines++;
	lines = lines - 1;
	if (!check_lines(map_info->map_array[lines]))
		return (0);
	if (!check_col(map_info->map_array))
		return (0);
	return (1);
}

int	check_rectangular_map(map *map_info)
{
	int	len;
	int	lines;
	int	current_len;

	current_len = 0;
	lines = 0;
	len = ft_strlen(map_info->map_array[0]);
	while (map_info->map_array[lines])
	{
		current_len = ft_strlen(map_info->map_array[lines]);
		if (len != current_len)
			return (0);
		lines++;
	}
	return (1);
}
