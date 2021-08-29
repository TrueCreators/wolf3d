/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sreicher <sreicher@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/31 13:47:22 by sreicher          #+#    #+#             */
/*   Updated: 2020/10/31 20:31:23 by sreicher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void		faq_message(void)
{
	ft_putendl("usage: ./wolf3d [yout map] [] \
	Example: ./wolf3d one.txt");
	exit(-1);
}

void		freeall(char **splt_line, char *line)
{
	ft_allfree((void **)splt_line);
	free(line);
}

void		error_exit(char *str)
{
	if (!str)
		ft_putendl("Error");
	else
	{
		ft_putstr("Error:");
		ft_putendl(str);
	}
	exit(-1);
}

int			main(int argc, char **argv)
{
	if (argc == 2)
		wolf3d(argv[1]);
	else
		faq_message();
}
