/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   controls.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sreicher <sreicher@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/30 14:36:59 by sreicher          #+#    #+#             */
/*   Updated: 2020/10/31 19:58:03 by sreicher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

int		close_programm(void *param)
{
	(void)param;
	exit(1);
	return (0);
}

int		mouse_press(int button, int x, int y, t_env *e)
{
	button_pressed(button, x, y, e);
	draw(e);
	return (0);
}

int		mouse_move(int x, int y, t_env *e)
{
	(void)x;
	(void)y;
	(void)e;
	return (0);
}

int		key_press(int keycode, t_env *e)
{
	if (keycode == K_ESC)
		close_programm(((void *)0));
	if (keycode == NK_N1 || keycode == NK_N2 || keycode == NK_N3 ||
	keycode == NK_N0)
		key_change_window(keycode, e);
	if (keycode == NK_PLUS || keycode == NK_MINUS || keycode == K_PLUS
	|| keycode == K_MINUS)
		manipulate(keycode, e);
	if (keycode == K_W || keycode == K_A || keycode == K_S || keycode == K_D ||
keycode == K_UP || keycode == K_DOWN || keycode == K_LEFT || keycode == K_RIGHT)
		move(keycode, e);
	if (keycode == K_BACKSPACE)
	{
		e->flag.menu_glb = (e->flag.menu_glb + 1) % 2;
	}
	return (0);
}
