/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmontani <tmontani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/06 14:58:15 by tmontani          #+#    #+#             */
/*   Updated: 2024/06/06 17:06:49 by tmontani         ###   ########.fr       */
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
    // if (keycode == 13)
    //     puts("up");
    // if (keycode == 0)
    //     puts("left");
    // if (keycode == 1)
    //     puts("down");
    // if (keycode == 2)
    //     puts("right");
    // return (0);
}