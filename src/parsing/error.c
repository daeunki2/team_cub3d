/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daeunki2 <daeunki2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/25 14:05:00 by daeunki2          #+#    #+#             */
/*   Updated: 2025/05/04 18:45:33 by daeunki2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	error_msg(char *msg)
{
	printf("Error\n%s\n", msg);
	return (-1);
}


void	free_split(char **strs)
{
	int	i;

	i = 0;
	while (strs[i] != NULL)
	{
		free(strs[i]);
		i++;
	}
	free(strs);
}

void	parsing_error_out(t_game *game)
{
	int	i = 0;

	if (game->map.grid)
		free_split(game->map.grid);
	if (game->copied_map)
		free_split(game->copied_map);
	free(game->big_line);

	while (i < 4)
	{
		if (game->textures[i].img && game->mlx)
			mlx_destroy_image(game->mlx, game->textures[i].img);
		if (game->textures[i].path)
			free(game->textures[i].path);
		i++;
	}

	if (game->frame.img && game->mlx)
		mlx_destroy_image(game->mlx, game->frame.img);
}


// void	free_grid(char **grid, int height)
// {
// 	if (!grid)
// 		return;
// 	for (int i = 0; i < height; i++)
// 		free(grid[i]);
// 	free(grid);
// }

// void	destroy_images(t_game *game)
// {
// 	for (int i = 0; i < 4; i++)
// 	{
// 		if (game->textures[i].img)
// 			mlx_destroy_image(game->mlx, game->textures[i].img);
// 	}
// 	if (game->frame.img)
// 		mlx_destroy_image(game->mlx, game->frame.img);
// }

// void	parsing_error_out(t_game *game)
// {
// 	if (!game)
// 		return;

// 	// 이미지 해제
// 	destroy_images(game);

// 	// 맵 그리드 해제
// 	free_grid(game->map.grid, game->map.height);
// 	free_grid(game->copied_map, game->map.height);

// 	// 창과 mlx 해제
// 	if (game->win)
// 		mlx_destroy_window(game->mlx, game->win);
// 	if (game->mlx)
// 	{
// 		mlx_destroy_display(game->mlx); // Linux 환경일 때
// 		free(game->mlx);
// 	}

// 	// big_line 해제
// 	free(game->big_line);
// }
