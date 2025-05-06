/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wall_check.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daeunki2 <daeunki2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/04 14:18:05 by daeunki2          #+#    #+#             */
/*   Updated: 2025/05/06 14:38:01 by daeunki2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	dup_map(t_game *game)
{
	int	i;
	int	flag;
	int	k;

	i = game->map_start;
	k = 0;
	flag = ft_identifi(game->copied_map[i]);
	game->map.grid = (char **)malloc((game->map_h + 1) * sizeof(char *));
	while (game->copied_map[i] && ft_identifi(game->copied_map[i]) == T_MAP)
	{
		game->map.grid[k] = ft_strdup(game->copied_map[i]);
		if (game->map.grid[k] == NULL)
		{
			error_msg("malloc fail_dupmap");
			break ;
		}
		i++;
		k++;
	}
	game->map.grid[k] = NULL;
}

static int	is_error(t_game *game, char **str, int i, int j)
{
	if (i == 0 || j == 0 || i == game->map_h - 1 || str[i][j + 1] == '\0')
		return (-1);
	if (str[i][j - 1] == ' ' || str[i][j + 1] == ' ')
		return (-1);
	if (!str[i - 1] || j >= (int)ft_strlen(str[i - 1]) || str[i - 1][j] == ' ')
		return (-1);
	if (!str[i + 1] || j >= (int)ft_strlen(str[i + 1]) || str[i + 1][j] == ' ')
		return (-1);
	else
		return (0);
}

int	surround_wall_check(t_game *game, char **str)
{
	int	i;
	int	j;

	i = 0;
	while (str[i])
	{
		j = 0;
		while (str[i][j])
		{
			if (str[i][j] == '0')
			{
				if (is_error(game, str, i, j) < 0)
					return (error_msg("Map is not enclosed."));
			}
			j++;
		}
		i++;
	}
	return (0);
}

void	set_player_pos(t_game *game, char **str)
{
	int	i;
	int	j;

	i = 0;
	while (str[i])
	{
		j = 0;
		while (str[i][j])
		{
			if (str[i][j] == 'W' || str[i][j] == 'E' || str[i][j] == 'S'
				|| str[i][j] == 'N')
			{
				game->player.pos_y = i + 0.049;
				game->player.pos_x = j + 0.049;
				game->player.dir = str[i][j];
				game->map.grid[i][j] = '0';
			}
			j++;
		}
		i++;
	}
}
