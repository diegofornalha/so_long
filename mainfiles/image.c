/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dida-sil <dida-sil@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/08 09:19:59 by dida-sil          #+#    #+#             */
/*   Updated: 2022/09/08 09:19:59 by dida-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	*put_image(t_image image, int x, int y)
{
	image.img = mlx_xpm_file_to_image(image.wlx.mlx,
			image.relative_path, &image.img_width, &image.img_height);
	mlx_put_image_to_window(image.wlx.mlx, image.wlx.window, image.img, x, y);
	return (image.img);
}

t_block	set_block(char name)
{
	t_block	maps[6];
	int		i;

	maps[0] = (t_block){"1", "./img/stone.xpm"};
	maps[1] = (t_block){"0", "./img/floor.xpm"};
	maps[2] = (t_block){"C", "./img/strash.xpm"};
	maps[3] = (t_block){"P", "./img/turtle_d.xpm"};
	maps[4] = (t_block){"E", "./img/hospital.xpm"};
	maps[5] = (t_block){0, 0};
	i = 0;
	while (maps[i].name != 0)
	{
		if (maps[i].name[0] == name)
		{
			return (maps[i]);
			break ;
		}
		i++;
	}
	return (maps[5]);
}
