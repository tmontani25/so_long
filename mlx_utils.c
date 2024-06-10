/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmontani <tmontani@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/06 14:58:15 by tmontani          #+#    #+#             */
/*   Updated: 2024/06/10 16:21:57 by tmontani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int mlx_key_handler(int keycode, void *param)
{
    map *map_info2;

    map_info2 = (map *)param;
    /*if (keycode == 53)
    {
        if (map_info2->mlx && map_info2->window) 
        {
            mlx_destroy_window(map_info2->mlx, map_info2->window);
            exit(0);
        }
    }*/
    if (keycode == 13) // 'W'
        map_info2->player_y -= 1;
    if (keycode == 1) // 'S'
        map_info2->player_y += 1;
    if (keycode == 0) // 'A'
        map_info2->player_x -= 1;
    if (keycode == 2) // 'D'
        map_info2->player_x += 1;

    //render_game(map_info); // Mettre à jour le rendu après chaque mouvement
    return (0);
}

int close_handler(void *param)
{
    map *map_info = (map *)param;
    
    if(map_info->window && map_info->mlx)
    {
        mlx_destroy_window(map_info->mlx, map_info->window);
        free(map_info->map_array);
        exit(0);
    }
    return (0);
}