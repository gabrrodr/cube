/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: digoncal <digoncal@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/01 15:55:50 by digoncal          #+#    #+#             */
/*   Updated: 2024/07/01 15:55:50 by digoncal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

bool	valid_map(t_data *data, char *file)
{
	if (parse_identifiers(data, file))
		return (false);
	/*if (parse_map(data, file))
		return (false);
	if (parse_player(data, data->map))
		return (false);*/
	return (true);
	/*CHECK IF IN THERE'S RANDOM TEXT IN THE MAP (IT SHOULD BE INVALID)*/
}
