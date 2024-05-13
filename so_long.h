/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmontani <tmontani@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/03 14:23:22 by tmontani          #+#    #+#             */
/*   Updated: 2024/05/03 14:55:24 by tmontani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <mlx.h>
# include "./get_next_line/get_next_line.h"
# include <fcntl.h>
# include <stdio.h>

typedef struct map
{
	int	player;
	int	coins;
	int	pos_x;
	int	pos_y;
	int	map_exit;
	
} map;

#endif