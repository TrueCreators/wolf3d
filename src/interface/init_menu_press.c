/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_menu_press.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sreicher <sreicher@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/29 19:50:19 by sreicher          #+#    #+#             */
/*   Updated: 2020/10/31 13:48:09 by sreicher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

static void			i_settings_press(t_env *e, int x_win, int y_win)
{
	(e->button)[35] = (t_butt) {150, 50, x_win / 2 - 200, y_win / 2 + 200,
	"<- BACK", RGB(0, 255, 0), 0};
	(e->button)[37] = (t_butt) {150, 50, x_win / 2 - 200, y_win / 2 + 100,
	"CREDITS", RGB(0, 255, 0), 0};
	(e->button)[38] = (t_butt) {150, 50, x_win / 2 - 200, y_win / 2 - 200,
	"CONTROLS", RGB(0, 255, 0), 0};
}

void				init_menu_press(t_env *e, int x_win, int y_win)
{
	(e->button)[22] = (t_butt) {250, 50, x_win / 2, y_win / 2 - 100,
	"PLAY", RGB(0, 255, 0), 0};
	(e->button)[23] = (t_butt) {250, 50, x_win / 2, y_win / 2 - 100,
	"CHANGE FRACTAL", RGB(0, 255, 0), 0};
	(e->button)[24] = (t_butt) {250, 50, x_win / 2, y_win / 2,
	"SETTINGS", RGB(0, 255, 0), 0};
	(e->button)[25] = (t_butt) {250, 50, x_win / 2, y_win / 2 + 100,
	"EXIT", RGB(0, 255, 0), 0};
	i_settings_press(e, x_win, y_win);
}
