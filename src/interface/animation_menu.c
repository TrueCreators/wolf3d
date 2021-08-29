/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animation_menu.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sreicher <sreicher@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/29 22:11:13 by sreicher          #+#    #+#             */
/*   Updated: 2020/10/31 20:12:27 by sreicher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

int				animation_menu(t_env *e)
{
	if (e->flag.background)
	{
		e->move->olddirx = e->plr->dir_x;
		e->plr->dir_x = e->plr->dir_x * cos(0.01)
				- e->plr->dir_y * sin(0.01);
		e->plr->dir_y = e->move->olddirx * sin(0.01)
				+ e->plr->dir_y * cos(0.01);
		e->move->oldplanex = e->plr->plane_x;
		e->plr->plane_x = e->plr->plane_x * cos(0.01)
				- e->plr->plane_y * sin(0.01);
		e->plr->plane_y = e->move->oldplanex * sin(0.01)
				+ e->plr->plane_y * cos(0.01);
		draw(e);
	}
	return (0);
}
