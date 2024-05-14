/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmontani <tmontani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/03 14:19:50 by tmontani          #+#    #+#             */
/*   Updated: 2024/05/14 16:23:54 by tmontani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	map_parser(map map_info)
{
	if (!check_rectangular_map(map_info))
		printf("error map not rectangular\n");
	if(!check_walls(map_info))
		printf("map not enclosed in walls\n");
	
	
	//checker les erreurs de map
	//creer un algo qui determine si la map est faisable
}

char *ft_get_next_line(int fd)
{
	
	int	bytes_read;
	char *buf;
	
	buf = (char *)malloc(sizeof(char) * (1000));
	if (!buf)
	{
		free(buf);
		return (NULL);
	}
	bytes_read = read(fd, buf, 1000);
	return (buf);
}

int	main(void)
{
	int	fd;
	char	*stash;
	map	map_info;
	
	fd = open("map.ber", O_RDONLY);
	if (fd == -1)
	{
		printf("error open or file doesn't exist\n ");
	}
	stash = ft_get_next_line(fd);
	if (!stash)
	{
		printf("error no map\n");
	}
	printf("stash:\n%s", stash);
	map_info.my_map = ft_split(stash, '\n');
	map_parser(map_info);
}