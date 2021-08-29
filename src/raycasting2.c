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

void				raycasting4(t_env *e)
{
	e->rc->lineheight = (int)(e->win->y_win / e->rc->perpwalldist);
	e->rc->drawstart = -e->rc->lineheight / 2 + e->win->y_win / 2;
	if (e->rc->drawstart < 0)
		e->rc->drawstart = 0;
	e->rc->drawend = e->rc->lineheight / 2 + e->win->y_win / 2;
	if (e->rc->drawend >= e->win->y_win)
		e->rc->drawend = e->win->y_win - 1;
	e->rc->color = 0xFFFFFF;
	if (e->map->vertices2[e->rc->mapy][e->rc->mapx].z == 1)
		e->rc->color = 0x00FFFF;
	else if (e->map->vertices2[e->rc->mapy][e->rc->mapx].z == 2)
		e->rc->color = 0x0000FF;
	else if (e->map->vertices2[e->rc->mapy][e->rc->mapx].z == 3)
		e->rc->color = 0xFF0000;
	else if (e->map->vertices2[e->rc->mapy][e->rc->mapx].z == 4)
		e->rc->color = 0xFFFF00;
	else
		e->rc->color = 0xFFFFFF;
}
