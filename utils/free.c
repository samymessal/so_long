/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smessal <smessal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/11 12:39:30 by smessal           #+#    #+#             */
/*   Updated: 2022/09/15 19:58:07 by smessal          ###   ########.fr       */
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
	while (imgs && i < 7)
	{
		if (imgs[i].mlx_img)
			mlx_destroy_image(data->mlx_ptr, imgs[i].mlx_img);
		i++;
	}
	free(imgs);
}

void	free_all(t_all all)
{
	if (all.data.map)
		free_tab(all.data.map);
	free_imgs(&all.data, all.imgs);
	if (all.big.mlx_img)
		mlx_destroy_image(all.data.mlx_ptr, all.big.mlx_img);
	if (all.data.win_ptr)
		mlx_destroy_window(all.data.mlx_ptr, all.data.win_ptr);
	if (all.data.mlx_ptr)
		mlx_destroy_display(all.data.mlx_ptr);
	if (all.data.mlx_ptr)	
		free(all.data.mlx_ptr);
}
