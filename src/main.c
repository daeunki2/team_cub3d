/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daeunki2 <daeunki2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/28 20:25:04 by rgrochow          #+#    #+#             */
/*   Updated: 2025/05/04 18:47:16 by daeunki2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	main(int argc, char **argv)
{
	t_game	game;

	if (argc != 2)
		(printf("Usage: ./cub3D maps/<map_fileddddd>\n"), exit(0));
	ft_memset(&game, 0, sizeof(t_game));
	if (do_parsing(&game, argv[1]) == -1)
	{
		parsing_error_out(&game);//todo
		return (-1);
	}
	if (set_map(&game) != 0)
	{
		parsing_error_out(&game);//todo
		return(-1);
	}
	init_game(&game);
	mlx_mouse_move(game.mlx, game.win, game.win_w / 2, game.win_h / 2);
	mlx_hook(game.win, 2, 1L << 0, key_press, &game);
	mlx_hook(game.win, 3, 1L << 1, key_release, &game);
	mlx_hook(game.win, 6, 1L << 6, mouse_move, &game);
	mlx_hook(game.win, 17, 0, close_window, &game);
	mlx_mouse_hide(game.mlx, game.win);
	mlx_loop_hook(game.mlx, loop_hook, &game);
	mlx_loop(game.mlx);
	clear_game(&game);
	return (0);
}

// {
// 	int q;
// 	int i = 0;
// 	q = 0;
// 	int type;
// 	while(game.copied_map[q] != NULL)
// 	{
// 		type = ft_identifi(game.copied_map[q]);
// 		printf("%d %s \n", type, game.copied_map[q]);
// 		q++;
// 	}

// 	i = 0;
// 	while (i < 4)
// 	{
// 		printf("%d [%s] [%d]\n", game.textures[i].type, game.textures[i].path, game.textures[i].count);
// 		i++;
// 	}
// 	printf("ceil = [%d]\n", game.ceiling_color);

// 	printf("ceil_n = [%d]\n", game.ceiling_count);
// 	printf("floor = [%d]\n", game.floor_color);
// 	printf("player = [%d]\n", game.player_count);
// 	printf("map_h = [%d]\n", game.map_h);
// 	printf("map_w = [%d]\n", game.map_w);

// 	return (0);
// 	}
	// check_file(argv[1]);
	// init_imgs(&game, argv[1]);
	// init_map(&game, argv[1]);
	// check_map(&game);
	// init_game(&game);