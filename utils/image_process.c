/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image_process.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smessal <smessal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/04 16:21:58 by smessal           #+#    #+#             */
/*   Updated: 2022/09/08 22:05:24 by smessal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	my_mlx_pixel_put(t_img *img, int x, int y, int color)
{
	char	*dst;

	dst = img->addr + (y * img->line_len + x * (img->bpp / 8));
	*(unsigned int*)dst = color;
}

void	draw(t_img *img_big, t_img img_s, int x_dest, int y_dest)
{
	int	i;
	int	j;
	int	color;
	int	temp;
	
	i = 0;
	j = 0;
	temp = x_dest;
	color = 0;
	while (i < 64)
	{
		j = 0;
		x_dest = temp;
		while (j < 64)
		{
			color = *(int *)(img_s.addr + i * img_s.line_len + j * 4);
			my_mlx_pixel_put(img_big, x_dest, y_dest, color);
			x_dest++;
			j++;
		}
		y_dest++;
		i++;
	}	
}

void	download_image(t_data *data, t_img *img, char *path)
{	
	img->height = 0;
	img->width = 0;
	img->mlx_img = mlx_xpm_file_to_image(data->mlx_ptr, path, &img->width, &img->height);
	img->addr = mlx_get_data_addr(img->mlx_img, &img->bpp, &img->line_len, &img->endian);
	return ;
}

int	render(t_all *all)
{
	mlx_put_image_to_window(all->data->mlx_ptr, all->data->win_ptr, all->img->mlx_img, 0, 0);
	return (0);
}

// int	main(void)
// {
// 	t_data	data;
// 	t_img	img;
// 	t_img	img_wall;
// 	t_all	test;

// 	data.mlx_ptr = mlx_init();
// 	data.win_ptr = mlx_new_window(data.mlx_ptr, WINDOW_WIDTH, WINDOW_HEIGHT, "SO_LONG");
	
// 	img.mlx_img = mlx_new_image(data.mlx_ptr, WINDOW_WIDTH, WINDOW_HEIGHT);
// 	img.addr = mlx_get_data_addr(img.mlx_img, &img.bpp, &img.line_len, &img.endian);

// 	download_image(&data, &img_wall, "img/grillage_cc8233_size.xpm");
// 	img_wall.addr = mlx_get_data_addr(img_wall.mlx_img, &img_wall.bpp, &img_wall.line_len, &img_wall.endian);
// 	draw(&img, &img_wall, 0, 0);
// 	test.data = &data;
// 	test.img = &img;
// 	//mlx_loop_hook(data.mlx_ptr, &render, &test);
// 	mlx_put_image_to_window(test.data->mlx_ptr, test.data->win_ptr, test.img->mlx_img, 0, 0);

// 	mlx_hook(data.win_ptr, KeyPress, KeyPressMask, &handle_keypress, &data);
// 	mlx_hook(data.win_ptr, KeyRelease, KeyReleaseMask, &handle_keyrelease, &data);
// 	mlx_loop(data.mlx_ptr);
// 	// mlx_destroy_display(data.mlx_ptr);
// 	// free(data.mlx_ptr);
// }