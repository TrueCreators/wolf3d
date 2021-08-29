/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sreicher <sreicher@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/31 14:11:21 by sreicher          #+#    #+#             */
/*   Updated: 2020/11/04 13:34:32 by sreicher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

int					one_string(char *file)
{
	int				fd;
	char			**sp_line;
	char			*nw_line;
	int				i;

	i = 0;
	if ((fd = open(file, O_RDONLY)) < 0)
		error_exit("File not exist");
	get_next_line(fd, &nw_line);
	sp_line = ft_strsplit(nw_line, ' ');
	while (sp_line[i])
	{
		free(sp_line[i]);
		i++;
	}
	if (i != 0)
		free(nw_line);
	free(sp_line);
	close(fd);
	return (i);
}

void				lenght_xy(char fd, t_map *map, char *file)
{
	char			**splt_line;
	int				x_pos;
	char			*new_line;
	int				y_pos;
	int				x_prev;

	y_pos = 0;
	x_prev = one_string(file);
	if (x_prev == 0)
		error_exit("No file or no map");
	while ((get_next_line(fd, &new_line)))
	{
		splt_line = ft_strsplit(new_line, ' ');
		x_pos = 0;
		while (splt_line[x_pos])
			x_pos++;
		if (x_prev != x_pos)
			error_exit("No valid file");
		freeall(splt_line, new_line);
		y_pos++;
	}
	map->width = x_pos;
	map->height = y_pos;
	if (y_pos < 1 || x_pos != map->width || !new_line)
		error_exit("Bad lines");
}

void				map_to_array(char fd, t_map *map)
{
	int				i;
	char			*new_line;

	i = 0;
	map->temp = ft_memalloc(sizeof(char **) * map->height);
	while ((get_next_line(fd, &new_line) > 0))
	{
		map->temp[i] = ft_strsplit(new_line, ' ');
		free(new_line);
		i++;
	}
}

void				init_map_content(t_env *e, t_map *map, int i)
{
	int				y;
	int				x;

	y = 0;
	x = 0;
	map->vertices2 = create_map(map);
	ft_putstr("create_map_OK\n");
	e->plr->valid = false;
	while (y < map->height)
	{
		while (x < map->width)
		{
			if (ft_strcmp(map->temp[i / map->width][i % map->width], "X") == 0)
				ft_init_player(e, i, x, y);
			else
				map->vertices2[y][x].z = ft_atoi(map->temp[i
						/ map->width][i % map->width]);
			i++;
			x++;
		}
		y++;
		x = 0;
	}
}
