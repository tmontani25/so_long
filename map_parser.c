/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parser.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmontani <tmontani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 14:42:05 by tmontani          #+#    #+#             */
/*   Updated: 2024/07/18 13:42:55 by tmontani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	find_player_y(t_map *map_info)
{
	int	lines;
	int	x;

	lines = 0;
	while (map_info->map_array[lines])
	{
		x = 0;
		while (map_info->map_array[lines][x])
		{
			if (map_info->map_array[lines][x] == 'P')
			{
				map_info->player_y = lines;
				map_info->player_x = x;
			}
			x++;
		}
		lines++;
	}
}

int	ft_strchr_array(char **array, char c, t_map *map_info)
{
	int	lines;
	int	x;
	int	count;

	lines = 0;
	count = 0;
	while (array[lines])
	{
		x = 0;
		while (array[lines][x])
		{
			if (array[lines][x] == c)
			{
				if (c == 'E')
				{
					map_info->exit_x = x;
					map_info->exit_y = lines;
				}	
				count++;
			}
			x++;
		}
		lines++;
	}
	return (count);
}

void	map_parser(t_map *map_info)
{
	while (map_info->map_array[map_info->len_y])
		map_info->len_y++;
	map_info->len_x = ft_strlen(map_info->map_array[0]);
	map_info->exit = ft_strchr_array(map_info->map_array, 'E', map_info);
	if (map_info->exit != 1)
	{
		printf("0 or too many Exit\n");
		return ;
	}
	map_info->coins = ft_strchr_array(map_info->map_array, 'C', map_info);
	if (map_info->coins == 0)
	{
		printf("no coins");
		return ;
	}
	if (ft_strchr_array(map_info->map_array, 'P', map_info) != 1)
	{
		printf("wrong nb of player\n");
		return ;
	}
	find_player_y(map_info);
}
