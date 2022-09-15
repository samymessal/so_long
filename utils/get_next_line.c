/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smessal <smessal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/30 19:10:47 by smessal           #+#    #+#             */
/*   Updated: 2022/09/15 17:43:27 by smessal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

char	*ft_stash_san(char *stash, char *buf)
{
	int		i;
	int		j;
	char	*line;

	i = 0;
	while (stash[i] != '\n' && stash[i])
		i++;
	if (stash[i] == '\n')
		i++;
	j = 0;
	line = malloc(sizeof(char) * (i + 1));
	if (!line)
		return (NULL);
	while (j < i && stash[j])
	{
		line[j] = stash[j];
		j++;
	}
	line[j] = '\0';
	j = 0;
	while (stash[i] && buf[j])
		buf[j++] = stash[i++];
	buf[j] = '\0';
	return (line);
}

char	*get_next_line(int fd)
{
	int			ret;
	char		*line;
	char		*stash;
	static char	buf[2];

	if (fd < 0 || fd > 1024)
		return (NULL);
	ret = 1;
	stash = NULL;
	stash = ft_strjoin(stash, buf);
	while (ret == 1 && !ft_strchr(buf))
	{
		ret = read(fd, buf, 1);
		if (ret == -1)
			return (free(stash), NULL);
		buf[ret] = '\0';
		if (ret == 0 && !stash[0])
			return (free(stash), NULL);
		stash = ft_strjoin(stash, buf);
	}
	line = ft_stash_san(stash, buf);
	return (free(stash), line);
}

// int	main(int ac, char **av)
// {
// 	char	*test;
// 	int		lines;
// 	char	**all;
// 	int		fd;
	
// 	if (ac > 2)
// 		return (0);
// 	// fd = open("../text.txt", O_RDONLY);
// 	// test = get_next_line(fd);
// 	// printf("%s", test);
// 	lines = ft_count_lines(av[1]);
// 	all = malloc(sizeof(char *) * lines);
	
// 	printf("%d\n", num);
// }