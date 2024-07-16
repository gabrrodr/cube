/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: digoncal <digoncal@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/15 12:06:52 by digoncal          #+#    #+#             */
/*   Updated: 2024/07/16 12:41:51 by digoncal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

static bool	valid_border(char **map)
{
	int	y;
	int	lines;

	lines = 0;
	while (map[lines])
		lines++;
	if (ft_strchr(map[0], 'F') || ft_strchr(map[lines - 1], 'F'))
		return (false);
	y = -1;
	while (map[++y])
		if (map[y][0] == 'F' || map[y][ft_strlen(map[y]) - 1] == 'F')
			return (false);
	return (true);
}

static void	fill(char **map, int y, int x)
{
	if (x < 0 || y < 0 || !map[y] || map[y][x] == '\0')
		return ;
	if (map[y][x] == '1' || map[y][x] == 'F')
		return ;
	map[y][x] = 'F';
	fill(map, y - 1, x);
	fill(map, y + 1, x);
	fill(map, y, x - 1);
	fill(map, y, x + 1);
}

static	char	**copy_darr(char **arr)
{
	char	**copy;
	int		i;

	i = 0;
	while (arr[i])
		i++;
	copy = ft_calloc(i + 1, sizeof(char *));
	if (!copy)
		return (NULL);
	i = 0;
	while (arr[i])
	{
		copy[i] = ft_strdup(arr[i]);
		if (!copy[i])
			return (free_array(copy), NULL);
		i++;
	}
	copy[i] = NULL;
	return (copy);
}

bool	border_check(char **map)
{
	char	**map_copy;
	int		x;
	int		y;

	map_copy = copy_darr(map);
	if (!map_copy)
		return (true);
	y = -1;
	while (map_copy[++y])
	{
		x = 0;
		while (map_copy[y][x] == ' ' || map_copy[y][x] == '1')
			x++;
		if (map_copy[y][x] == '0')
			break ;
	}
	fill(map_copy, y, x);
	if (!valid_border(map_copy))
	{
		free_array(map_copy);
		return (ft_putstr_fd("Error: invalid map borders.\n", 2), true);
	}
	free_array(map_copy);
	return (false);
}
