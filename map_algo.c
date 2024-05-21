/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_algo.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmontani <tmontani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/17 14:29:41 by tmontani          #+#    #+#             */
/*   Updated: 2024/05/21 15:31:59 by tmontani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	map_copy(map *map_info)
{
	char **map_cpy;
	int x;
	int y;

	x = 0;
	y = 0;
	map_cpy = (char **)malloc(sizeof(char *) * (map_info->len_y));
	
	if (!map_cpy)
		return ;
	while (y < map_info->len_y)
	{
		map_cpy[y] = (char *)malloc(sizeof(char) * (map_info->len_x + 1));
		if (!map_cpy[y])
			return ;
		x = 0;
		while (x < map_info->len_x)
		{
			map_cpy[y][x] = map_info->map_array[y][x];
			x++;
		}
		map_cpy[y][x] = '\0';
		y++;
	}
	map_info->map_cpy = map_cpy;
}

// int map_algo(map *map_info)
// {
// 	static int  coins_count;
// 	static int  exit_count;
	
	
	//verifier si la position a deja ete visitee
		//faire une copie de la map et une fonction qui change les chiffres en 1 si la case a etee visitee
	//si sortie atteinte ok
	//si coins coins++
	//si position innacessible return
	//si non marque comme visitee
	//explore les 4 directions possibles avec appel recursif
//}