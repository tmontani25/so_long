/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmontani <tmontani@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/06 14:58:15 by tmontani          #+#    #+#             */
/*   Updated: 2024/06/18 15:29:23 by tmontani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void    put_background(map *map_info)
{
    int y;
    int x;

    y = 0;
    x = 0;
    while (y < map_info->len_y)
    {
        x = 0;
        while (x < map_info->len_x)
        {
            if (map_info->map_array[y][x] == '1')
                mlx_put_image_to_window(map_info->mlx, map_info->window, map_info->wall_img, x * 32, y * 32);
            else
                mlx_put_image_to_window(map_info->mlx, map_info->window, map_info->ground_img, x * 32, y * 32);
            x++;
        }
        y++;
    }

}
void render_game(map *map_info)
{
    int y;
    int x;

    x = 0;
    y = - 1;
    put_background(map_info);
    while (++y < map_info->len_y)
    {
        x = -1;
        while (++x < map_info->len_x)
        {
            if (map_info->map_array[y][x] == 'C')
                mlx_put_image_to_window(map_info->mlx, map_info->window, map_info->coin_img, x * 32, y * 32);
            if (map_info->map_array[y][x] == 'P')
                mlx_put_image_to_window(map_info->mlx, map_info->window, map_info->player_img, x * 32, y * 32);
            if (map_info->map_array[y][x] == 'E')
            {
                if (map_info->c_count == map_info->coins)
                    mlx_put_image_to_window(map_info->mlx, map_info->window, map_info->exit_img, x * 32, y * 32);
                else
                    mlx_put_image_to_window(map_info->mlx, map_info->window, map_info->ground_img, x * 32, y * 32);
            }
        }
    }
}

int mlx_key_handler(int keycode, map *map_info)
{
    if (keycode == 53)
    {
        if (map_info->mlx && map_info->window) 
            close_handler(map_info);
    }
    if (keycode == 13) // 'W'
        move_up(map_info);
    if (keycode == 1) // 'S'
        move_down(map_info);
    if (keycode == 0) // 'A'
        move_left(map_info);
    if (keycode == 2 ) // 'D'
        move_right(map_info);
    if (map_info->c_count == map_info->coins)
        map_info->map_array[map_info->exit_y][map_info->exit_x] = 'E';
    render_game(map_info); // Mettre à jour le rendu après chaque mouvement
    return (0);
}

int close_handler(map *map_info)
{
    
    if(map_info->window && map_info->mlx)
    {
        mlx_destroy_window(map_info->mlx, map_info->window);
        free(map_info->map_array);
        exit(0);
    }
    return (0);
}
