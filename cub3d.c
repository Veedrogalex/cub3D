/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssobchak <ssobchak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/10 22:34:51 by ssobchak          #+#    #+#             */
/*   Updated: 2021/04/23 19:55:40 by ssobchak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/cub3d.h"

static int	cross_press(t_all *all)
{
	(void)all;
	exit(0);
}

int	render(t_all *all)
{
	all->ray.x = 0;
	ceiling_floor_fill(all);
	while (all->ray.x < all->win.width)
	{
		cast_rays(all);
		wall_draw_calculate(all);
		whattexture(all);
		all->ray.rayslen[all->ray.x] = all->ray.wall_dist;
		all->ray.x++;
	}
	sprites(all);
	fill_addr(all);
	if (all->flags.save)
	{
		createsqrnsht(all);
		exitfonc(all, 'Q');
	}
	mlx_put_image_to_window(all->win.mlx, all->win.win, all->win.img, 0, 0);
	return (0);
}

static void	arguments(t_all *all, int argc, char **argv)
{
	int	l;

	if (argc == 2 || argc == 3)
	{
		if (argc == 3)
		{
			l = ft_strlen(argv[2]);
			if (ft_strncmp("--save", argv[2], l) || l != 6)
				exitfonc(all, 'S');
			all->flags.save = 1;
		}
		if (argc == 2)
		{
			l = ft_strlen(argv[1]);
			if (argv[1][l - 4] != '.' || argv[1][l - 3] != 'c'
				|| argv[1][l - 2] != 'u' || argv[1][l - 1] != 'b')
				exitfonc(all, 'G');
		}
	}
	else
		exitfonc(all, 'G');
}

int	main(int argc, char **argv)
{
	t_all	all;

	ft_bzero(&all, sizeof(all));
	arguments(&all, argc, argv);
	fullparser(&all, argv[1]);
	all.win.mlx = mlx_init();
	get_all_txt(&all);
	createbuffer(&all);
	spritestart(&all);
	all.ray.rayslen = malloc(sizeof(double) * all.win.width);
	if (!all.ray.rayslen)
		exitfonc(&all, 'M');
	all.win.win = mlx_new_window(all.win.mlx, all.win.width,
			all.win.height, "cub3D");
	all.win.img = mlx_new_image(all.win.mlx, all.win.width, all.win.height);
	all.win.addr = (int *)mlx_get_data_addr(all.win.img, &all.win.bpp,
			&all.win.line_len, &all.win.endian);
	if (all.flags.save)
		render(&all);
	mlx_hook(all.win.win, 2, 1L, keys, &all);
	mlx_hook(all.win.win, 17, 0L, cross_press, &all);
	mlx_loop_hook(all.win.mlx, render, &all);
	mlx_loop(all.win.mlx);
	return (0);
}
