/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssobchak <ssobchak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/04 16:36:40 by ssobchak          #+#    #+#             */
/*   Updated: 2021/04/23 23:56:57 by ssobchak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H
# include "./mlx.h"
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include "../libft/libft.h"
# include <fcntl.h>
# include <math.h>

typedef struct s_coord
{
	double				x;
	double				y;
}						t_coord;

typedef struct s_parse
{
	int					res;
	int					textno;
	int					textso;
	int					textwe;
	int					textea;
	int					ceilingcolor;
	int					floorcolor;
	int					sprite;
	int					numsprite;
	int					map;
	int					player;
	int					bmp;
	int					save;
}						t_parse;

typedef struct s_colors
{
	int					rf;
	int					gf;
	int					bf;
	int					rgbfloor;
	int					dotfl;
	int					rc;
	int					gc;
	int					bc;
	int					rgbceiling;
	int					dotce;
}						t_colors;

typedef struct s_win
{
	void				*mlx;
	void				*win;
	void				*img;
	int					*addr;
	int					line_len;
	int					bpp;
	int					endian;
	int					width;
	int					height;
}						t_win;

typedef struct s_validmap
{
	int					maxlenstr;
	int					mapstrs;
	int					player;
	int					cm;
	int					mf;
}						t_validmap;

typedef struct s_ray
{
	int					map_x;
	int					map_y;
	double				camera_x;
	int					hit;
	int					side;
	int					step_x;
	int					step_y;
	int					draw_start;
	int					draw_end;
	double				wall_dist;
	double				coef;
	int					line_height;
	int					x;
	double				*rayslen;
}						t_ray;

typedef struct s_text
{
	void				*img;
	int					*addr;
	int					line_len;
	int					bpp;
	int					endian;
	int					width;
	int					height;
}						t_text;

typedef struct s_spr
{
	int					*order;
	double				*dist;
	double				pts_dist_x;
	double				pts_dist_y;
	t_coord				*pos;
	int					start_x;
	int					end_x;
	int					start_y;
	int					end_y;
	int					height;
	int					width;
	double				trans_x;
	double				trans_y;
	int					rtts;
}						t_spr;

typedef struct s_all
{
	int					**buf;
	int					sqrn;
	char				**map;
	char				*noway;
	char				*soway;
	char				*weway;
	char				*eaway;
	char				*spriteway;
	t_ray				ray;
	t_validmap			vmap;
	t_win				win;
	t_parse				flags;
	t_text				*no;
	t_text				*so;
	t_text				*we;
	t_text				*ea;
	t_text				*sprite;
	t_colors			colors;
	t_coord				plr;
	t_coord				plane;
	t_coord				plr_dir;
	t_coord				ray_dir;	
	t_coord				side_dist;
	t_coord				delta_dist;
	t_coord				spritexy;
	t_spr				sprt;
}						t_all;

void					ismap(int fd, t_all *all);
void					map_params(char *str, t_all *all);
void					mapcpy(char *str, t_all *all);
void					fullparser(t_all *all, char *file);
void					parsescreensize(char *str, t_all *all);
void					parsetexture(char *str, t_all *all);
void					parsesprite(char *str, t_all *all);
void					parsefloorcolor(char *str, t_all *all);
void					parseceilingcolor(char *str, t_all *all);
char					*skiptxt(char *str, t_all *all);
char					*skipdigits(t_all *all, char *str);
char					*skipspaces(char *str);
void					exitfonc(t_all *all, char error);
void					convertcolors(t_all *all);
void					makemap(t_all *data, char *file);
void					textureflags(t_all *all, char *str);
char					*skipdigitsclr(t_all *all, char *str);
int						checkflags(t_all *all);
int						ifmap(char *str);
int						keys(int code, t_all *all);
void					validate(t_all *all);
int						checkaround(t_all *all, int x, int y);
int						ifplr(t_all *all, int x, int y);
int						validsym(t_all *all, int x, int y);
void					raystart(t_all *all);
void					ceiling_floor_fill(t_all *all);
void					cast_rays(t_all *all);
void					wall_draw_calculate(t_all *all);
void					txtwalls(t_all *all, int tex_x, double step,
							t_text *tex);
int						render(t_all *all);
void					whattexture(t_all *all);
void					get_all_txt(t_all *all);
void					createbuffer(t_all *all);
void					fill_addr(t_all *all);
void					spritestart(t_all *all);
void					spriteorder(t_all *all);
void					sprite_calculate(t_all *all, int i);
void					draw_sprite(t_all *all);
void					sprites(t_all *all);
void					fillsprdist(t_all *all);
void					createsqrnsht(t_all *all);
void					calc_sprt_rtt(t_all *all, double inv);
void					checkparams(t_all *all, char *str);
int						ifnpar(t_all *all);

#endif
