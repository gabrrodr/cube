/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabrrodr <gabrrodr@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/01 14:44:10 by gabrrodr          #+#    #+#             */
/*   Updated: 2024/07/08 15:47:10 by gabrrodr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"


//make exit_error function with destroy image and free the data struct
void	init_mlx(t_data *data)
{
	t_img	screen_img;

	data->mlx = mlx_init();
	if (!data->mlx)
		return (ft_putstr_fd("Error: mlx init\n", 2), NULL);
	data->win = mlx_new_window(data->mlx, SCREEN_WIDTH, SCREEN_HEIGHT, "cube3D");
	if (!data->win)
		return (ft_putstr_fd("Error: mlx_win\n", 1), NULL);
	screen_img.img =mlx_new_image(data->mlx, SCREEN_HEIGHT, SCREEN_WIDTH);
	screen_img.addr = (int *)mlx_get_data_addr(screen_img.img, &screen_img.bpp, 
				&screen_img.line_len, &screen_img.endian);
	data->screen_img = screen_img;
}

void	init_game(t_data *data)
{
	init_mlx(data);
	//handle textures
	mlx_hook(data->win, KeyPress, KeyPressMask, &handle_key_press, NULL);
	mlx_hook(data->win, KeyRelease, KeyReleaseMask, &handle_key_release, NULL);
	mlx_hook(data->win, DestroyNotify, StructureNotifyMask, &ft_quit, NULL);
	mlx_loop_hook(data->mlx, render_game, NULL);
	set_player(data);
	mlx_loop(data->mlx);
}

t_data	*init_data(void)
{
	t_data	*data;

	data = malloc(sizeof(t_data));
	if (!data)
		return (ft_putstr_fd("Error: malloc execution.\n", 2), NULL);
	data->mlx = NULL;
	data->win = NULL;
	data->map = NULL;
	data->map_info = ft_calloc(1, sizeof(t_map_info));
	if (!data->map_info)
		return (ft_putstr_fd("Error: malloc execution.\n", 2), NULL);
	data->textures = ft_calloc(1, sizeof(t_textures));
	if (!data->textures)
		return (ft_putstr_fd("Error: mallos execution.\n", 2), NULL);
	data->player = ft_calloc(1, sizeof(t_player));
	if (!data->player)
		return (ft_putstr_fd("Error: malloc execution.\n", 2), NULL);
	return (data);
}

