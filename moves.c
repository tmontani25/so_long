/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmontani <tmontani@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 15:07:36 by tmontani          #+#    #+#             */
/*   Updated: 2024/06/18 15:26:44 by tmontani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void    move_up(map *map_info)
{
    map_info->moves++;
    ft_printf("%d\n", map_info->moves);
    if (map_info->map_array[map_info->player_y - 1][map_info->player_x] == '1')
        return ;
    if (map_info->map_array[map_info->player_y - 1][map_info->player_x] == 'C')
        map_info->c_count++;
    ft_printf("coins: %d\n", map_info->coins);
    ft_printf("c_count: %d\n", map_info->c_count);
    if (map_info->map_array[map_info->player_y - 1][map_info->player_x] == 'E')
    {
        map_info->exit_y = map_info->player_y - 1;
        map_info->exit_x = map_info->player_x;
        if (map_info->c_count == map_info->coins)
            exit(0);
    }
    map_info->map_array[map_info->player_y][map_info->player_x] = '0';
    map_info->player_y = map_info->player_y - 1;
    map_info->map_array[map_info->player_y][map_info->player_x] = 'P';

}
void    move_down(map *map_info)
{
    map_info->moves++;
    ft_printf("%d\n", map_info->moves);
    if (map_info->map_array[map_info->player_y + 1][map_info->player_x] == '1')
        return ;
    if (map_info->map_array[map_info->player_y + 1][map_info->player_x] == 'C')
        map_info->c_count += 1;
    //ft_printf("coins: %d\n", map_info->coins);
    //ft_printf("c_count: %d\n", map_info->c_count);
    if (map_info->map_array[map_info->player_y + 1][map_info->player_x] == 'E')
    {
        map_info->exit_y = map_info->player_y + 1;
        map_info->exit_x = map_info->player_x;
        if (map_info->c_count == map_info->coins)
            exit(0);
    }
    map_info->map_array[map_info->player_y][map_info->player_x] = '0';
    map_info->player_y = map_info->player_y + 1;
    map_info->map_array[map_info->player_y][map_info->player_x] = 'P';
    map_info->moves++;
}
void    move_left(map *map_info)
{
    map_info->moves++;
    ft_printf("%d\n", map_info->moves);
    if (map_info->map_array[map_info->player_y][map_info->player_x - 1] == '1')
        return ;
    if (map_info->map_array[map_info->player_y][map_info->player_x - 1] == 'C')
        map_info->c_count += 1;
    ft_printf("coins: %d\n", map_info->coins);
    ft_printf("c_count: %d\n", map_info->c_count);
    if (map_info->map_array[map_info->player_y][map_info->player_x - 1] == 'E')
    {
        map_info->exit_y = map_info->player_y;
        map_info->exit_x = map_info->player_x - 1;
        if (map_info->c_count == map_info->coins)
            exit(0);
    }
    map_info->map_array[map_info->player_y][map_info->player_x] = '0';
    map_info->player_x = map_info->player_x - 1;
    map_info->map_array[map_info->player_y][map_info->player_x] = 'P';

}

void move_right(map *map_info)
{
    map_info->moves++;
    ft_printf("%d\n", map_info->moves);
    if (map_info->map_array[map_info->player_y][map_info->player_x + 1] == '1')
        return ;
    if (map_info->map_array[map_info->player_y][map_info->player_x + 1] == 'C')
        map_info->c_count += 1;
    ft_printf("coins: %d\n", map_info->coins);
    ft_printf("c_count: %d\n", map_info->c_count);
    if (map_info->map_array[map_info->player_y][map_info->player_x + 1] == 'E')
    {
        map_info->exit_y = map_info->player_y;
        map_info->exit_x = map_info->player_x + 1;
        if (map_info->c_count == map_info->coins)
            exit(0);
    }
    map_info->map_array[map_info->player_y][map_info->player_x] = '0';
    map_info->player_x = map_info->player_x + 1;
    map_info->map_array[map_info->player_y][map_info->player_x] = 'P';
}