/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmontani <tmontani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/04 15:32:53 by tmontani          #+#    #+#             */
/*   Updated: 2024/06/06 16:04:36 by tmontani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	mlx_start(map *map_info)
{
	
	map_info->mlx = mlx_init();
	map_info->window = mlx_new_window(map_info->mlx, 1920, 1080, "Hello world!");
	mlx_hook(map_info->window, 17, 0, mlx_test120, &map_info);
	mlx_loop(map_info->mlx);
}

