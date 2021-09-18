#include "./includes/cub3d.h"

void	wall_draw_calculate(t_all *all)
{
	if (all->ray.side == 0)
		all->ray.wall_dist = (all->ray.map_x - all->plr.x
				+ (1.0 - all->ray.step_x) / 2.0) / all->ray_dir.x;
	else
		all->ray.wall_dist = (all->ray.map_y - all->plr.y
				+ (1.0 - all->ray.step_y) / 2.0) / all->ray_dir.y;
	all->ray.line_height = (int)(all->win.height * all->ray.coef
			/ all->ray.wall_dist);
	all->ray.draw_start = all->win.height / 2 - all->ray.line_height / 2;
	all->ray.draw_end = all->win.height / 2 + all->ray.line_height / 2;
	if (all->ray.draw_start < 0)
		all->ray.draw_start = 0;
	if (all->ray.draw_end >= all->win.height)
		all->ray.draw_end = all->win.height - 1;
}

void	raystart(t_all *all)
{
	all->ray.camera_x = 2 * all->ray.x / (double)all->win.width - 1;
	all->ray_dir.x = all->plr_dir.x + all->plane.x * all->ray.camera_x;
	all->ray_dir.y = all->plr_dir.y + all->plane.y * all->ray.camera_x;
	all->ray.map_x = (int)(all->plr.x);
	all->ray.map_y = (int)(all->plr.y);
	all->ray.hit = 0;
	all->ray.wall_dist = 0;
}
