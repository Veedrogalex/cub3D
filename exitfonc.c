#include "./includes/cub3d.h"

static void	destroymlx(t_all *all)
{
	if (all->win.img)
		mlx_destroy_image(all->win.mlx, all->win.img);
	if (all->win.win)
		mlx_destroy_window(all->win.mlx, all->win.win);
}

static void	destroytxt(t_all *all)
{
	if (all->ea)
	{
		if (all->ea->addr && all->ea->img)
			mlx_destroy_image(all->win.mlx, all->ea->img);
	}
	if (all->no)
	{
		if (all->no->addr && all->no->img)
			mlx_destroy_image(all->win.mlx, all->no->img);
	}
	if (all->so)
	{
		if (all->so->addr && all->so->img)
			mlx_destroy_image(all->win.mlx, all->so->img);
	}
	if (all->we)
	{
		if (all->we->addr && all->we->img)
			mlx_destroy_image(all->win.mlx, all->we->img);
	}
	if (all->sprite)
	{
		if (all->sprite->addr && all->sprite->img)
			mlx_destroy_image(all->win.mlx, all->sprite->img);
	}
}

static void	othererrors(char error)
{
	if (error == 'I')
		write(2, "ERROR\nTROUBLE WITH SPRITE", 26);
	if (error == 'E')
		write(2, "THX 4 ur attention", 19);
	if (error == 'S')
		write(2, "ERROR\nTROUBLE WITH SQREENSHOT", 26);
	if (error == 'Q')
		write(2, "I DID A SCREENSHOT,", 19);
	if (error == 'G')
		write(2, "ERROR\nTROUBLE WITH MAPFILE OR SQRNSHT", 38);
	if (error == 'Z')
		write(2, "ERROR\nA LOT OF PLAYER IN THE MAP", 33);
	if (error == 'F')
		write(2, "ERROR\nOPEN FILE FAIL", 21);
}

void	exitfonc(t_all *all, char error)
{
	if (error == 'B')
		write(2, "ERROR\nTROUBLE WITH CREATE SQREENSHOT", 37);
	if (error == 'R')
		write(2, "ERROR\nWRONG RESOLUTION", 23);
	if (error == 'T')
		write(2, "ERROR\nTROUBLE WITH TEXTURE", 26);
	if (error == 'S')
		write(2, "ERROR\nWRONG SPRITE INPUT", 25);
	if (error == 'C')
		write(2, "ERROR\nTROUBLE WITH COLORS", 26);
	if (error == 'M')
		write(2, "ERROR\nMALLOC FAIL", 18);
	if (error == 'X')
		write(2, "ERROR\nWRONG SYMBOL IN THE MAP", 30);
	if (error == 'P')
		write(2, "ERROR\nWRONG PARAM'S", 20);
	if (error == 'A')
		write(2, "ERROR\nINVALID MAP", 18);
	othererrors(error);
	destroytxt(all);
	destroymlx(all);
	exit(0);
}
