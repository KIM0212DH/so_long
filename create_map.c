/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dokim2 <dokim2@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 16:00:31 by dokim2            #+#    #+#             */
/*   Updated: 2022/09/21 16:00:31 by dokim2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void print_error(char *err_msg)
{
    int len = ft_strlen(err_msg);
    write(1, "***", 3);
    write(1, err_msg, len);
    write(1, "***", 3);
    exit(1);
}

int checkopen_size(char *filename, t_game *game)
{
    int     fd;
    char    *line;
    int     full_size;

    fd = open(filename, O_RDONLY);
    if (fd < 0)
        print_error("file open Error");
    line = get_next_line(fd);
    game->wid = ft_strlen(line) - 1;
    while (line > 0)
    {
        if (game->wid != ft_strlen(line) - 1)
            print_error("line count Error");
        game->hei = game->hei + 1;
        line = get_next_line(fd);
    }
    full_size = game->hei * game->wid;
    return (full_size);
}

char    *fill_full_map(char *full_map, char *filename, t_game *game)
{
    int     fd;
    int     idx;
    char    *line;
    char    *ret;

    idx = 0;
    fd = open(filename, O_RDONLY);
    line = get_next_line(fd);
    while (line)
    {
        ft_memmove(full_map + idx, line, ft_strlen(line) - 1);
        idx = idx + ft_strlen(line) - 1;
        line = get_next_line(fd);
    }

    ret = full_map;
    free(full_map);
    full_map = NULL;
    idx = 0;
    while (ret[idx] != '\0')
    {
        if ((idx < game->wid && ret[idx] != '1') || ((idx > game->wid * (game->hei - 1)) && ret[idx] != '1'))
            print_error("wall Error");
        if ((idx % game->wid == 0 && ret[idx] != '1') || (idx % game->wid == game->wid - 1 && ret[idx] != '1'))
            print_error("wall Error");
        if (ret[idx] == 'C')
            game->collection++;
        if (ret[idx] == 'P')
            game->player++;
        if (ret[idx] == 'E')
            game->exit++;
        idx++;
    }
    return (ret);
}

char    *read_map(char *filename, t_game *game, t_mlx *mlx, int full_size)
{
    char    *line;
    
    //this.full_size = full_size;
    game->full_map = (char *) malloc (sizeof(char) * (full_size + 1));
    if (!game->full_map)
        return NULL;
    game->full_map[full_size] = '\0';
    game->full_map = fill_full_map(game->full_map, filename, game);
    //game->full_map[full_size] = '\0';

    return (game->full_map);
}

void    show_map(t_game *game, t_mlx *mlx, t_img *img)
{
    int hei;
    int wid;

    hei = 0;
    printf("%s\n", game->full_map);
    printf("%d %d\n", game->wid, game->hei);
    while (hei < game->hei)
    {
        wid = 0;
        while (wid < game->wid)
        {
            printf("hei : %d\nwid : %d\n", hei, wid);
            printf("%d %d\n", game->wid, game->hei);
            printf("%s\n", game->full_map);
            if (game->full_map[hei * game->wid + wid] == '1')
            {
                mlx_put_image_to_window(mlx->mlx_ptr, mlx->win_ptr, img->wall, wid * 32, hei * 32);
            }
            /*
            else if (game->full_map[hei * game->wid + wid] == 'C')
            {
                ;
            }
            else if (game->full_map[hei * game->wid + wid] == 'P')
            {
                ;   
            }
            else if (game->full_map[hei * game->wid + wid] == 'E')
            {
                ;
            }
            */
            else
            {
                mlx_put_image_to_window(mlx->mlx_ptr, mlx->win_ptr, img->road, wid * 32, hei * 32);
            }
            wid++;
        }
        hei++;
    }
}