/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmontani <tmontani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/03 14:23:22 by tmontani          #+#    #+#             */
/*   Updated: 2024/05/14 16:12:22 by tmontani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

//# include <mlx.h>
# include <fcntl.h>
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>

typedef struct map
{
	int	player;
	int	coins;
	int	pos_x;
	int	pos_y;
	int	map_exit;
	int	len_x;
	int	len_y;
	char	**my_map;
	
} map;

int ft_strlen(char *str);
char	**ft_split(char const *str, char sep);
int	check_rectangular_map(map map_info);
int check_walls(map map_info);

#endif