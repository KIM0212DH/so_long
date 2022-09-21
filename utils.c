/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dokim2 <dokim2@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 16:59:18 by dokim2            #+#    #+#             */
/*   Updated: 2022/09/21 16:59:19 by dokim2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void    param_init(t_param *param)
{
    param->x = 0;
    param->y = 0;
}

void    game_init(t_game *game)
{
    game->hei = 0;
    game->wid = 0;
    game->collection = 0;
    game->player = 0;
    game->exit = 0;
}

void    img_init(t_img *img, int img_width, int img_height, t_mlx *mlx)
{
    img->road = mlx_xpm_file_to_image(mlx->mlx_ptr, "./images/road.xpm", &img_width, &img_height);
    img->wall = mlx_xpm_file_to_image(mlx->mlx_ptr, "./images/wall.xpm", &img_width, &img_height);
}
