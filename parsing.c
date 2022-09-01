/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smessal <smessal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/01 14:42:07 by smessal           #+#    #+#             */
/*   Updated: 2022/09/01 18:08:23 by smessal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_ber_file(char **av)
{
	int	i;

	i = 0;
	while (*av[1])
	{
		if (*av[1] == '.')
		{
			if (ft_strncmp(av[1], ".ber", 5))
				return (0);
			else
				return (1);
		}
		av[1]++;
	}
	return (0);
}

int	ft_count_lines(char	*file_name)
{
	int		lines;
	int		fd;
	int		ret;
	char	*temp;
	char	temp2;

	ret = BUFFER_SIZE;
	lines = 1;
	fd = open(file_name, O_RDONLY);
	temp = malloc(sizeof(char) * 2);
	if (!temp)
		return (0);
	while (ret == BUFFER_SIZE)
	{
		ret = read(fd, temp, BUFFER_SIZE);
		if (ret != BUFFER_SIZE)
		{
			if (temp2 == '\n')
				return (0);
		}
		temp2 = temp[0];
		if (temp[0] == '\n')
			lines++;
	}
	return (free(temp), lines);
}

char	**read_map(char *file_name)
{
	int		lines;
	char	**all;
	int		i;
	int		fd;
	
	i = 0;
	lines = ft_count_lines(file_name);
	all = malloc(sizeof(char *) * lines);
	if (!all)
		return (NULL);
	fd = open(file_name, O_RDONLY);
	all[i] = get_next_line(fd);
	while (all[i++])
	{
		all[i] = get_next_line(fd);
		printf("%d\n", i);
	}
	return (all);
}

int	main(int ac, char **av)
{
	char	*test;
	int		lines;
	char	**all;
	int		fd;
	
	if (ac > 2)
		return (0);
	all = read_map(av[1]);
	printf("%s", all[0]);
}

// int	main(int ac, char **av)
// {
// 	int fd;

// 	fd = open(av[1], O_RDONLY);
// 	if (ft_ber_file(av))
// 	{
// 		printf("yes\n");
// 	}
// 	return (0);
// }
