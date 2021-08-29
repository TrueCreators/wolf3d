/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sreicher <sreicher@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/30 15:11:56 by sreicher          #+#    #+#             */
/*   Updated: 2020/11/04 15:39:02 by sreicher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

static void		change_window_to_be_contined(int keycode, t_env *e)
{
	if (keycode == NK_N2)
	{
		e->win->x_win = 1024;
		e->win->y_win = 768;
		e->win->n_win = "Wolf 3D 1024x768";
	}
	if (keycode == NK_N3)
	{
		e->win->x_win = 800;
		e->win->y_win = 600;
		e->win->n_win = "Wolf 3D 800x600";
	}
}

int				key_change_window(int keycode, t_env *e)
{
	mlx_destroy_window(e->win->mlx_ptr, e->win->win_ptr);
	mlx_destroy_image(e->win->mlx_ptr, e->img.img_ptr);
	if (keycode == NK_N0)
	{
		e->win->x_win = 2560;
		e->win->y_win = 1600;
		e->win->n_win = "Wolf 3D 2560x1600";
	}
	if (keycode == NK_N1)
	{
		e->win->x_win = 1920;
		e->win->y_win = 1080;
		e->win->n_win = "Wolf 3D 1920x1080";
	}
	change_window_to_be_contined(keycode, e);
	init_win_img(e);
	draw(e);
	return (0);
}

void			draw(t_env *e)
{
	int			a[3];

	mlx_destroy_image(e->win->mlx_ptr, e->img.img_ptr);
	e->img.img_ptr = mlx_new_image(e->win->mlx_ptr,
	e->win->x_win, e->win->y_win);
	e->img.data = (int *)mlx_get_data_addr(e->img.img_ptr, &a[0], &a[1], &a[2]);
	raycasting(e, 0);
	mlx_put_image_to_window(e->win->mlx_ptr, e->win->win_ptr,
	e->img.img_ptr, 0, 0);
	if (e->flag.menu_glb)
	{
		init_menu(e, e->win->x_win, e->win->y_win);
		init_menu_press(e, e->win->x_win, e->win->y_win);
		main_menu(e);
		mlx_loop_hook(e->win->mlx_ptr, animation_menu, e);
	}
}
