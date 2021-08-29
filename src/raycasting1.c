/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sreicher <sreicher@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/02 14:05:47 by sreicher          #+#    #+#             */
/*   Updated: 2020/11/04 16:40:15 by sreicher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void				put_color_to_pixel(t_env *e, int x, int y, int color)
{
	int				pixel;

	pixel = (x + y * e->win->x_win);
	e->img.data[pixel] = color;
}

void				verline(int x, t_env *e)
{
	while (e->rc->drawstart < e->rc->drawend)
	{
		put_color_to_pixel(e, x, e->rc->drawstart, e->rc->color);
		e->rc->drawstart++;
	}
}

void				raycasting(t_env *e, int x)
{
	mlx_clear_window(e->win->mlx_ptr, e->win->win_ptr);
	while (x < e->win->x_win)
	{
		e->plr->camera_x = 2 * x / (double)e->win->x_win - 1;
		e->plr->ray_pos_x = e->plr->pos_x;
		e->plr->ray_pos_y = e->plr->pos_y;
		e->plr->ray_dir_x = e->plr->dir_x + e->plr->plane_x * e->plr->camera_x;
		e->plr->ray_dir_y = e->plr->dir_y + e->plr->plane_y * e->plr->camera_x;
		e->rc->mapx = (int)e->plr->ray_pos_x;
		e->rc->mapy = (int)e->plr->ray_pos_y;
		e->rc->deltadistx = sqrt(1 + (e->plr->ray_dir_y * e->plr->ray_dir_y)
				/ (e->plr->ray_dir_x * e->plr->ray_dir_x));
		e->rc->deltadisty = sqrt(1 + (e->plr->ray_dir_x * e->plr->ray_dir_x)
				/ (e->plr->ray_dir_y * e->plr->ray_dir_y));
		e->rc->hit = 0;
		e->rc->side = 0;
		raycasting2(e);
		if (e->rc->side == 1)
		{
			e->rc->color = e->rc->color / 2;
		}
		verline(x, e);
		x++;
	}
}

void				raycasting2(t_env *e)
{
	if (e->plr->ray_dir_x < 0)
	{
		e->rc->stepx = -1;
		e->rc->sidedistx = (e->plr->ray_pos_x - e->rc->mapx)
			* e->rc->deltadistx;
	}
	else
	{
		e->rc->stepx = 1;
		e->rc->sidedistx = (e->rc->mapx + 1.0 - e->plr->ray_pos_x)
			* e->rc->deltadistx;
	}
	if (e->plr->ray_dir_y < 0)
	{
		e->rc->stepy = -1;
		e->rc->sidedisty = (e->plr->ray_pos_y - e->rc->mapy)
			* e->rc->deltadisty;
	}
	else
	{
		e->rc->stepy = 1;
		e->rc->sidedisty = (e->rc->mapy + 1.0 - e->plr->ray_pos_y)
			* e->rc->deltadisty;
	}
	raycasting3(e);
}

void				raycasting3(t_env *e)
{
	while (e->rc->hit == 0)
	{
		if (e->rc->sidedistx < e->rc->sidedisty)
		{
			e->rc->sidedistx += e->rc->deltadistx;
			e->rc->mapx += e->rc->stepx;
			e->rc->side = 0;
		}
		else
		{
			e->rc->sidedisty += e->rc->deltadisty;
			e->rc->mapy += e->rc->stepy;
			e->rc->side = 1;
		}
		if (e->map->vertices2[e->rc->mapy][e->rc->mapx].z > 0)
			e->rc->hit = 1;
	}
	if (e->rc->side == 0)
		e->rc->perpwalldist = (e->rc->mapx - e->plr->ray_pos_x
		+ (1 - e->rc->stepx) / 2) / e->plr->ray_dir_x;
	else
		e->rc->perpwalldist = (e->rc->mapy - e->plr->ray_pos_y
		+ (1 - e->rc->stepy) / 2) / e->plr->ray_dir_y;
	raycasting4(e);
}
