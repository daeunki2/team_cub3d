/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wall_check.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daeunki2 <daeunki2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/04 14:18:05 by daeunki2          #+#    #+#             */
/*   Updated: 2025/05/05 13:38:20 by daeunki2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void  dup_map(t_game *game)
{
    int i;
    int flag;
    int k;
 
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
            break; 
        }
        i++;
        k++;
    }
    game->map.grid[k] = NULL;
}

int surround_wall_check(t_game *game, char **str)
{
	int i = 0;
	int j;

	while (str[i])
	{
		j = 0;
		while (str[i][j])
		{
			if (str[i][j] == '0')
			{
				if (i == 0 || j == 0 || i == game->map_h - 1 || str[i][j + 1] == '\0')
					return (error_msg("map has to be closed1."));
				if (str[i][j - 1] == ' ' || str[i][j + 1] == ' ')
					return (error_msg("map has to be closed2."));
				if (!str[i - 1] || j >= (int)ft_strlen(str[i - 1]) || str[i - 1][j] == ' ')
					return (error_msg("map has to be closed3."));
				if (!str[i + 1] || j >= (int)ft_strlen(str[i + 1]) || str[i + 1][j] == ' ')
					return (error_msg("map has to be closed4."));
			}
			j++;
		}
		i++;
	}
	return (0);
}

// int    surround_wall_check(t_game *game, char **str)
// {
// 	int	i;
// 	int	j;

// 	i = 0;
// 	while (str[i])
// 	{
// 		j = 0;
// 		while (str[i][j])
// 		{
// 			if (str[i][j] == '0')
// 			{
// 				if (i == 0 || j == 0 || i == game->map_h - 1 || str[i][j + 1] == '\0') // 맨 앞이거나 맨 위일때는 0이 나오면 안됨
// 					return(error_msg("map has to be closed1."));
// 				else if (i == game->map_h || !str[i][j + 1]) // 맨 아래거나 맨 뒤일때도 0이 나오면 안됨
//                     return(error_msg("map has to be closed2."));
// 				else if (str[i][j - 1] == ' ' || str[i][j + 1] == ' ') // 0의 앞이나 뒤가 공백인지 확인
//                     return(error_msg("map has to be closed3."));
// 				else if (str[i + 1][j] == ' ' || str[i - 1][j] == ' ') // 0의 위나 아래가 공백인지 확인
//                     return(error_msg("map has to be closed4."));
// 			}
// 			j++;
// 		}
// 		i++;
// 	}
//     return(0);
// }

// int surround_wall_check(t_game *game)
// {
// 	int row = 0;
// 	int col;

// 	while (row < game->map_h)
// 	{
// 		col = 0;
// 		while (game->map.grid[row][col])
// 		{
// 			if (game->map.grid[row][col] == '0')
// 			{
// 				// 맨 위, 맨 아래, 맨 왼쪽, 맨 오른쪽은 안 됨
// 				if (row == 0 || col == 0 || row == game->map_h - 1 || game->map.grid[row][col + 1] == '\0')
// 					return (error_msg("map has to be closed1"));

// 				// 좌우가 공백이면 안 됨
// 				if (game->map.grid[row][col - 1] == ' ' || game->map.grid[row][col + 1] == ' ')
// 					return (error_msg("map has to be closed2"));

// 				// 윗줄이 짧거나 공백이면 안 됨
// 				if (row - 1 < 0 || (int)ft_strlen(game->map.grid[row - 1]) <= col ||
// 					game->map.grid[row - 1][col] == ' ')
// 					return (error_msg("map has to be closed3"));

// 				// 아랫줄이 짧거나 공백이면 안 됨
// 				if (row + 1 >= game->map_h || (int)ft_strlen(game->map.grid[row + 1]) <= col ||
// 					game->map.grid[row + 1][col] == ' ')
// 					return (error_msg("map has to be closed4"));
// 			}
// 			col++;
// 		}
// 		row++;
// 	}
// 	return (0);
// }



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
				game->player.pos_y= i + 0.049;
				game->player.pos_x = j+ 0.049;
                game->player.dir = str[i][j];
				game->map.grid[i][j] = '0';
			}
			j++;
		}
		i++;
	}
}

static void	init_direction(t_game *game)
{
	if (game->player.dir == 'N')
	{
		game->player.dir_x = 0.0;
		game->player.dir_y = -1.0;
	}
	else if (game->player.dir == 'S')
	{
		game->player.dir_x = 0.0;
		game->player.dir_y = 1.0;
	}
	else if (game->player.dir == 'E')
	{
		game->player.dir_x = 1.0;
		game->player.dir_y = 0.0;
	}
	else if (game->player.dir == 'W')
	{
		game->player.dir_x = -1.0;
		game->player.dir_y = 0.0;
	}
}

static void	init_plane(t_game *game)
{
	if (game->player.dir == 'N')
	{
		game->player.plane_x = 0.66;
		game->player.plane_y = 0.0;
	}
	else if (game->player.dir == 'S')
	{
		game->player.plane_x = -0.66;
		game->player.plane_y = 0.0;
	}
	else if (game->player.dir == 'E')
	{
		game->player.plane_x = 0.0;
		game->player.plane_y = 0.66;
	}
	else if (game->player.dir == 'W')
	{
		game->player.plane_x = 0.0;
		game->player.plane_y = -0.66;
	}
}

int set_map(t_game *game)
{
	dup_map(game);//for wall check.
	if (game->map.grid == NULL)
		return(error_msg("malloc fail set_game"));
    if (surround_wall_check(game, game->map.grid) != 0)
        return(-1);
    set_player_pos(game, game->map.grid);
	game->player.move_speed = 0.05;
	game->player.rot_speed = 0.05;
	init_direction(game);
	init_plane(game);
    return(0);
}