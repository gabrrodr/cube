/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabrrodr <gabrrodr@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/10 13:28:07 by gabrrodr          #+#    #+#             */
/*   Updated: 2024/07/17 13:37:59 by digoncal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

static void	set_limits(t_data *data, int ray_x, int x, int y)
{
	double			tex_pos;
	double			step;
	int				i;
	int				color;

	step = 1.0 * 64 / data->ray->line_height;
	tex_pos = (data->ray->draw_start - WIN_HEIGHT / 2 + data->ray->line_height / 2) * step;
	i = data->ray->draw_start;
	while (i < data->ray->draw_end && i < WIN_WIDTH)
	{
		y = ((int) tex_pos & (64 - 1));
		tex_pos += step;
		if (ray_x >= 0 && i >= 0 && x >= 0 && y >= 0)
		{
			if (data->ray->wall_dir == NORTH || data->ray->wall_dir == SOUTH)
				color = rgb_to_int("9, 121, 105");
			else
				color = rgb_to_int("175, 225, 175");
			mlx_pixel_put(data->mlx, data->win, ray_x, i, color);
		}
		i++;
	}
}

void	load_texture(t_data *data, int ray_x)
{
	double	wall_x;
	int		x;
	int 	y;

	y = 0;
	if (!data->ray->side)
	{
		wall_x = data->player->position.y + data->ray->wall_dist * data->ray->dir.y;
		wall_x -= data->ray->map_y;
	}
	else
	{
		wall_x = data->player->position.x + data->ray->wall_dist * data->ray->dir.x;
		wall_x -= data->ray->map_x;
	}
	x = (int)(wall_x * (double)64);
	x = 64 - x - 1;
	set_limits(data, ray_x, x, y);
}

void	pick_texture(t_data *data)
{
	if (data->ray->dir.x < 0 && !data->ray->side)
	{
		data->ray->wall_dir = EAST;
		return ;
	}
	else if (!data->ray->side)
	{
		data->ray->wall_dir = WEST;
		return ;
	}
	if (data->ray->dir.y < 0)
	{
		data->ray->wall_dir = SOUTH;
		return ;
	}
	else
		data->ray->wall_dir = NORTH;
}

static void	render_floor_ceiling(t_data *data)
{
	double	y;
	double	x;
	t_img	image;

	image.mlx_img = NULL;
	if (!init_mlx_img(data, &image, WIN_WIDTH, WIN_HEIGHT))
		return ;
	x = -1;
	while (++x < WIN_WIDTH)
	{
		y = 0;
		while (y < (double)WIN_HEIGHT / 2)
			image.addr[(int)y++ *(image.line_len / 4) + (int)x] \
				= data->map_info->cc_ceiling;
		while (y < WIN_HEIGHT)
			image.addr[(int)y++ *(image.line_len / 4) + (int)x] \
				= data->map_info->cc_floor;
	}
	mlx_put_image_to_window(data->mlx, data->win, image.mlx_img, 0, 0);
	mlx_destroy_image(data->mlx, image.mlx_img);
}

void	render(t_data *data)
{
	render_floor_ceiling(data);
	raycast(data);
}

int	render_game(t_data *data)
{
	data->player->moved += move_player(data);
	if (data->player->moved == 0)
		return (EXIT_SUCCESS);
	render(data);
	return (EXIT_FAILURE);
}
