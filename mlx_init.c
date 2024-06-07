/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmontani <tmontani@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/04 15:32:53 by tmontani          #+#    #+#             */
/*   Updated: 2024/06/07 17:24:10 by tmontani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	mlx_start(map *map_info)
{
	
	map_info->mlx = mlx_init();
	map_info->window = mlx_new_window(map_info->mlx, 1920, 1080, "Hello world!");
	mlx_hook(map_info->window, 2, 0, mlx_key_handler, &map_info);
	mlx_mouse_hook(map_info->window, mouse_handler, &map_info);
	mlx_looop(map_info->mlx);
}

