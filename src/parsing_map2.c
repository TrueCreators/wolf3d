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

t_xyz				**create_map(t_map *map)
{
	t_xyz			**vertices2;
	int				y;

	y = 0;
	if (!(vertices2 = (t_xyz **)malloc(sizeof(t_xyz *) * (map->height))))
		return (NULL);
	while (y < map->height)
	{
		if (!(vertices2[y] = (t_xyz *)malloc(sizeof(t_xyz) * (map->width))))
			return (NULL);
		y++;
	}
	return (vertices2);
}

void				ft_init_player(t_env *e, int i, int x, int y)
{
	e->map->vertices2[y][x].z = 0;
	e->plr->pos_x = i % e->map->width + 0.5f;
	e->plr->pos_y = i / e->map->width + 0.5f;
	e->plr->valid = true;
}

void				parsing_map(t_env *e, t_map *map, char *file)
{
	int				fd;
	int				fd2;
	FILE			*fp;

	fp = fopen(file, "rb");
	if (getc(fp) == EOF)
		error_exit("File Empty");
	if ((fd = open(file, O_RDONLY)) == -1)
		error_exit("File not exist");
	if ((fd2 = open(file, O_RDONLY)) == -1)
		error_exit("File not exist");
	lenght_xy(fd2, map, file);
	map_to_array(fd, map);
	ft_putstr("map_to_array_OK\n");
	init_map_content(e, map, 0);
	ft_putstr("init_map_content_OK\n");
	map_validation(e->plr, map, 0);
	ft_putstr("map_validation_OK\n");
}

void				map_validation(t_player *player, t_map *map, int i)
{
	int				y;
	int				x;

	y = 0;
	x = 0;
	if (!player->valid)
		error_exit("No player mark on the map or NOT SPACE in map");
	if (player->pos_x == 0 || player->pos_y == 0 || player->pos_x
			== map->width - 1 || player->pos_y == map->height - 1)
		error_exit("Player on a boarder");
	while (y < map->height)
	{
		while (x < map->width)
		{
			if (map->vertices2[0][x].z == 0 || map->vertices2[map->height
			- 1][x].z == 0 || map->vertices2[y][0].z == 0 ||
			map->vertices2[y][map->width - 1].z == 0)
				error_exit("Problem with map's border");
			i++;
			x++;
		}
		y++;
		x = 0;
	}
}
