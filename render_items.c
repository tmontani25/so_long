/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_items.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmontani <tmontani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/11 17:34:08 by tmontani          #+#    #+#             */
/*   Updated: 2024/07/17 15:49:36 by tmontani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	render_coins(t_map *map_info, int x, int y)
{
	mlx_put_image_to_window(map_info->mlx, map_info->window,
		map_info->coin_img, x * 32, y * 32);
}

void	render_player(t_map *map_info, int x, int y)
{
	mlx_put_image_to_window(map_info->mlx, map_info->window,
		map_info->player_img, x * 32, y * 32);
}

void	render_exit(t_map *map_info, int x, int y)
{
	mlx_put_image_to_window(map_info->mlx, map_info->window,
		map_info->exit_img, x * 32, y * 32);
}

void	render_ground(t_map *map_info, int x, int y)
{
	mlx_put_image_to_window(map_info->mlx, map_info->window,
		map_info->ground_img, x * 32, y * 32);
}
