/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: digoncal <digoncal@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/01 15:45:01 by digoncal          #+#    #+#             */
/*   Updated: 2024/07/01 15:45:01 by digoncal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

bool	valid_file(char *file, char *ext)
{
	char	*tmp_file;
	int		fd;

	tmp_file = ft_strrchr(file, '.');
	if (ft_strcmp(tmp_file, ext))
		return (false);
	fd = open(file, O_RDONLY);
	if (fd == -1)
		return (false);
	close(fd);
	return (true);
}
