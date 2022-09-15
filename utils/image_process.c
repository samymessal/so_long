/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image_process.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smessal <smessal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/04 16:21:58 by smessal           #+#    #+#             */
/*   Updated: 2022/09/15 19:08:22 by smessal          ###   ########.fr       */
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

int	download_image(t_data *data, t_img *img, char *path)
{	
	img->height = 0;
	img->width = 0;
	img->mlx_img = mlx_xpm_file_to_image(data->mlx_ptr, path, &img->width, &img->height);
	if (!img->mlx_img)
		return (0);
	img->addr = mlx_get_data_addr(img->mlx_img, &img->bpp, &img->line_len, &img->endian);
	return (1);
}

void	conditions_draw(t_img *img_big, t_img *all, char map, t_pos pos)
{
	if (map == '0')
		draw(img_big, all[0], pos.width, pos.height);
	else if (map == '1')
		draw(img_big, all[1], pos.width, pos.height);
	else if (map == 'C')
		draw(img_big, all[3], pos.width, pos.height);
	else if (map == 'P')
		draw(img_big, all[4], pos.width, pos.height);
	else if (map == 'E')
		draw(img_big, all[2], pos.width, pos.height);
	else if (map == 'O')
		draw(img_big, all[6], pos.width, pos.height);
	else if (map == 'M')
		draw(img_big, all[5], pos.width, pos.height);
	return ;
}
