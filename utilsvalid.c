#include "./includes/cub3d.h"

int	checkaround(t_all *all, int x, int y)
{
	if (all->map[y + 1][x] == ' ' || all->map[y + 1][x + 1] == ' '
				|| all->map[y + 1][x - 1] == ' ' || all->map[y][x + 1] == ' '
				|| all->map[y][x - 1] == ' ' || all->map[y - 1][x] == ' '
				|| all->map[y - 1][x - 1] == ' '
				|| all->map[y - 1][x + 1] == ' ')
		return (0);
	return (1);
}

void	checkparams(t_all *all, char *str)
{
	if (all->flags.ceilingcolor > 1
		|| all->flags.floorcolor > 1 || all->flags.textea > 1
		|| all->flags.textno > 1 || all->flags.textso > 1
		|| all->flags.textwe > 1 ||all->flags.sprite > 1)
		exitfonc(all, 'P');
	if (str)
		free(str);
	if (ifnpar(all) || all->vmap.mf != 1)
		exitfonc(all, 'P');
}
