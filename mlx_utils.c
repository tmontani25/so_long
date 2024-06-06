/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmontani <tmontani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/06 14:58:15 by tmontani          #+#    #+#             */
/*   Updated: 2024/06/06 16:04:26 by tmontani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int mlx_test120(int keycode, void *param)
{
     map *map_info = (map *)param;
    printf("hello");
    mlx_destroy_window(map_info->mlx, map_info->window);
    exit(0);
    
}