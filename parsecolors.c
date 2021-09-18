#include "./includes/cub3d.h"

static char	*skipdotflr(t_all *all, char *str)
{
	if (*str == ',')
	{
		str++;
		all->colors.dotfl++;
	}
	return (str);
}

static char	*skipdotceil(t_all *all, char *str)
{
	if (*str == ',')
	{
		str++;
		all->colors.dotce++;
	}
	return (str);
}

void	parsefloorcolor(char *str, t_all *all)
{
	if (ft_strchr(str, '+') || ft_strchr(str, '-'))
		exitfonc(all, 'C');
	if (*str == 'F')
		str++;
	all->colors.rf = ft_atoi(str);
	str = skipspaces(str);
	str = skipdigitsclr(all, str);
	str = skipspaces(str);
	str = skipdotflr(all, str);
	all->colors.gf = ft_atoi(str);
	str = skipspaces(str);
	str = skipdigitsclr(all, str);
	str = skipspaces(str);
	str = skipdotflr(all, str);
	all->colors.bf = ft_atoi(str);
	str = skipspaces(str);
	str = skipdigitsclr(all, str);
	if (all->colors.rf < 0 || all->colors.gf < 0 || all->colors.bf < 0
		|| all->colors.rf > 255 || all->colors.gf > 255 || all->colors.bf > 255
		|| (all->colors.dotfl > 2) || *str)
		exitfonc(all, 'C');
	convertcolors(all);
	all->flags.floorcolor += 1;
}

void	parseceilingcolor(char *str, t_all *all)
{
	if (ft_strchr(str, '+') || ft_strchr(str, '-'))
		exitfonc(all, 'C');
	if (*str == 'C')
		str++;
	str = skipspaces(str);
	all->colors.rc = ft_atoi(str);
	str = skipdigitsclr(all, str);
	str = skipspaces(str);
	str = skipdotceil(all, str);
	all->colors.gc = ft_atoi(str);
	str = skipspaces(str);
	str = skipdigitsclr(all, str);
	str = skipspaces(str);
	str = skipdotceil(all, str);
	all->colors.bc = ft_atoi(str);
	str = skipspaces(str);
	str = skipdigitsclr(all, str);
	if (all->colors.rc < 0 || all->colors.gc < 0 || all->colors.bc < 0
		|| all->colors.rc > 255 || all->colors.gc > 255 || all->colors.bc > 255
		|| (all->colors.dotce > 2) || *str)
		exitfonc(all, 'C');
	convertcolors(all);
	all->flags.ceilingcolor += 1;
}

void	convertcolors(t_all *all)
{
	all->colors.rgbceiling = ((all->colors.rc & 0x0ff) << 16
			| (all->colors.gc & 0x0ff) << 8 | (all->colors.bc & 0x0ff));
	all->colors.rgbfloor = ((all->colors.rf & 0x0ff) << 16
			| (all->colors.gf & 0x0ff) << 8 | (all->colors.bf & 0x0ff));
}
