/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smessal <smessal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/07 15:23:44 by smessal           #+#    #+#             */
/*   Updated: 2022/09/04 18:28:45 by smessal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
#define SO_LONG_H

# include "../utils/libft/libft.h"
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <X11/keysym.h>
# include <X11/X.h>
# include <stdio.h>
# include <stdlib.h>
# include "../mlx_linux/mlx.h"

#define BUFFER_SIZE 1
#define RED_PIXEL 0xFF0000
#define GREEN_PIXEL 0xFF00
#define WINDOW_HEIGHT 1000
#define WINDOW_WIDTH 2000
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
}	t_data;

typedef struct s_all
{
	t_data	*data;
	t_img	*img;
}	t_all;

/*---------------Events-----------------------*/
int	handle_keypress(int keysym, t_data *data);
int	handle_no_event(void *data);
int	handle_keyrelease(int keysym, void *data);
/*---------------Functions--------------------*/
char	*get_next_line(int fd);
int		ft_count_lines(char	*file_name);
char	**read_map(char *file_name);
int		errors_man(char **av, char **map, int lines);
int		ft_ber_file(char **av);
int		map_walls(char **map, int lines);
int		count_elements(char **map, char elem);
int		map_elements(char **map);
int		square_map(char **map);

#endif