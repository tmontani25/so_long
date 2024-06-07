/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmontani <tmontani@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/06 14:58:15 by tmontani          #+#    #+#             */
/*   Updated: 2024/06/07 15:55:49 by tmontani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int mlx_key_handler(int keycode, void *param)
{
    map *map_info;

    map_info = (map *)param;
    if (keycode == 53)
    {
        mlx_destroy_window(map_info->mlx, map_info->window);
        exit(0);
    }
    if (keycode == 13) // 'W'
        map_info->player_y -= 1;
    if (keycode == 1) // 'S'
        map_info->player_y += 1;
    if (keycode == 0) // 'A'
        map_info->player_x -= 1;
    if (keycode == 2) // 'D'
        map_info->player_x += 1;

    //render_game(map_info); // Mettre à jour le rendu après chaque mouvement

    return (0);
}