/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssobchak <ssobchak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/20 14:23:35 by ssobchak          #+#    #+#             */
/*   Updated: 2021/04/27 19:48:43 by ssobchak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/cub3d.h"

#define UP 126
#define DOWN 125
#define RIGHT 124
#define LEFT 123
#define ESC 53
#define STEP 0.18
#define W 13
#define A 0
#define S 1
#define D 2

static void	rotation(t_all *all, double angle)
{
	double	oldplane;
	double	olddir;

	oldplane = all->plane.x;
	olddir = all->plr_dir.x;
	all->plr_dir.x = all->plr_dir.x * cos(angle) - all->plr_dir.y * sin(angle);
	all->plr_dir.y = olddir * sin(angle) + all->plr_dir.y * cos(angle);
	all->plane.x = all->plane.x * cos(angle) - all->plane.y * sin(angle);
	all->plane.y = oldplane * sin(angle) + all->plane.y * cos(angle);
}

static void	forw_back(t_all *all, double a)
{
	if (all->map[(int)(all->plr.x + all->plr_dir.x * a)][(int)(all->plr.y)]
		!= '1')
		all->plr.x += all->plr_dir.x * a;
	if (all->map[(int)(all->plr.x)][(int)(all->plr.y + all->plr_dir.y * a)]
		!= '1')
		all->plr.y += all->plr_dir.y * a;
}

static void	left_right(t_all *all, double a)
{
	if (all->map[(int)(all->plr.x - all->plr_dir.y * a)][(int)(all->plr.y)]
		!= '1')
		all->plr.x -= all->plr_dir.y * a;
	if (all->map[(int)(all->plr.x)][(int)(all->plr.y + all->plr_dir.x * a)]
		!= '1')
		all->plr.y += all->plr_dir.x * a;
}

int	keys(int code, t_all *all)
{
	if (code == UP || code == W)
		forw_back(all, STEP);
	else if (code == DOWN || code == S)
		forw_back(all, -STEP);
	else if (code == A)
		left_right(all, STEP);
	else if (code == D)
		left_right(all, -STEP);
	else if (code == LEFT)
		rotation(all, STEP);
	else if (code == RIGHT)
		rotation(all, -STEP);
	else if (code == ESC)
		exitfonc(all, 'E');
	return (0);
}
