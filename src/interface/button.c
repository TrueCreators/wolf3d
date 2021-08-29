/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   button.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sreicher <sreicher@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/29 19:42:24 by sreicher          #+#    #+#             */
/*   Updated: 2020/10/31 13:48:09 by sreicher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void	create_button(t_env *e, t_butt *butt)
{
	int	i;

	butt->pos_x = butt->pos_x - (butt->size_x / 2);
	butt->pos_y = butt->pos_y - (butt->size_y / 2);
	e->img_butt.img_ptr =
	mlx_new_image(e->win->mlx_ptr, butt->size_x, butt->size_y);
	e->img_butt.data =
	(int *)mlx_get_data_addr(e->img_butt.img_ptr, &e->img_butt.bpp,
	&e->img_butt.size_line, &e->img_butt.endian);
	i = -1;
	while (++i < butt->size_x * butt->size_y)
	{
		e->img_butt.data[i] = butt->color_button;
	}
	mlx_put_image_to_window(e->win->mlx_ptr, e->win->win_ptr,
	e->img_butt.img_ptr, butt->pos_x, butt->pos_y);
	if (butt->text)
	{
		mlx_string_put(e->win->mlx_ptr, e->win->win_ptr,
		butt->pos_x + (butt->size_x / 2) - (ft_strlen(butt->text) * 5),
		butt->pos_y + (butt->size_y / 2) - 10, butt->color_text, butt->text);
	}
}
