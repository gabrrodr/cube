/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabrrodr <gabrrodr@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/01 13:26:12 by digoncal          #+#    #+#             */
/*   Updated: 2024/07/10 12:30:55 by gabrrodr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

static void	print_info(t_data *data)
{
	int i = 0;
	printf("====================== MAP INFO ======================\n");
	printf("\nNO-> \"%s\"\nSO-> \"%s\"\nWE-> \"%s\"\nEA-> \"%s\"\nF-> \"%s\"\nC-> \"%s\"\n\n", data->map_info->no, data->map_info->so, data->map_info->we, data->map_info->ea, data->map_info->f, data->map_info->c);
	printf("Player: x-> %.2f | y-> %.2f | direction-> ", data->player->position.x, data->player->position.y);
	if (data->player->dir.x == 0 && data->player->dir.y == -1)
		printf("Front(N)\n\n");
	else if (data->player->dir.x == 0 && data->player->dir.y == 1)
		printf("Back(S)\n\n");
	else if (data->player->dir.x == -1 && data->player->dir.y == 0)
		printf("Left(W)\n\n");
	else if (data->player->dir.x == 1 && data->player->dir.y == 0)
		printf("Right(E)\n\n");
	else
		printf("(null)\n\n");
	printf("Ceiling color: %d\nFloor color: %d\n\n", data->map_info->cc_ceiling, data->map_info->cc_floor);
	while (data->map[i] != NULL) {
		printf("%s", data->map[i]);
		printf("\n");
		i++;
	}
	printf("\n");
	printf("====================== MAP INFO ======================\n\n");
}

 /*======================================== DEBUG ===============================================*/

int	main(int argc, char **argv)
{
	t_data	*data;

	if (argc != 2)
		return (ft_putstr_fd("Error: no file provided\n", 2), 1);
	if (!valid_file(argv[1], ".cub"))
		return (ft_putstr_fd("Error: Invalid file\n", 2), 1);
	data = init_data();
	if (!data || !valid_map(data, argv[1]))
		return (free_data(data), 1);
	print_info(data);
	init_game(data);
	free_data(data);
}
