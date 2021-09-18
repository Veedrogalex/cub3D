#include "./includes/cub3d.h"

void	parsescreensize(char *str, t_all *all)
{
	long		x;
	long		y;

	if (ft_strchr(str, '+'))
		exitfonc(all, 'R');
	if (*str == 'R')
		str++;
	mlx_get_screen_size(all->win.mlx, &all->win.width, &all->win.height);
	x = ft_atoi(str);
	if (x < all->win.width)
		all->win.width = x;
	str = skipspaces(str);
	str = skipdigits(all, str);
	y = ft_atoi(str);
	str = skipspaces(str);
	str = skipdigits(all, str);
	if (y < all->win.height)
		all->win.height = y;
	all->flags.res += 1;
	if (all->win.width <= 0 || all->win.height <= 0 || all->flags.res > 1
		|| *str)
		exitfonc(all, 'R');
}

void	textureflags(t_all *all, char *str)
{
	if (all->flags.textno == 0 || all->flags.textso == 0
		||all->flags.textwe == 0 || all->flags.textea == 0
		||all->flags.sprite == 0)
	{
		if (*str == 'N')
			all->flags.textno++;
		if (*str == 'S' && *(str + 1) == 'O')
			all->flags.textso++;
		if (*str == 'W')
			all->flags.textwe++;
		if (*str == 'E')
			all->flags.textea++;
		if (*str == 'S' && *(str + 1) == ' ')
			all->flags.sprite++;
	}
	else
	{
		if (all->flags.textno != 1 || all->flags.textso != 1
			|| all->flags.textwe != 1 || all->flags.textea != 1
			|| all->flags.sprite != 1)
			exitfonc(all, 'T');
	}
}

void	parsetexture(char *str, t_all *all)
{
	if ((*str == 'N' && *(str + 1) == 'O' && *(str + 2) == ' ')
		|| (*str == 'S' && *(str + 1) == 'O' && *(str + 2) == ' ')
		|| (*str == 'W' && *(str + 1) == 'E' && *(str + 2) == ' ')
		|| (*str == 'E' && *(str + 1) == 'A' && *(str + 2) == ' '))
	{
		textureflags(all, str);
		str = skiptxt(str, all);
		if (all->flags.textno && !all->noway)
			all->noway = ft_strdup(str);
		if (all->flags.textso && !all->soway)
			all->soway = ft_strdup(str);
		if (all->flags.textwe && !all->weway)
			all->weway = ft_strdup(str);
		if (all->flags.textea && !all->eaway)
			all->eaway = ft_strdup(str);
	}
	else
		exitfonc(all, 'T');
}

void	parsesprite(char *str, t_all *all)
{
	str = skipspaces(str);
	if (*str == 'S' && *(str + 1) == ' ')
	{
		textureflags(all, str);
		str = skiptxt(str, all);
		if (!all->spriteway && all->flags.sprite)
			all->spriteway = ft_strdup(str);
	}
	else
		exitfonc(all, 'S');
}
