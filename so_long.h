/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dokim2 <dokim2@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 15:48:50 by dokim2            #+#    #+#             */
/*   Updated: 2022/09/21 15:48:51 by dokim2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "minilibx_opengl_20191021/mlx.h"
#include "get_next_line/get_next_line.h"
#include <stdlib.h>
#include <fcntl.h>
#include <stdio.h>

# define X_EVENT_KEY_PRESS      2
# define X_EVENT_KEY_RELEASE    3
# define KEY_ESC                53
# define KEY_W                  13
# define KEY_A                  0
# define KEY_S                  1
# define KEY_D                  2
# define X_EVENT_KEY_EXIT       17


typedef struct  s_param
{
    int x;
    int y;
}   t_param;

typedef struct  s_mlx
{
    void    *mlx_ptr;
    void    *win_ptr;
}   t_mlx;

typedef struct  s_game
{
    char    *full_map;
    int     hei;
    int     wid;
    int     collection;
    int     player;
    int     exit;
}   t_game;

typedef struct  s_img
{
    void    *road;
    void    *wall;
    void    *chara;
    void    *exit1;
    void    *exit2;
    void    *collect;
}   t_img;

void    param_init(t_param *param);
void    game_init(t_game *game);
void    img_init(t_img *img, int img_width, int img_height, t_mlx *mlx);
void print_error(char *err_msg);
int checkopen_size(char *filename, t_game *game);
char    *fill_full_map(char *full_map, char *filename, t_game *game);
char    *read_map(char *filename, t_game *game, t_mlx *mlx, int full_size);
void    show_map(t_game *game, t_mlx *mlx, t_img *img);
int key_press(int keycode, t_param *param);
int exit_game(t_mlx *mlx);
