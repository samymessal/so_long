/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smessal <smessal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/07 15:23:44 by smessal           #+#    #+#             */
/*   Updated: 2022/09/02 19:47:06 by smessal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
#define SO_LONG_H

# include "../utils/libft/libft.h"
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h> 
# include <stdio.h>
# include <stdlib.h>
# include "../mlx_linux/mlx.h"

#define BUFFER_SIZE 1

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