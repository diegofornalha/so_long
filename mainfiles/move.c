/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dida-sil <dida-sil@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/08 09:19:49 by dida-sil          #+#    #+#             */
/*   Updated: 2022/09/08 09:19:49 by dida-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	update(t_game *game, int x, int y)
{
	t_image	image;

	image.relative_path = "./img/floor.xpm";
	image.wlx = *game;
	put_image(image, game->player.x, game->player.y);
	put_image(image, x, y);
}

void	right(t_game *game)
{
	int		i;
	int		j;
	t_image	image;

	image.relative_path = "./img/turtle_d.xpm";
	image.wlx = *game;
	i = game->player.y;
	j = game->player.x + 48;
	if ((move_check(game, (i / 48), (j / 48)) != 1))
	{
		game->player.hareket++;
		printf(GREEN"number of moves = %d\n"ENDC, game->player.hareket);
		update(game, j, i);
		game->player.y = i;
		game->player.x = j;
		put_image(image, j, i);
	}
}

void	left(t_game *game)
{
	int		i;
	int		j;
	t_image	image;

	image.relative_path = "./img/turtle_a.xpm";
	image.wlx = *game;
	i = game->player.y;
	j = game->player.x - 48;
	if ((move_check(game, (i / 48), (j / 48)) != 1))
	{
		game->player.hareket++;
		printf(GREEN"number of moves = %d\n"ENDC, game->player.hareket);
		update(game, j, i);
		game->player.y = i;
		game->player.x = j;
		put_image(image, j, i);
	}
}

void	up(t_game *game)
{
	int		i;
	int		j;
	t_image	image;

	image.relative_path = "./img/turtle_w.xpm";
	image.wlx = *game;
	i = game->player.y - 48;
	j = game->player.x;
	if ((move_check(game, (i / 48), (j / 48)) != 1))
	{
		game->player.hareket++;
		printf(GREEN"number of moves = %d\n"ENDC, game->player.hareket);
		update(game, j, i);
		game->player.y = i;
		game->player.x = j;
		put_image(image, j, i);
	}
}

void	down(t_game *game)
{
	int		i;
	int		j;
	t_image	image;

	image.relative_path = "./img/turtle_s.xpm";
	image.wlx = *game;
	i = game->player.y + 48;
	j = game->player.x;
	if ((move_check(game, (i / 48), (j / 48)) != 1))
	{
		game->player.hareket++;
		printf(GREEN"number of moves = %d\n"ENDC, game->player.hareket);
		update(game, j, i);
		game->player.y = i;
		game->player.x = j;
		put_image(image, j, i);
	}
}
