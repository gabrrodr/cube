/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabrrodr <gabrrodr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/01 14:44:10 by gabrrodr          #+#    #+#             */
/*   Updated: 2024/07/01 15:28:56 by gabrrodr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	init_data()
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
	
}