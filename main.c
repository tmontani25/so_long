/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmontani <tmontani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/03 14:19:50 by tmontani          #+#    #+#             */
/*   Updated: 2024/05/24 15:41:31 by tmontani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	map_check_errors(map *map_info)
{
	if (!check_rectangular_map(map_info))
	{
		printf("error map not rectangular\n");
		return ;
	}
	if(!check_walls(map_info))
	{
		printf("map not enclosed in walls\n");
		return ;
	}
}

void	ft_get_next_line(int fd, map *map_info)
{
	int	bytes_read;
	char *buf;
	buf = (char *)malloc(sizeof(char) * (5000));
	if (!buf)
		return ;
	bytes_read = read(fd, buf, 5000);
	if (bytes_read < 0)
	{
		free(buf);
		return ;
	}
	map_info->map_array = ft_split(buf, '\n');
	if (!map_info->map_array)
	{
		free(map_info->map_array);
		return ;
	}
	
}

int	main(int argc, char **argv)
{
	int	fd;
	map	map_info;
	
	if (argc != 2)
	{
		write(2, "wrong nb of arguments", 21);
		return (0);
	}
	else
	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
		write(2, "error open or file doesn't exist\n", 33);
	ft_get_next_line(fd, &map_info);
	map_check_errors(&map_info);
	map_parser(&map_info);
	map_info.map_cpy = map_copy(&map_info);
	if (!map_algo(&map_info, map_info.player_y, map_info.player_x))
		return (write(2, "map impossible\n", 15));
}

