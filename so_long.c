/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dokim2 <dokim2@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 15:48:40 by dokim2            #+#    #+#             */
/*   Updated: 2022/09/21 15:48:41 by dokim2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"


int main(void)
{
    t_mlx   mlx;
    t_game  game;
    t_param param;
    t_img   img;
    
    int     img_width;
    int     img_height;
    char    *full;
    int     full_size;
    game_init(&game);
    mlx.mlx_ptr = mlx_init();
    //size 받아오기
    full_size = checkopen_size("map.ber", &game);

    mlx.win_ptr = mlx_new_window(mlx.mlx_ptr, game.wid * 32, game.hei * 32, "mlx 42");

    img_init(&img, img_width, img_height, &mlx);
    read_map("map.ber", &game, &mlx, full_size);
    show_map(&game, &mlx, &img);
    //mlx_put_image_to_window(mlx.mlx_ptr, mlx.win_ptr, img.road, 0, 0);
    mlx_hook(mlx.win_ptr, X_EVENT_KEY_RELEASE, 0, &key_press, &param);
    mlx_hook(mlx.win_ptr, X_EVENT_KEY_EXIT, 0, &exit_game, &mlx);
    mlx_loop(mlx.mlx_ptr);
    return (0);
}