/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_player.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: digoncal <digoncal@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/02 15:57:41 by digoncal          #+#    #+#             */
/*   Updated: 2024/07/02 16:12:40 by digoncal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	get_direction(t_data *data, char c)
{
	if (c == 'N')
	{
		data->player->dir.x = 0;
		data->player->dir.y = -1;
	}
	else if (c == 'S')
	{
		data->player->dir.x = 0;
		data->player->dir.y = 1;
	}
	else if (c == 'W')
	{
		data->player->dir.x = -1;
		data->player->dir.y = 0;
	}
	else if (c == 'E')
	{
		data->player->dir.x = 1;
		data->player->dir.y = 0;
	}
}

bool	parse_player(t_data *data, char **map)
{
	t_pos	pos;
	int		players;

	players = 0;
	if (!data->player)
		return (ft_putstr_fd("Error: invalid player.\n", 2), false);
	pos.y = -1;
	while (map[(int)++pos.y])
	{
		pos.x = -1;
		while (map[(int)pos.y][(int)++pos.x])
		{
			if (map[(int)pos.y][(int)pos.x] == 'N' || map[(int)pos.y][(int)pos.x] == 'S'
				|| map[(int)pos.y][(int)pos.x] == 'W' || map[(int)pos.y][(int)pos.x] == 'E')
			{
				/*data->player->position.x = pos.x;
				data->player->position.y = pos.y;
				get_direction(data, map[(int)pos.y][(int)pos.x]);*/
				//Checkar com a Gaby como guardar info
				players++;
			}
		}
	}
	if (players == 1)
		return (true);
	return (ft_putstr_fd("Error: invalid player.\n", 2), false);
}
