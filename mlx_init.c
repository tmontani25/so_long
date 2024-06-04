/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmontani <tmontani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/04 15:32:53 by tmontani          #+#    #+#             */
/*   Updated: 2024/06/04 15:59:12 by tmontani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"


int	window_innit(map *map_info)
{
    puts("00");

	map_info->mlx = mlx_init();
	map_info->window = mlx_new_window(map_info->mlx, 1920, 1080, "Hello world!");
	mlx_loop(map_info->mlx);
    return (0);
}
