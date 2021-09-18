#include "./includes/cub3d.h"

char	*skiptxt(char *str, t_all *all)
{
	while (str)
	{
		if (*str == '.')
		{
			if (*(str + 1) == '/')
				break ;
			else
				exitfonc(all, 'P');
		}
		str++;
	}
	return (str);
}

char	*skipspaces(char *str)
{
	while (*str == ' ')
		str++;
	return (str);
}

char	*skipdigits(t_all *all, char *str)
{
	int		i;

	i = 0;
	while (ft_isdigit(*str) || *str == '-')
	{
		if (i == 0 && *str == '0')
			exitfonc(all, 'R');
		str++;
		i++;
	}
	return (str);
}

char	*skipdigitsclr(t_all *all, char *str)
{
	int		i;

	i = 0;
	while (ft_isdigit(*str) || *str == '-')
	{
		if (i == 0 && *str == '0' && ft_isdigit(*(str + 1)))
			exitfonc(all, 'C');
		str++;
		i++;
	}
	if (i > 3)
		exitfonc(all, 'C');
	return (str);
}

int	checkflags(t_all *all)
{
	if (!all->flags.ceilingcolor || !all->flags.floorcolor
		|| !all->flags.res || !all->flags.textea
		|| !all->flags.textno || !all->flags.textso
		|| !all->flags.textwe)
		exitfonc(all, 'P');
	return (1);
}
