/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabrrodr <gabrrodr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/01 14:44:10 by gabrrodr          #+#    #+#             */
/*   Updated: 2024/07/08 15:40:51 by digoncal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

t_data	*init_data(void)
{
	t_data	*data;

	data = malloc(sizeof(t_data));
	if (!data)
		return (ft_putstr_fd("Error: malloc execution.\n", 2), NULL);
	data->mlx = NULL;
	data->win = NULL;
	data->img = NULL;
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
