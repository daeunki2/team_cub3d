/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daeunki2 <daeunki2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/20 13:51:41 by rgrochow          #+#    #+#             */
/*   Updated: 2025/05/05 13:27:15 by daeunki2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "../mlx_linux/mlx.h"
# include <stdlib.h>
# include <stdio.h>
# include <math.h>
# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>
# include <X11/X.h>
# include <X11/keysym.h>
#include <X11/extensions/Xfixes.h>
# include <stdio.h>
# include <string.h>

# define T_ERROR (-1)
# define T_NO (0)
# define T_SO (1)
# define T_WE (2)
# define T_EA (3)
# define T_FLOOR (4)
# define T_CEIL (5)
# define T_MAP (6)
# define T_EMPTY (7)
# define TEXTURE_COUNT (4)
# define RGB (2)

# define BUFFER_SIZE 1023

# define TEX_WIDTH 64
# define TEX_HEIGHT 64

typedef struct s_ray
{
	double	camera;
	double	ray_dir_x;
	double	ray_dir_y;
	int		map_x;
	int		map_y;
	double	side_dist_x;
	double	side_dist_y;
	double	delta_dist_x;
	double	delta_dist_y;
	double	perp_wall_dist;
	int		step_x;
	int		step_y;
	int		side;
	int		hit;
	int		line_h;
	int		draw_start;
	int		draw_end;
	int		tex_num;
	int		tex_x;
	double	wall_x;
	double	tex_pos;
	double	step;
}	t_ray;

typedef struct s_map
{
	char	**grid;//init_map
	int		width;//init_map
	int		height;//init_map
}	t_map;

typedef struct s_path
{
	int	ex;
	int	front;
	int	rear;
	int	x;
	int	y;
}	t_path;

typedef struct s_img
{
	void	*img;
	int		*data;
	int		width;
	int		height;
	char	*path;//init_img
	int		count;
	int		type;
}	t_img;

typedef struct s_player
{
	double	move_speed;//inti player
	double	rot_speed;//init player
	char	dir;//check_player
	double	dir_x;//자동
	double	dir_y;//자동
	double	pos_x;//check_plaer +0.5
	double	pos_y;//check_plaer +0.5
	double	plane_x;//자동
	double	plane_y;//자동
}	t_player;

typedef struct s_game
{
	void		*mlx;
	void		*win;
	int			win_w;
	int			win_h;
	int			bpp;
	int			sl;
	int			endian;
	int			floor_color;
	int			ceiling_color;
	int			keys[70000];
	int			pitch;
	int			ignore_mouse;
	//parsing
	int			map_h;
	int			map_w;
	int			file_fd;
	int			player_count;
	int			ceiling_count;
	int			floor_count;
	int			info_count;
	int			map_start;
	int			map_last;
	char		*big_line;
	char		**copied_map;
	t_img		textures[4];
	t_img		frame;
	t_map		map;
	t_player	player;
	t_path		path;
}	t_game;

/* ************************************************************************** */
/*                                      FILE                                  */
/* ************************************************************************** */

/* check.c */
// void	check_file(char *map_file);
// /* init.c */
// void	init_imgs(t_game *game, char *map_file);
// /* utils.c */
// int		count_lines(const char *map_file);
// char	*read_line(int fd);

/* ************************************************************************** */
/*                                      MAP                                   */
/* ************************************************************************** */
/* init.c */
void	init_map(t_game *game, char *map_file);
/* check.c */
void	check_map(t_game *game);
/* utils.c */
int		bfs(t_game *game, int **directions, int **visited);


/* ************************************************************************** */
/*                                      PARSING                               */
/* ************************************************************************** */
/* down_parsing.c */
int		down_parsing(t_game *info, int start);
int		component_check(t_game *info, char *map);
int 	is_end_map(t_game *info, int i);
/* error.c */
int		error_msg(char *msg);
void	free_split(char **strs);
void	parsing_error_out(t_game *game);
/* file_read.c */
int	read_map(t_game *info);
int	file_format(char *file);

/* init.c */
int		set_game(t_game *info, char *av);
void	set_tile(t_game *info);
/* parsing.c */
int		do_parsing(t_game *info, char *av);
int		ft_identifi(char *str);
/* simple_tool.c */
int		is_space(char c);
int		count_strings(char **arr);
int		ft_isdigit(char c);
/* up_parsing.c */
int		up_parsing(t_game *info);
int		info_check(t_game *info);
int		is_map_line(char *str);
int		direction_path_check(t_game *info, int k, int nsew);
/* color_parser.c */
int				color_parser(t_game *info, int i, int type);
int				color_component(char *line);

int	init_color(int *color, char *ptr);
/* wall_check.c */
void	 dup_map(t_game *game);
int    surround_wall_check(t_game *game, char **str);
void	set_player_pos(t_game *game, char **str);
int set_map(t_game *game);

/* ************************************************************************** */
/*                                     PLAYER                                 */
/* ************************************************************************** */
/* check.c */
int		check_player(t_game *game, char *line, int height);
/* init.c */
void	init_player(t_game *game);

/* ************************************************************************** */
/*                                      GAME                                  */
/* ************************************************************************** */
/* init.c */
void	init_game(t_game *game);
void	init_ray_direction(t_game *game, t_ray *ray, int x);
void	init_ray_steps(t_game *game, t_ray *ray);
void	perform_dda(t_game *game, t_ray *ray);
/* events.c */
int		mouse_move(int x, int y, t_game *game);
int		key_press(int keycode, t_game *game);
int		key_release(int keycode, t_game *game);
int		close_window(void *game);
/* render.c */
void	render(t_game *game);
/* loop.c */
int		loop_hook(t_game *game);
/* minimap.c */
void	draw_minimap(t_game *game);
/* clear.c */
void	clear_game(t_game *game);
void 	parsing_free(t_game *game);
/* utils.c */
void	calculate_wall_distance(t_game *game, t_ray *ray);
void	choose_texture_number(t_ray *ray);
void	calculate_texture_coordinates(t_game *game, t_ray *ray);
int		get_wall_texture_color(t_game *game, t_ray *ray);
void	draw_vertical_line(t_game *game, t_ray *ray, int x);
/* ************************************************************************** */
/*                                     UTILS                                  */
/* ************************************************************************** */
int		ft_strlen(const char *s);
char	*ft_strdup(const char *s1);
int		ft_strcmp(const char *s1, const char *s2);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
char	*ft_strchr(const char *str, int c);
char	**ft_split(char *s, char c);
int		ft_atoi(const char *str);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_get_line(char *backup);
char	*ft_file_read(int fd, char *backup, char *buf);
char	*ft_get_backup(char *backup);
char	*get_next_line(int fd);
char	*ft_strnstr(const char *big, const char *little, size_t len);
void	*ft_memset(void *pointeur, int value, size_t count);


#endif
