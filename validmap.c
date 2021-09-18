#include "./includes/cub3d.h"

void	map_params(char *str, t_all *all)
{
	int		i;
	int		error;

	i = 0;
	error = 0;
	while (str[i])
	{
		if (ft_strchr("NSWE012 ", str[i]))
			i++;
		else
			exitfonc(all, 'X');
	}
	if (i > all->vmap.maxlenstr)
		all->vmap.maxlenstr = i;
	if ((!str && all->vmap.mapstrs > 0) || ifmap(str))
		all->vmap.mapstrs++;
	if (!ifmap(str) && all->vmap.mapstrs > 0)
		error++;
	if (error > 0)
		exitfonc(all, 'A');
	all->vmap.mf = 1;
}

void	mapcpy(char *str, t_all *all)
{
	int		i;

	i = 0;
	all->map[all->vmap.cm] = malloc((sizeof(char *)
				* (all->vmap.maxlenstr + 1)));
	if (!all->map[all->vmap.cm])
		exitfonc(all, 'M');
	while (str[i])
	{
		all->map[all->vmap.cm][i] = str[i];
		i++;
	}
	while (i < all->vmap.maxlenstr)
	{
		all->map[all->vmap.cm][i] = ' ';
		i++;
	}
	all->map[all->vmap.cm][i] = '\0';
	all->vmap.cm++;
}

void	validate(t_all *all)
{
	int	x;
	int	y;

	y = -1;
	while (++y < all->vmap.mapstrs)
	{
		x = -1;
		while (++x < all->vmap.maxlenstr)
		{
			if (!(validsym(all, x, y)))
				exitfonc(all, 'A');
			if (all->map[y][x] == '0' || all->map[y][x] == '2')
			{
				if (x == 0 || x == all->vmap.maxlenstr - 1 || y == 0
					|| y == all->vmap.mapstrs - 1)
					exitfonc(all, 'A');
				if (!checkaround(all, x, y))
					exitfonc(all, 'A');
			}
		}
	}
}

static void	plrdirnplane(t_all *all, char plr)
{
	if (plr == 'S')
	{
		all->plane.y = -0.66;
		all->plr_dir.x = 1;
		all->vmap.player++;
	}
	if (plr == 'W')
	{
		all->plane.x = -0.66;
		all->plr_dir.y = -1;
		all->vmap.player++;
	}
	if (plr == 'E')
	{
		all->plane.x = 0.66;
		all->plr_dir.y = 1;
		all->vmap.player++;
	}
	if (plr == 'N')
	{
		all->plane.y = 0.66;
		all->plr_dir.x = -1;
		all->vmap.player++;
	}
}

int	validsym(t_all *all, int x, int y)
{
	if (all->map[y][x] == '0' || all->map[y][x] == '2' || all->map[y][x] == '1'
		|| all->map[y][x] == ' ')
	{
		if (all->map[y][x] == '2')
			all->flags.numsprite++;
		return (1);
	}
	if (ft_strchr("NSWE", all->map[y][x]) && all->vmap.player < 2)
	{
		all->plr.x = y + 0.5;
		all->plr.y = x + 0.5;
		plrdirnplane(all, all->map[y][x]);
		all->map[y][x] = '0';
		if (all->vmap.player > 1)
			exitfonc(all, 'Z');
		return (1);
	}
	return (0);
}
