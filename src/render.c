/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabrrodr <gabrrodr@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/10 13:28:07 by gabrrodr          #+#    #+#             */
/*   Updated: 2024/07/10 13:28:07 by gabrrodr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int render_game(t_data *data)
{
    data->player->moved += move_player(data);
    if (data->player->moved == 0)
		return (EXIT_SUCCESS);
	raycast(data);
    //render_ceiling(data);
    //render_floor(data);
	return (EXIT_FAILURE);
}
