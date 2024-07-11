/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmontani <tmontani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/04 15:32:53 by tmontani          #+#    #+#             */
/*   Updated: 2024/07/11 16:38:31 by tmontani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	mlx_start(t_map *map_info)
{
	int	img_width;
	int	img_height;

	map_info->mlx = mlx_init();
	map_info->window = mlx_new_window(map_info->mlx, map_info->len_x * 32,
			map_info->len_y * 32, "so_long");
	map_info->ground_img = mlx_xpm_file_to_image(map_info->mlx,
			"./ground.xpm", &img_width, &img_height);
	map_info->wall_img = mlx_xpm_file_to_image(map_info->mlx, "./wall.xpm",
			&img_width, &img_height);
	map_info->coin_img = mlx_xpm_file_to_image(map_info->mlx, "./coin.xpm",
			&img_width, &img_height);
	map_info->player_img = mlx_xpm_file_to_image(map_info->mlx, "./player.xpm",
			&img_width, &img_height);
	map_info->exit_img = mlx_xpm_file_to_image(map_info->mlx, "./exit.xpm",
			&img_width, &img_height);
	render_game(map_info);
	mlx_hook(map_info->window, 2, 1L << 0, mlx_key_handler, map_info);
	mlx_hook(map_info->window, 17, 1L << 0, close_handler, map_info);
	mlx_loop(map_info->mlx);
}
