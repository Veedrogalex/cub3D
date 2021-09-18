#include "./includes/cub3d.h"

void	createbuffer(t_all *all)
{
	int		i;

	all->buf = ft_calloc(sizeof(int *), all->win.height);
	if (!all->buf)
		exitfonc(all, 'M');
	i = 0;
	while (i < all->win.height)
	{
		all->buf[i] = ft_calloc(sizeof(int), all->win.width);
		if (!all->buf[i])
			exitfonc(all, 'M');
		i++;
	}
}

void	fill_addr(t_all *all)
{
	int		y;
	int		x;

	y = 0;
	while (y < all->win.height)
	{
		x = 0;
		while (x < all->win.width)
		{
			all->win.addr[all->win.line_len / 4 * y + x] = all->buf[y][x];
			x++;
		}
		y++;
	}
}

void	ceiling_floor_fill(t_all *all)
{
	int	mid;
	int	x;
	int	y;

	mid = all->win.height / 2;
	y = -1;
	while (++y < mid)
	{
		x = -1;
		while (++x < all->win.width)
			all->buf[y][x] = all->colors.rgbceiling;
	}
	while (++y < all->win.height)
	{
		x = -1;
		while (++x < all->win.width)
			all->buf[y][x] = all->colors.rgbfloor;
	}
}

static void	gettexture(t_all *all, t_text *tx, char *way)
{
	tx->img = mlx_xpm_file_to_image(all->win.mlx, way, &tx->width, &tx->height);
	if (!tx->img)
		exitfonc(all, 'T');
	tx->addr = (int *)mlx_get_data_addr(tx->img, &tx->bpp, &tx->line_len,
			&tx->endian);
	if (!tx->addr)
		exitfonc(all, 'T');
}

void	get_all_txt(t_all *all)
{
	all->no = ft_calloc(1, sizeof(t_text));
	if (!all->no)
		exitfonc(all, 'T');
	all->so = ft_calloc(1, sizeof(t_text));
	if (!all->so)
		exitfonc(all, 'T');
	all->we = ft_calloc(1, sizeof(t_text));
	if (!all->we)
		exitfonc(all, 'T');
	all->ea = ft_calloc(1, sizeof(t_text));
	if (!all->ea)
		exitfonc(all, 'T');
	all->sprite = ft_calloc(1, sizeof(t_text));
	if (!all->sprite)
		exitfonc(all, 'T');
	gettexture(all, all->no, all->noway);
	gettexture(all, all->so, all->soway);
	gettexture(all, all->we, all->weway);
	gettexture(all, all->ea, all->eaway);
	gettexture(all, all->sprite, all->spriteway);
}
