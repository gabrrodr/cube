/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabrrodr <gabrrodr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 16:06:46 by digoncal          #+#    #+#             */
/*   Updated: 2024/07/01 15:46:30 by gabrrodr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

/* ---------- LIBRARIES ---------- */

# include "libft.h"
# include "../libs/minilibx-linux/mlx.h"
# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>
# include <math.h>
# include <X11/X.h>
# include <X11/keysym.h>

/*---------- MACROS ----------*/

# define WIN_HEIGHT 640
# define WIN_WIDTH 640
# define TEX_SIZE 64


/*------------- STRUCTURES ---------------*/

typedef struct s_pos
{
	double	x;
	double	y;
}				t_pos;

typedef struct s_textures
{
	
}				t_textures;

typedef struct raycast
{
	t_pos	plane;
	t_pos 	dir;
	t_pos	next_dist; //distance to next x or y-side (sideDist)
	t_pos	grid_dist; //length of ray from one x or y-side to next x or y-side (deltaDist)
	int		step_x;
	int		step_y;
	int		map_x;
	int		map_y;
	int 	draw_start;
	int 	draw_end;
	bool	hit;
	bool	side;
	double	cam_x;
} t_raycast;

typedef struct s_player
{
	t_pos	position;
	t_pos	dir;
	t_pos	cam;
	int		moved;
	//bool	move_up;
	//bool	move_down;
	//bool	move_right;
	//bool	move_left;
	int		move_x;
	int		move_y;
	int		rotate;
}				t_player;

typedef struct s_img
{
    void    *mlx_img;
    int     *addr;
    int		bpp;
	int		line_len;
	int		endian;
}               t_img;

typedef struct s_map_info
{
    char    *no;
    char    *so;
    char    *ea;
    char    *we;
    char    *f;
    char    *c;
    int   cc_ceiling;
    int   cc_floor;
}               t_map_info;

typedef struct s_data
{
    void        *mlx;
    void        *win;
    char        **map;
	t_raycast	*ray;
    t_map_info  *map_info;
    t_img       img;
	t_player	*player;
    t_textures	*textures;
}               t_data;

/*---------- FUNCTIONS ----------*/

//VALID MAP
bool	valid_file(char *file, char *ext);
bool	valid_map(t_data *data, char *file);
bool	parse_identifiers(t_data *data, char *file);
bool	is_digit(char *str);
char	*trim_content(char *str);
int		rgb_to_int(char *str);
bool	parse_map(t_data *data, char *file);
bool	invalid_map(char **map);
bool	only_spaces(const char *str);
bool	parse_player(t_data *data, char **map);
int		lines_result(char *gnl, int fd, int lines, bool flg);
bool	border_check(char **map);

//INIT & FREE
t_data	*init_data(void);
void	free_data(t_data *data);
void	free_array(char **arr);
int		ft_quit(t_data *data);
void	init_game(t_data *data);
void	init_mlx(t_data *data);

//RENDER GAME
void	raycast(t_data *data);
int 	render_game(t_data *data);

//MOVEMNET
int		handle_key_press(int keysym, t_data *data);
int		handle_key_release(int keysym, t_data *data);
int		move_player(t_data *data);

#endif
