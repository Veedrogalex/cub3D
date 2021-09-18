#include "./includes/cub3d.h"

int	ifnpar(t_all *all)
{
	if (all->flags.ceilingcolor == 0
		|| all->flags.floorcolor == 0 || all->flags.textea == 0
		|| all->flags.textno == 0 || all->flags.textso == 0
		|| all->flags.textwe == 0 ||all->flags.sprite == 0)
		return (1);
	return (0);
}

void	parseparams(int fd, t_all *all)
{
	char	*str;

	str = NULL;
	while (get_next_line(fd, &str) > 0)
	{
		if (ifnpar(all))
		{
			if (*str == 'F')
				parsefloorcolor(str, all);
			else if (*str == 'C')
				parseceilingcolor(str, all);
			else if (*str == 'R')
				parsescreensize(str, all);
			else if (((*str == 'N' || *str == 'S') && *(str + 1) == 'O')
				|| *str == 'W' || *str == 'E')
				parsetexture(str, all);
			else if (*str == 'S' && *(str + 1) == ' ')
				parsesprite(str, all);
		}
		else if (!ifnpar(all) && str)
			map_params(str, all);
		free(str);
		str = NULL;
	}
	checkparams(all, str);
}

int	ifmap(char *str)
{
	if ((ft_strchr(str, '1') || ft_strchr(str, '0') || ft_strchr(str, '2'))
		&& (!ft_strchr(str, 'R') && !ft_strchr(str, 'C') && !ft_strchr(str, 'F')
			&& !ft_strchr(str, '.') && !ft_strchr(str, '/')))
		return (1);
	return (0);
}

void	ismap(int fd, t_all *all)
{
	char	*str;

	str = NULL;
	while ((get_next_line(fd, &str) > 0))
	{
		if (ifmap(str) && all->vmap.mf == 1)
			mapcpy(str, all);
		free(str);
		str = NULL;
	}
	free(str);
	str = NULL;
}

void	fullparser(t_all *all, char *file)
{
	int	fd;

	fd = open(file, O_RDONLY);
	if (fd < 0)
		exitfonc(all, 'F');
	parseparams(fd, all);
	close(fd);
	all->map = (char **)malloc(sizeof(char *) * all->vmap.mapstrs);
	if (!all->map)
		exitfonc(all, 'M');
	fd = open(file, O_RDONLY);
	if (fd < 0)
		exitfonc(all, 'F');
	ismap(fd, all);
	validate(all);
	close(fd);
	all->ray.coef = 0.75 * (double)(all->win.width)
		/ (double)(all->win.height);
}
