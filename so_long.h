/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmontani <tmontani@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/03 14:23:22 by tmontani          #+#    #+#             */
/*   Updated: 2024/06/14 17:35:05 by tmontani         ###   ########.fr       */
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


typedef struct map
{
	void	*mlx;
	void	*window;
	void	*ground_img;
	void	*wall_img;
	void	*player_img;
	void	*exit_img;
	void	*coin_img;
	int	player_x;
	int player_y;
	int	coins;
	int	exit;
	int	len_x;
	int len_y;
	bool	window_should_close;
	char	**map_array;
	char	**map_cpy;
	bool	visited;

} map;

int		ft_strlen(char *str);
char	**ft_split(char const *str, char sep);
int		check_rectangular_map(map *map_info);
int		check_walls(map *map_info);
void	map_parser(map *map_info);
char	**map_copy(map *map_info);
int		map_algo(map *map_info, int y, int x);
void	mlx_start(map *map_info);
int		mlx_key_handler(int keycode, map *map_info);
int		close_handler(map *map_info);
void	render_game(map *map_info);
#endif