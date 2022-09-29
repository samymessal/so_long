/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smessal <smessal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/07 15:23:44 by smessal           #+#    #+#             */
/*   Updated: 2022/09/29 15:40:05 by smessal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../utils/libft/libft.h"
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <X11/keysym.h>
# include <X11/X.h>
# include <stdio.h>
# include <stdlib.h>
# include "../mlx_linux/mlx.h"
/*----------------Structures-----------------*/
typedef struct s_img
{
	void	*mlx_img;
	char	*addr;
	int		bpp;
	int		line_len;
	int		endian;
	int		width;
	int		height;
}	t_img;

typedef struct s_data
{
	void	*mlx_ptr;
	void	*win_ptr;
	char	**map;
	int		*mechant;
	int		moves;
	int		counter;
}	t_data;

typedef struct s_all
{
	t_data	data;
	t_img	big;
	t_img	*imgs;
}	t_all;

typedef struct s_pos
{
	int	width;
	int	height;
}	t_pos;

/*---------------Events-----------------------*/
int		handle_keypress(int keysym, t_data *data);
int		mouse_click(t_data *data);
/*---------------Functions--------------------*/
char	*get_next_line(int fd);
int		ft_count_lines(char	*file_name);
char	**read_map(char *file_name);
/*---------------Image Process----------------*/
void	my_mlx_pixel_put(t_img *img, int x, int y, int color);
void	draw(t_img *img_big, t_img img_s, int x_dest, int y_dest);
int		download_image(t_data *data, t_img *img, char *path);
int		render(t_all *all);
void	conditions_draw(t_img *img_big, t_img *all, char map, t_pos pos);
/*---------------Initialize-------------------*/
t_img	*init_img(t_data *data);
void	draw_all(t_img *img_big, t_img *all, char **map);
int		init_win(char *filename, char **map);
void	move_mechant(t_data data);
void	init_mechant(t_data *data);
/*---------------Moves------------------------*/
t_pos	find_elem(char **map, char elem);
int		check_if_ok(char **map, t_pos pos_p, int keysym, char elem);
void	move(char **map, t_pos pos_p, int keysym);
void	update_map(char **map);
/*----------------Path finder--------------------*/
int		is_flooded(char **map);
void	fill(char **map, int y, int x);
void	flood(char **map);
int		valid_path(char **map);
int		flood_fill(char **map, int lines);
/*---------------Errors------------------------*/
int		ft_ber_file(char **av);
int		map_walls(char **map, char *filename);
int		count_elements(char **map, char elem);
int		map_elements(char **map);
int		square_map(char **map);
int		messages(char **av, char **map);
int		messages2(char **av, char **map);
/*----------------Free--------------------------*/
void	free_tab(char **map);
void	free_imgs(t_data data, t_img *imgs);
void	free_data(t_data *data);
void	free_all(t_all all);
#endif
