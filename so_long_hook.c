/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_hook.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dokim2 <dokim2@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 18:54:04 by dokim2            #+#    #+#             */
/*   Updated: 2022/09/21 18:54:06 by dokim2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int key_press(int keycode, t_param *param)
{
    if (keycode == KEY_W)
        param->y++;
    else if (keycode == KEY_S)
        param->y--;
    else if (keycode == KEY_A)
        param->x--;
    else if (keycode == KEY_D)
        param->x++;
    else if (keycode == KEY_ESC)
        exit(0);
    printf("x: %d, y: %d\n", param->x, param->y);
    return (0);
}

int exit_game(t_mlx *mlx)
{
    mlx_destroy_window(mlx->mlx_ptr, mlx->win_ptr);
    exit(0);
}