/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabrrodr <gabrrodr@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/10 13:44:18 by gabrrodr          #+#    #+#             */
/*   Updated: 2024/07/10 13:44:18 by gabrrodr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int move_player(t_data *data)
{
    int m;

    m = 0;

    if (data->player.move_y == 1)
        m += move_front(data);
    if (data->player.move_y == -1)
        m += move_back(data);
    if (data->player.move_x == 1)
        m += move_right(data);
    if (data->player.move_x == -1)
        m += move_left(data);
    if (data->player.rotate == 1)
        m += rotate(Right);

}