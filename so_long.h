/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmontani <tmontani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/03 14:23:22 by tmontani          #+#    #+#             */
/*   Updated: 2024/07/18 14:16:32 by tmontani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

//# include <mlx.h>
# include <fcntl.h>
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdbool.h>
# include "./mlx/mlx.h"
# include "ft_printf/ft_printf.h"

typedef struct t_map
{
	void	*mlx;
	void	*window;
	void	*ground_img;
	void	*wall_img;
	void	*player_img;
	void	*exit_img;
	void	*coin_img;
	int		player_x;
	int		player_y;
	int		coins;
	int		exit;
	int		len_x;
	int		len_y;
	int		c_count;
	int		moves;
	int		exit_x;
	int		exit_y;
	bool	window_should_close;
	char	**map_array;
	char	**map_cpy;
	bool	visited;

}	t_map;

int		ft_strlen(char *str);
char	**ft_split(char const *str, char sep);
int		check_rectangular_map(t_map *map_info);
int		check_walls(t_map *map_info);
void	map_parser(t_map *map_info);
char	**map_copy(t_map *map_info);
int		map_algo(t_map *map_info, int y, int x);
void	mlx_start(t_map *map_info);
int		mlx_key_handler(int keycode, t_map *map_info);
int		close_handler(t_map *map_info);
void	render_game(t_map *map_info);
void	move_up(t_map *map_info);
void	move_down(t_map *map_info);
void	move_left(t_map *map_info);
void	move_right(t_map *map_info);
void	render_coins(t_map *map_info, int x, int y);
void	render_player(t_map *map_info, int x, int y);
void	render_exit(t_map *map_info, int x, int y);
void	render_ground(t_map *map_info, int x, int y);
void	free_map(t_map *map_info);
#endif