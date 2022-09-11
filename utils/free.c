/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smessal <smessal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/11 12:39:30 by smessal           #+#    #+#             */
/*   Updated: 2022/09/11 15:21:46 by smessal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	free_tab(char **map)
{
	int	i;
	
	i = 0;
	while (map[i])
	{
		free(map[i]);
		i++;
	}
	free(map);
}

void	free_imgs(t_data *data, t_img *imgs)
{
	int	i;
	
	i = 0;
	while (imgs && imgs[i].mlx_img)
	{
		mlx_destroy_image(data->mlx_ptr, imgs[i].mlx_img);
		i++;
	}
	free(imgs);
}

void	free_all(t_all all)
{
	free_imgs(&all.data, all.imgs);
	mlx_destroy_image(all.data.mlx_ptr, all.big.mlx_img);
	mlx_destroy_window(all.data.mlx_ptr, all.data.win_ptr);
	mlx_destroy_display(all.data.mlx_ptr);
	free(all.data.mlx_ptr);
	free_tab(all.data.map);
}
