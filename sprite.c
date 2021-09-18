#include "./includes/cub3d.h"

void	spriteorder(t_all *all)
{
	int		i;
	int		j;
	double	fs;

	i = -1;
	while (++i < all->flags.numsprite)
	{
		j = -1;
		while (++j < all->flags.numsprite - 1)
		{
			if (all->sprt.dist[j] < all->sprt.dist[j + 1])
			{
				fs = all->sprt.dist[j];
				all->sprt.dist[j] = all->sprt.dist[j + 1];
				all->sprt.dist[j + 1] = fs;
				fs = all->sprt.order[j];
				all->sprt.order[j] = all->sprt.order[j + 1];
				all->sprt.order[j + 1] = (int)fs;
			}
		}
	}
}

void	sprite_calculate(t_all *all, int i)
{
	double	inv;

	all->sprt.pts_dist_x = all->sprt.pos[all->sprt.order[i]].x - all->plr.x;
	all->sprt.pts_dist_y = all->sprt.pos[all->sprt.order[i]].y - all->plr.y;
	inv = 1.0 / (all->plane.x * all->plr_dir.y - all->plr_dir.x * all->plane.y);
	calc_sprt_rtt(all, inv);
	all->sprt.height = (int)fabs((all->win.height *all->ray.coef
				/ all->sprt.trans_y));
	all->sprt.start_y = all->win.height / 2 - all->sprt.height / 2;
	all->sprt.end_y = all->win.height / 2 + all->sprt.height / 2;
	if (all->sprt.start_y < 0)
		all->sprt.start_y = 0;
	if (all->sprt.end_y >= all->win.height)
		all->sprt.end_y = all->win.height - 1;
	all->sprt.width = (int)fabs((all->win.height *all->ray.coef
				/ all->sprt.trans_y));
	all->sprt.start_x = all->sprt.rtts - all->sprt.width / 2;
	all->sprt.end_x = all->sprt.rtts + all->sprt.width / 2;
	if (all->sprt.start_x < 0)
		all->sprt.start_x = 0;
	if (all->sprt.end_x >= all->win.width)
		all->sprt.end_x = all->win.width - 1;
}

static void	draw_line(t_all *all, int x, int l)
{
	int	y;
	int	i;
	int	clr;
	int	s;

	i = all->sprt.start_y;
	while (i < all->sprt.end_y)
	{
		s = i * 256 - all->win.height * 128 + all->sprt.height * 128;
		y = (s * all->sprite->height) / all->sprt.height / 256;
		clr = all->sprite->addr[all->sprite->height * y + x];
		if ((clr & 0x00FFFF) != 0)
			all->buf[i][l] = clr;
		i++;
	}
}

void	draw_sprite(t_all *all)
{
	int	x;
	int	dsx;

	dsx = all->sprt.start_x;
	while (dsx < all->sprt.end_x)
	{
		x = (int)(256 * (dsx - (-all->sprt.width / 2
						+ all->sprt.rtts)) * all->sprite->width
				/ all->sprt.width) / 256;
		if (all->sprt.trans_y > 0 && dsx < all->win.width && dsx
			>= 0 && all->sprt.trans_y < all->ray.rayslen[dsx])
			draw_line(all, x, dsx);
		dsx++;
	}
}

void	sprites(t_all *all)
{
	int	i;

	all->sprt.order = malloc(sizeof(int) * all->flags.numsprite);
	if (!all->sprt.order)
		exitfonc(all, 'M');
	all->sprt.dist = malloc(sizeof(double) * all->flags.numsprite);
	if (!all->sprt.dist)
		exitfonc(all, 'M');
	fillsprdist(all);
	spriteorder(all);
	i = -1;
	while (++i < all->flags.numsprite)
	{
		sprite_calculate(all, i);
		draw_sprite(all);
	}
	if (all->sprt.order)
		free(all->sprt.order);
	if (all->sprt.dist)
		free(all->sprt.dist);
}
