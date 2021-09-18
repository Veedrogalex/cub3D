#include "./includes/cub3d.h"

void	fillsprdist(t_all *all)
{
	int	i;

	i = -1;
	while (++i < all->flags.numsprite)
	{
		all->sprt.order[i] = i;
		all->sprt.dist[i] = pow(all->plr.x - all->sprt.pos[i].x, 2)
			+ pow(all->plr.y - all->sprt.pos[i].y, 2);
	}
}

void	spritestart(t_all *all)
{
	int	i;
	int	j;
	int	cnt;

	cnt = 0;
	all->sprt.pos = ft_calloc(sizeof(t_coord), all->flags.numsprite);
	if (!all->sprt.pos)
		exitfonc(all, 'M');
	i = -1;
	while (++i < all->vmap.mapstrs)
	{
		j = -1;
		while (j++ < all->vmap.maxlenstr)
		{
			if (all->map[i][j] == '2')
			{
				all->sprt.pos[cnt].x = i + 0.5;
				all->sprt.pos[cnt].y = j + 0.5;
				all->map[i][j] = '0';
				cnt++;
			}
		}
	}
}

void	calc_sprt_rtt(t_all *all, double inv)
{
	all->sprt.trans_x = inv * (all->plr_dir.y * all->sprt.pts_dist_x
			- all->plr_dir.x * all->sprt.pts_dist_y);
	all->sprt.trans_y = inv * (-all->plane.y * all->sprt.pts_dist_x
			+ all->plane.x * all->sprt.pts_dist_y);
	all->sprt.rtts = (int)((all->win.width / 2.0)
			* (1.0 + all->sprt.trans_x / all->sprt.trans_y));
}
