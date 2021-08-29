/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf3d.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sreicher <sreicher@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/29 22:52:49 by sreicher          #+#    #+#             */
/*   Updated: 2020/11/04 16:36:27 by sreicher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void		init_mlx(t_env *e)
{
	e->win->mlx_ptr = mlx_init();
	e->win->x_win = 2560;
	e->win->y_win = 1600;
	e->win->n_win = "Fractol 2560x1600";
	init_win_img(e);
}

void		init_win_img(t_env *e)
{
	int		a[3];

	e->win->win_ptr = mlx_new_window(e->win->mlx_ptr, e->win->x_win,
	e->win->y_win, e->win->n_win);
	e->img.img_ptr = mlx_new_image(e->win->mlx_ptr,
	e->win->x_win, e->win->y_win);
	e->img.data = (int *)mlx_get_data_addr(e->img.img_ptr, &a[0], &a[1], &a[2]);
	mlx_hook(e->win->win_ptr, 2, 0, key_press, e);
	mlx_hook(e->win->win_ptr, 4, 0, mouse_press, e);
	mlx_hook(e->win->win_ptr, 17, 0, close_programm, NULL);
	mlx_hook(e->win->win_ptr, 6, 0, mouse_move, e);
}

static void	init_wolf3d(t_env *e)
{
	e->flag.menu_glb = 1;
	e->flag.menu = 1;
	e->flag.move_menu = 1;
	e->flag.background = 1;
	e->plr->dir_x = 1;
	e->plr->dir_y = 0;
	e->plr->plane_x = 0;
	e->plr->plane_y = 0.66;
}

static void	memalloc_global(t_env *e)
{
	if (!(e->win = ft_memalloc(sizeof(t_win))))
		error_exit("t_win is not allocated!");
	if (!(e->map = ft_memalloc(sizeof(t_map))))
		error_exit("t_win is not allocated!");
	if (!(e->button = ft_memalloc(sizeof(t_butt) * 39)))
		error_exit("t_button is not allocated");
	if (!(e->plr = ft_memalloc(sizeof(t_player))))
		error_exit("t_player is not allocated");
	if (!(e->move = ft_memalloc(sizeof(t_move))))
		error_exit("t_move is not allocated");
	if (!(e->rc = ft_memalloc(sizeof(t_raycast))))
		error_exit("t_raycast is not allocated");
}

void		wolf3d(char *file)
{
	t_env	*e;

	if (!(e = ft_memalloc(sizeof(t_env))))
		error_exit("t_env is not allocated!");
	memalloc_global(e);
	init_mlx(e);
	parsing_map(e, e->map, file);
	init_wolf3d(e);
	draw(e);
	mlx_loop(e->win->mlx_ptr);
}
