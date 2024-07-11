/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_algo.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmontani <tmontani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/17 14:29:41 by tmontani          #+#    #+#             */
/*   Updated: 2024/07/11 16:42:35 by tmontani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	**map_copy(t_map *map_info)
{
	char	**map_cpy;
	int		x;
	int		y;

	y = -1;
	map_cpy = (char **)malloc(sizeof(char *) * (map_info->len_y));
	if (!map_cpy)
		return (NULL);
	while (++y < map_info->len_y)
	{
		map_cpy[y] = (char *)malloc(sizeof(char) * (map_info->len_x + 1));
		if (!map_cpy[y])
			return (NULL);
		x = -1;
		while (++x < map_info->len_x)
			map_cpy[y][x] = map_info->map_array[y][x];
	}
	return (map_cpy);
}

int	map_algo(t_map *map_info, int y, int x)
{
	static int	coins_count = 0;
	static int	exit = 0;

	if (x < 0 || x > map_info->len_x || y < 0 || y > map_info->len_y)
		return (0);
	if (map_info->map_cpy[y][x] == '1')
		return (0);
	if (map_info->map_cpy[y][x] == 'E')
		exit = 1;
	if (map_info->map_cpy[y][x] == 'C')
		coins_count++;
	map_info->map_cpy[y][x] = '1';
	if (coins_count == map_info->coins && exit == 1)
		return (1);
	if (map_algo(map_info, y + 1, x))
		return (1);
	if (map_algo(map_info, y - 1, x))
		return (1);
	if (map_algo(map_info, y, x + 1))
		return (1);
	if (map_algo(map_info, y, x - 1))
		return (1);
	return (0);
}
