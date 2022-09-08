/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smessal <smessal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/07 12:47:31 by smessal           #+#    #+#             */
/*   Updated: 2022/09/08 14:00:47 by smessal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/so_long.h"
#include <X11/keysym.h>
#include <X11/X.h>

#define RED_PIXEL 0xFF0000
#define GREEN_PIXEL 0xFF00
#define WINDOW_HEIGHT 1000
#define WINDOW_WIDTH 2000

typedef struct s_rect
{
	int	x;
	int	y;
	int width;
	int height;
	int color;
}	t_rect;

int	handle_keypress(int keysym, t_data *data)
{
	if (keysym == XK_Escape)
		mlx_destroy_window(data->mlx_ptr, data->win_ptr);
	printf("Keypress: %d\n", keysym);
	return (0);
}

int	handle_no_event(void *data)
{
	t_data	*test;
	
	test = data;
	return (0);
}
int	handle_keyrelease(int keysym, void *data)
{
	/* This function needs to exist, but it is useless for the moment */
	t_data	*test;

	printf("Keyrelease: %d\n", keysym);
	test = data;
	return (0);
}

int	render_rect(t_data *data, t_rect rect)
{
	int	i;
	int	j;
	
	i = rect.y;
	while (i < rect.y + rect.height)
	{
		j = rect.x;
		while (j < rect.x + rect.width)
		{
			mlx_pixel_put(data->mlx_ptr, data->win_ptr, j, i, rect.color);
			j++;
		}
		i++;
	}
	return (0);
}

void	img_pix_put(t_img *img, int x, int y, int color)
{
	char    *pixel;

	pixel = img->addr + (y * img->line_len + x * (img->bpp / 8));
	*(int *)pixel = color;
}

int	render_rect_img(t_img *img, t_rect rect)
{
	int	i;
	int	j;

	i = rect.y;
	while (i < rect.y + rect.height)
	{
		j = rect.x;
		while (j < rect.x + rect.width)
		{
			img_pix_put(img, j, i, rect.color);
			j++;
		}
		i++;
	}
	return (0);
}

int	render(t_data *data)
{
	t_rect	rect1;
	int		i;
	//int		j;

	i = 0;
	rect1.x = 0;
	rect1.y = 0;
	rect1.height = WINDOW_HEIGHT;
	rect1.width = WINDOW_WIDTH;
	rect1.color = RED_PIXEL;
	// if (data->win_ptr)
	// {
	// 	render_rect_img(&data->img, rect1);
	// 	render_rect_img(&data->img, (t_rect){0, 0, 100, 100, GREEN_PIXEL});
	// }
	while (i <= WINDOW_WIDTH)
	{
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img.mlx_img, i, 0);
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img.mlx_img, i, WINDOW_HEIGHT);
		i += 64;
	}
	return (0);
}
// void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
// {
// 	char	*dst;

// 	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
// 	*(unsigned int*)dst = color;
// }


int main(void)
{
	t_data	data;
	t_data	data0;
	int		x;
	int		y;

	x = 0;
	y = 0;
	data.mlx_ptr = mlx_init();
	data.win_ptr = mlx_new_window(data.mlx_ptr, WINDOW_HEIGHT, WINDOW_WIDTH, "Rvrignon zamel");
	data0.mlx_ptr = data.mlx_ptr;
	data0.win_ptr = data.win_ptr;
	/* Create image test */
	//data.img.mlx_img = mlx_new_image(data.mlx_ptr, WINDOW_WIDTH, WINDOW_HEIGHT);
	//data.img.addr = mlx_get_data_addr(data.img.mlx_img, &data.img.bpp, &data.img.line_len, &data.img.endian);
	
	int width;
	int height;
	/* Import image from internet */
	//render_rect_img(&data.img, (t_rect){0, 0, WINDOW_HEIGHT, WINDOW_WIDTH, GREEN_PIXEL});
	data.img.mlx_img = mlx_xpm_file_to_image(data.mlx_ptr, "img/grillage_cc8233_size.xpm", &width, &height);
	data0.img.mlx_img = mlx_xpm_file_to_image(data.mlx_ptr, "img/case0.xpm", &width, &height);
	printf("%d\n%d\n", width, height);
	mlx_loop_hook(data.mlx_ptr, &render, &data);
	
	//mlx_key_hook(data.win_ptr, &handle_input, &data);
	mlx_hook(data.win_ptr, KeyPress, KeyPressMask, &handle_keypress, &data);
	mlx_hook(data.win_ptr, KeyRelease, KeyReleaseMask, &handle_keyrelease, &data); /* CHANGED */

	mlx_loop(data.mlx_ptr);
	printf("test\n");
	mlx_destroy_display(data.mlx_ptr);
	free(data.mlx_ptr);
}
