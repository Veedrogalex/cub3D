#include "./includes/cub3d.h"

static int	get_clr(t_all *all, int x, int y)
{
	char	*data;
	int		clr;

	data = (char *)all->win.addr + (y * all->win.line_len
			+ x * (all->win.bpp / 8));
	clr = *(int *)data;
	return (clr);
}

void	pixelfill(t_all *all, int fd)
{
	int	x;
	int	y;
	int	clr;

	y = all->win.height - 1;
	while (y >= 0)
	{
		x = 0;
		while (x < all->win.width)
		{
			clr = get_clr(all, x, y);
			write(fd, &clr, 4);
			x++;
		}
		y--;
	}
}

static void	headerfill(int n, unsigned char *arr)
{
	arr[0] = (unsigned char)(n);
	arr[1] = (unsigned char)(n >> 8);
	arr[2] = (unsigned char)(n >> 16);
	arr[3] = (unsigned char)(n >> 24);
}

static void	createheadder(t_all *all, int fd, int filesize)
{
	unsigned char	head[54];
	int				i;

	i = -1;
	while (i < 54)
		head[++i] = 0;
	head[0] = 'B';
	head[1] = 'M';
	headerfill(filesize + 54, &head[2]);
	head[10] = (unsigned char)54;
	head[14] = (unsigned char)40;
	headerfill(all->win.width, &head[18]);
	headerfill(all->win.height, &head[22]);
	head[26] = (unsigned char)1;
	head[28] = (unsigned char)32;
	head[34] = (unsigned char)filesize;
	write(fd, head, 54);
}

void	createsqrnsht(t_all *all)
{
	int	fd;
	int	filesize;

	filesize = all->win.width * all->win.height * 4;
	fd = open("sqrnsht.bmp", O_TRUNC | O_WRONLY | O_CREAT, 0777);
	if (fd < 0)
		exitfonc(all, 'B');
	createheadder(all, fd, filesize);
	pixelfill(all, fd);
	close(fd);
}
