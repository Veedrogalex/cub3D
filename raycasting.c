#include "./includes/cub3d.h"

static int	ishit(t_all *all)
{
	while (all->ray.hit != 1)
	{
		if (all->side_dist.x < all->side_dist.y)
		{
			all->side_dist.x += all->delta_dist.x;
			all->ray.map_x += all->ray.step_x;
			all->ray.side = 0;
		}
		else
		{
			all->side_dist.y += all->delta_dist.y;
			all->ray.map_y += all->ray.step_y;
			all->ray.side = 1;
		}
		if (all->map[all->ray.map_x][all->ray.map_y] == '1')
			all->ray.hit = 1;
	}
	return (all->ray.hit);
}

void	cast_rays(t_all *all)
{
	raystart(all);
	all->delta_dist.y = fabs(1 / all->ray_dir.y);
	all->delta_dist.x = fabs(1 / all->ray_dir.x);
	all->side_dist.x = (all->plr.x - all->ray.map_x) * all->delta_dist.x;
	if (all->ray_dir.x >= 0)
		all->side_dist.x = (all->ray.map_x + 1.0 - all->plr.x)
			* all->delta_dist.x;
	all->ray.step_x = -1;
	if (all->ray_dir.x >= 0)
		all->ray.step_x = 1;
	all->side_dist.y = (all->plr.y - all->ray.map_y) * all->delta_dist.y;
	if (all->ray_dir.y >= 0)
		all->side_dist.y = (all->ray.map_y + 1.0 - all->plr.y)
			* all->delta_dist.y;
	all->ray.step_y = -1;
	if (all->ray_dir.y >= 0)
		all->ray.step_y = 1;
	ishit(all);
}

static void	text_calculate(t_all *all, t_text *tex)
{
	double	wall_x;
	double	step;
	int		tex_x;

	if (all->ray.side == 0)
		wall_x = all->plr.y + all->ray.wall_dist * all->ray_dir.y;
	else
		wall_x = all->plr.x + all->ray.wall_dist * all->ray_dir.x;
	wall_x -= floor(wall_x);
	tex_x = (int)(wall_x * (double)tex->width);
	if (all->ray.side == 0 && all->ray_dir.x > 0)
		tex_x = tex->width - tex_x - 1;
	if (all->ray.side == 1 && all->ray_dir.y < 0)
		tex_x = tex->width - tex_x - 1;
	step = 1.0 * tex->height / all->ray.line_height;
	txtwalls(all, tex_x, step, tex);
}

void	whattexture(t_all *all)
{
	if (all->ray.side == 1 && all->ray.step_y > 0)
		text_calculate(all, all->no);
	else if (all->ray.side == 1 && all->ray.step_y < 0)
		text_calculate(all, all->so);
	else if (all->ray.side == 0 && all->ray.step_x > 0)
		text_calculate(all, all->we);
	else
		text_calculate(all, all->ea);
}

void	txtwalls(t_all *all, int tex_x, double step, t_text *tex)
{
	int		tex_y;
	double	tex_pos;

	tex_pos = (all->ray.draw_start - all->win.height
			/ 2.0 + all->ray.line_height / 2.0) * step;
	while (all->ray.draw_start < all->ray.draw_end)
	{
		tex_y = (int)tex_pos & (tex->height - 1);
		tex_pos += step;
		all->buf[all->ray.draw_start][all->ray.x]
			= tex->addr[tex->height * tex_y + tex_x];
		all->ray.draw_start++;
	}
}
