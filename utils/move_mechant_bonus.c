/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_mechant_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smessal <smessal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/23 14:59:45 by smessal           #+#    #+#             */
/*   Updated: 2022/09/26 23:59:55 by smessal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void    init_mechant(t_data *data)
{
    int i;
    int mechant;

    mechant = count_elements(data->map, 'M');
    data->mechant = ft_calloc(mechant, sizeof(int *));
    if (!data->mechant)
        return ;
    i = 0;
    while (i < mechant)
    {
        data->mechant[i] = 0;
        i++;
    }    
}

void    move_mechant(t_data data)
{
    int     i;
    int     j;
    int     k;
    char **map;

    map = data.map;
    i = 0;
    k = 0;
    while (map[i])
    {
        j = 0;
        while (map[i] && map[i][j])
        {
            if (map[i][j] && map[i][j] == 'M')
            {
                if ((map[i][j + 1] == '0' || map[i][j + 1] == 'P')
                && data.mechant[k] == 0)
                {
                    map[i][j + 1] = 'M';
                    map[i][j] = '0';
                    j++;
                    if (map[i][j + 1] != '0' && map[i][j + 1] != 'P')
                    {
                        data.mechant[k] = 1;
                        printf("map[i][j + 1]: %c\n", map[i][j + 1]);
                    }
                }
                else if ((map[i][j - 1] == '0' || map[i][j - 1] == 'P'))
                {
                    map[i][j - 1] = 'M';
                    map[i][j] = '0';
                    if (map[i][j - 2] & map[i][j - 2] != '0' && map[i][j - 2] != 'P')
                        data.mechant[k] = 0;
                }
                k++;
            }
            j++;
        }
        i++;
    }
    i = 0;
    while (map[i])
    {
        printf("%s", map[i]);
        i++;
    }
}
