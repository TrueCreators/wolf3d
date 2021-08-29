/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_menu.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sreicher <sreicher@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/28 15:03:53 by sreicher          #+#    #+#             */
/*   Updated: 2020/10/31 13:48:09 by sreicher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

static void			init_settings(t_env *e, int x_win, int y_win)
{
	(e->button)[13] = (t_butt) {150, 50, x_win / 2 - 200, y_win / 2 - 200,
	"CONTROLS", RGB(255, 255, 255), 0};
	(e->button)[14] = (t_butt) {500, 50, x_win / 2 + 200, y_win / 2 - 200,
	"INPUT                            DESCRIPTION", RGB(255, 255, 255), 0};
	(e->button)[15] = (t_butt) {500, 50, x_win / 2 + 200, y_win / 2 - 150,
	"W, A, S, D                        Move", RGB(255, 255, 255), 0};
	(e->button)[16] = (t_butt) {500, 50, x_win / 2 + 200, y_win / 2 - 100,
	"ARROWS                            Move", RGB(255, 255, 255), 0};
	(e->button)[21] = (t_butt) {150, 50, x_win / 2 - 200, y_win / 2 + 200,
	"<- BACK", RGB(255, 255, 255), 0};
	(e->button)[36] = (t_butt) {150, 50, x_win / 2 - 200, y_win / 2 + 100,
	"CREDITS", RGB(255, 255, 255), 0};
}

void				init_menu(t_env *e, int x_win, int y_win)
{
	(e->button)[0] = (t_butt) {250, 50, x_win / 2, y_win / 2 - 100,
	"PLAY", RGB(255, 255, 255), 0};
	(e->button)[2] = (t_butt) {250, 50, x_win / 2, y_win / 2,
	"SETTINGS", RGB(255, 255, 255), 0};
	(e->button)[3] = (t_butt) {250, 50, x_win / 2, y_win / 2 + 100,
	"EXIT", RGB(255, 255, 255), 0};
	init_settings(e, x_win, y_win);
}
