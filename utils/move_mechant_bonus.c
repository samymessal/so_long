/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_mechant_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smessal <smessal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/23 14:59:45 by smessal           #+#    #+#             */
/*   Updated: 2022/09/26 23:18:25 by smessal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int mover = 0;

void    move_mechant(t_data data)
{
    int     i;
    int     j;
    char **map;

    map = data.map;
    i = 0;
    while (map[i])
    {
        j = 0;
        while (map[i] && map[i][j])
        {
            if (map[i][j] && map[i][j] == 'M')
            {
                if ((map[i][j + 1] == '0' || map[i][j + 1] == 'P')
                    && (mover == 0))
                {
                    map[i][j + 1] = 'M';
                    map[i][j] = '0';
                    j++;
                    if (map[i][j + 1] != '0' && map[i][j + 1] != 'P')
                    {
                        mover = 1;
                        printf("map[i][j + 1]: %c\n", map[i][j + 1]);
                    }
                }
                else if ((map[i][j - 1] == '0' || map[i][j - 1] == 'P')
                    && mover == 1)
                {
                    map[i][j - 1] = 'M';
                    map[i][j] = '0';
                    if (map[i][j - 2] & map[i][j - 2] != '0' && map[i][j - 2] != 'P')
                        mover = 0;
                }
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
    printf("\n%d\n", mover);
}
