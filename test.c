/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smessal <smessal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/07 12:47:31 by smessal           #+#    #+#             */
/*   Updated: 2022/08/07 15:45:17 by smessal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "mlx_linux/mlx.h"
#include <stdio.h>
#include "so_long.h"

typedef struct	s_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_data;

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

void	coloriage_square(t_data *data, int x, int y, int color)
{
	int	i;
	int	j;

	i = 0;
	while (i < x)
	{
		j = 0;
		while (j < y)
		{
			my_mlx_pixel_put(data, i, j, color);
			j++;
		}
		i++;
	}
}

char	*convert_to_hex(int x)
{
	char	*result;
	int		i;
	int		temp;
	char	*base;
	
	if (x == 0)
		return ("00");
	i = 1;
	temp = x;
	result = malloc(sizeof(char) * 3);
	if (!result)
		return (NULL);
	base = "0123456789ABCDEF";
	while (x > 16)
	{
		temp = x;
		result[i] = base[temp % 16];
		i--;
		x /= 16; 	
	}
	result[i] = base[x % 16];
	result[2] = '\0';
	return (result);
}

int	ft_strlen(char *str)
{
	int	len;

	if (!str)
		return (0);
	len = 0;
	while (str[len])
		len++;
	return (len);
}

char	*ft_concat(char *first, char *sec)
{
	char	*all;
	int		i;
	int		j;
	
	if (!first)
		return (sec);
	all = malloc(sizeof(char) * (ft_strlen(first) + ft_strlen(sec)) + 1);
	if (!all)
		return (NULL);
	i = 0;
	while (first[i])
	{
		all[i] = first[i];
		i++;
	}
	j = 0;
	while (sec[j])
		all[i++] = sec[j++];
	all[i] = '\0';
	//free(first);
	//free(sec);
	return (all);
}

int	rgb(int red, int green, int blue)
{
	char	*all;
	char	*two;
	int		result;
	
	two = convert_to_hex(red);
	all = ft_concat(all, two);
	two = convert_to_hex(green);
	all = ft_concat(all, two);
	printf("%s\n", all);
	two = convert_to_hex(blue);
	all = ft_concat(all, two);
	result = ft_atoi_base(all, "0123456789ABCDEF");
	return (result);
}

int main(void)
{
	void	*mlx_ptr;
	void	*win_ptr;
	int		x;
	int		y;
	t_data	img;

	x = 0;
	y = 0;
	mlx_ptr = mlx_init();
	win_ptr = mlx_new_window(mlx_ptr, 512, 512, "Rvrignon zamel");
	img.img = mlx_new_image(mlx_ptr, 512, 512);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian);
	// while (x < 512)
	// {
		
	// }
	printf("%s\n", convert_to_hex(0));
	printf("conv: %d\n", rgb(0, 0, 255));
	// coloriage_square(&img, 512, 512, 0x00FF0000);
	// coloriage_square(&img, 100, 100, 0x0000FF);
	// mlx_put_image_to_window(mlx_ptr, win_ptr, img.img, 0, 0);
	// mlx_loop(mlx_ptr);
	// mlx_destroy_window(mlx_ptr, win_ptr);
	// mlx_destroy_display(mlx_ptr);
	// free(mlx_ptr);
}