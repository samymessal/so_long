/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smessal <smessal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/08 15:27:08 by smessal           #+#    #+#             */
/*   Updated: 2022/09/08 22:16:53 by smessal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

t_img	*init_img(t_data *data)
{
	t_img	*all;
	int		i;
	
	i = 0;
	all = malloc(sizeof(t_img) * 7);
	if (!all)
		return (0);
	download_image(data, &all[0], "img/case_0.xpm");
	download_image(data, &all[1], "img/fence.xpm");
	download_image(data, &all[2], "img/douane.xpm");
	download_image(data, &all[3], "img/passport.xpm");
	download_image(data, &all[4], "img/player.xpm");
	download_image(data, &all[5], "img/dog.xpm");
	download_image(data, &all[6], "img/boat.xpm");
	return (all);
}

void	draw_all(t_img *img_big, t_img *all, t_pos screen, char **map)
{
	int	i;
	int	j;
	int	x;
	int	y;

	i = 0;
	x = 0;
	y = 0;
	(void)screen;
	while (map[i])
	{
		j = 0;
		while (map[i][j] != '\0' && map[i][j] != '\n')
		{
			if (map[i][j] == '0')
				draw(img_big, all[0], x, y);
			else if (map[i][j] == '1')
				draw(img_big, all[1], x, y);
			else if (map[i][j] == 'C')
				draw(img_big, all[3], x, y);
			else if (map[i][j] == 'P')
				draw(img_big, all[4], x, y);
			else if (map[i][j] == 'E')
				draw(img_big, all[5], x, y);
			x += 64;
			j++;
			printf("%d\n", j);
		}
		i++;
		y += 64;
	}
}

void	init_win(char *filename)
{
	char	**map;
	t_data	data;
	t_pos	screen;
	t_img	*imgs;
	t_img	big;
	
	map = read_map(filename);
	// if (!map || !errors_man(av, map, ft_count_lines(filename)))
	// {
	// 	write(1, "Error\n", 6);
	// 	return (0);
	// }
	screen.width = (ft_strlen(map[0]) - 1) * 64;
	screen.height = (ft_count_lines(filename)) * 64;
	printf("%d\n", screen.height);
	data.mlx_ptr = mlx_init();
	data.win_ptr = mlx_new_window(data.mlx_ptr, screen.width, screen.height, "SO_LONG");
	big.mlx_img = mlx_new_image(data.mlx_ptr, WINDOW_WIDTH, WINDOW_HEIGHT);
	big.addr = mlx_get_data_addr(big.mlx_img, &big.bpp, &big.line_len, &big.endian);
	imgs = init_img(&data);
	draw_all(&big, imgs, screen, map);
	// printf("test\n");
	mlx_put_image_to_window(data.mlx_ptr, data.win_ptr, big.mlx_img, 0, 0);
	mlx_hook(data.win_ptr, KeyPress, KeyPressMask, &handle_keypress, &data);
	mlx_hook(data.win_ptr, KeyRelease, KeyReleaseMask, &handle_keyrelease, &data);
	mlx_loop(data.mlx_ptr);
}
