/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sreicher <sreicher@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/29 23:16:59 by sreicher          #+#    #+#             */
/*   Updated: 2020/11/04 16:40:34 by sreicher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

int				manipulate(int keycode, t_env *e)
{
	(void)keycode;
	(void)e;
	return (0);
}

void			ft_init_move(t_env *e)
{
	e->move->start = 0;
	e->move->time = 0;
	e->move->oldtime = 0;
	e->move->end = e->move->start;
	e->move->start = clock();
	e->move->frametime = (e->move->start - e->move->end) / CLOCKS_PER_SEC;
	e->move->movespeed = 0.1;
	e->move->rotspeed = 0.05;
}

void			move(int keycode, t_env *e)
{
	ft_init_move(e);
	mlx_clear_window(e->win->mlx_ptr, e->win->win_ptr);
	if (keycode == K_W || keycode == K_UP)
	{
		if (e->map->vertices2[(int)e->plr->pos_y][(int)(e->plr->pos_x
				+ e->plr->dir_x * e->move->movespeed)].z == 0)
			e->plr->pos_x += e->plr->dir_x * e->move->movespeed;
		if (e->map->vertices2[(int)(e->plr->pos_y + e->plr->dir_y
				* e->move->movespeed)][(int)e->plr->pos_x].z == 0)
			e->plr->pos_y += e->plr->dir_y * e->move->movespeed;
	}
	if (keycode == K_S || keycode == K_DOWN)
	{
		if (e->map->vertices2[(int)e->plr->pos_y][(int)(e->plr->pos_x
				- e->plr->dir_x * e->move->movespeed)].z == 0)
			e->plr->pos_x -= e->plr->dir_x * e->move->movespeed;
		if (e->map->vertices2[(int)(e->plr->pos_y - e->plr->dir_y
				* e->move->movespeed)][(int)e->plr->pos_x].z == 0)
			e->plr->pos_y -= e->plr->dir_y * e->move->movespeed;
	}
	move2(keycode, e);
}

void			move2(int keycode, t_env *e)
{
	if (keycode == K_D || keycode == K_RIGHT)
	{
		e->move->olddirx = e->plr->dir_x;
		e->plr->dir_x = e->plr->dir_x * cos(e->move->rotspeed)
				- e->plr->dir_y * sin(e->move->rotspeed);
		e->plr->dir_y = e->move->olddirx * sin(e->move->rotspeed)
				+ e->plr->dir_y * cos(e->move->rotspeed);
		e->move->oldplanex = e->plr->plane_x;
		e->plr->plane_x = e->plr->plane_x * cos(e->move->rotspeed)
				- e->plr->plane_y * sin(e->move->rotspeed);
		e->plr->plane_y = e->move->oldplanex * sin(e->move->rotspeed)
				+ e->plr->plane_y * cos(e->move->rotspeed);
	}
	move3(keycode, e);
}

int				move3(int keycode, t_env *e)
{
	if (keycode == K_A || keycode == K_LEFT)
	{
		e->move->olddirx = e->plr->dir_x;
		e->plr->dir_x = e->plr->dir_x * cos(-e->move->rotspeed)
				- e->plr->dir_y * sin(-e->move->rotspeed);
		e->plr->dir_y = e->move->olddirx * sin(-e->move->rotspeed)
				+ e->plr->dir_y * cos(-e->move->rotspeed);
		e->move->oldplanex = e->plr->plane_x;
		e->plr->plane_x = e->plr->plane_x * cos(-e->move->rotspeed)
				- e->plr->plane_y * sin(-e->move->rotspeed);
		e->plr->plane_y = e->move->oldplanex * sin(-e->move->rotspeed)
				+ e->plr->plane_y * cos(-e->move->rotspeed);
	}
	draw(e);
	return (0);
}
