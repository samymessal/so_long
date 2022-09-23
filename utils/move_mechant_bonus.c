/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_mechant_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smessal <smessal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/23 14:59:45 by smessal           #+#    #+#             */
/*   Updated: 2022/09/23 15:33:03 by smessal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void    move_mechant(t_data data)
{
    int     i;
    int     j;
    char **map;

    map = data.map;
    i = 0;
    while (map && map[i])
    {
        j = 0;
        while (map[i] && map[i][j])
        {
            if (map[i][j] && map[i][j] == 'M')
            {
                if (map[i][j + 1] != '1' && map[i][j + 1] != 'C')
                {
                    printf("i: %d j: %d\n", i, j);
                    map[i][j + 1] = 'M';
                    map[i][j] = '0';
                }
                else if (map[i][j - 1] != '1' && map[i][j - 1] != 'C')
                {
                    map[i][j - 1] = 'M';
                    map[i][j] = '0';
                }
            }
            j++;
        }
        i++;
    }
}
