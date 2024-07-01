/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabrrodr <gabrrodr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 16:06:46 by digoncal          #+#    #+#             */
/*   Updated: 2024/07/01 15:29:18 by gabrrodr         ###   ########.fr       */
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

/*------------- STRUCTURES ---------------*/

typedef struct s_pos
{
	double	x;
	double	y;
}				t_pos;

typedef struct s_textures
{
	
}				t_textures;

typedef struct s_player
{
	t_pos	position;
	t_pos	dir;
	t_pos	cam;
	bool	move_up;
	bool	move_down;
	bool	move_right;
	bool	move_left;
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
    t_map_info  *map_info;
    t_img       img;
	t_player	*player;
	//t_raycast	*ray;
    t_textures	*textures;
}               t_data;

/*---------- FUNCTIONS ----------*/

t_data	*init_data(void);

//VALID MAP
bool	valid_file(char *file, char *ext);
bool	valid_map(t_data *data, char *file);
bool	parse_identifiers(t_data *data, char *file);
bool	is_digit(char *str);
char	*trim_content(char *str);
int		rgb_to_int(char *str);

#endif