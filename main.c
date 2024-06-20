/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmontani <tmontani@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/03 14:19:50 by tmontani          #+#    #+#             */
/*   Updated: 2024/06/20 13:15:55 by tmontani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	map_check_errors(map *map_info)
{
	if (!check_rectangular_map(map_info))
	{
		ft_printf("error map not rectangular\n");
		exit(0);
	}
	if (!check_walls(map_info))
	{
		ft_printf("map not enclosed in walls\n");
		exit(0);
	}
}

void	ft_get_next_line(int fd, map *map_info)
{
	int		bytes_read;
	char	*buf;

	buf = (char *)malloc(sizeof(char) * (5000));
	if (!buf)
		return ;
	bytes_read = read(fd, buf, 5000);
	if (bytes_read <= 0)
	{
		free(buf);
		exit(0);
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

	map_info.window_should_close = false;
	map_info.c_count = 0;
	if (argc != 2)
	{
		ft_printf("wrong nb of arguments\n");
		return (0);
	}
	else
		fd = open(argv[1], O_RDONLY);
	if (fd == -1)
		ft_printf("error open or file doesn't exist\n");
	ft_get_next_line(fd, &map_info);
	map_check_errors(&map_info);
	map_parser(&map_info);
	map_info.map_cpy = map_copy(&map_info);
	if (!map_algo(&map_info, map_info.player_y, map_info.player_x))
		return (write(2, "map impossible\n", 15));
	mlx_start(&map_info);
}
