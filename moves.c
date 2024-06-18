/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmontani <tmontani@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 15:07:36 by tmontani          #+#    #+#             */
/*   Updated: 2024/06/18 08:36:37 by tmontani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void    move_up(map *map_info)
{
    if (map_info->map_array[map_info->player_y - 1][map_info->player_x] == '1')
        return ;
    //if (map_info->map_array[map_info->player_y][map_info->player_x] == 'C')
      //  map_info->c_count;
    if (map_info->map_array[map_info->player_y][map_info->player_x] == 'E')
    {
        //if (map_info->c_count == map_info->coins)
            exit(0);
        //else
    }
    map_info->map_array[map_info->player_y][map_info->player_x] = '0';
    map_info->player_y = map_info->player_y - 1;
    map_info->map_array[map_info->player_y][map_info->player_x] = 'P';
   
  
}
void    move_down(map *map_info)
{
    if (map_info->map_array[map_info->player_y + 1][map_info->player_x] == '1')
        return ;
    //if (map_info->map_array[map_info->player_y][map_info->player_x] == 'C')
      //  map_info->c_count += 1;
    if (map_info->map_array[map_info->player_y + 1][map_info->player_x] == 'E')
    {
        //if (map_info->c_count == map_info->coins)
            exit(0);
        //else
    }
    map_info->map_array[map_info->player_y][map_info->player_x] = '0';
    map_info->player_y = map_info->player_y + 1;
        map_info->map_array[map_info->player_y][map_info->player_x] = 'P';
   
}
void    move_left(map *map_info)
{
    if (map_info->map_array[map_info->player_y][map_info->player_x - 1] == '1')
        return ;
    if (map_info->map_array[map_info->player_y + 1][map_info->player_x] == 'E')
    {
        //if (map_info->c_count == map_info->coins)
            exit(0);
        //else
    }
    map_info->map_array[map_info->player_y][map_info->player_x] = '0';
    map_info->player_x = map_info->player_x - 1;
    map_info->map_array[map_info->player_y][map_info->player_x] = 'P';
}

void move_right(map *map_info)
{
    if (map_info->map_array[map_info->player_y][map_info->player_x + 1] == '1')
        return ;
    if (map_info->map_array[map_info->player_y + 1][map_info->player_x] == 'E')
    {
        //if (map_info->c_count == map_info->coins)
            exit(0);
        //else
    }
    map_info->map_array[map_info->player_y][map_info->player_x] = '0';
    map_info->player_x = map_info->player_x + 1;
        map_info->map_array[map_info->player_y][map_info->player_x] = 'P';
   //if (map_info->map_array[map_info->player_y][map_info->player_x] == 'C')
     //   map_info->c_count += 1;
}