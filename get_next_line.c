/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skushnir <skushnir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/27 00:33:51 by sergee            #+#    #+#             */
/*   Updated: 2017/11/27 17:20:00 by skushnir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

int	get_next_line(const int fd, char **line)
{
	int i;
	char			*buff;
	static t_list	*descr;

	i = 0;
	if (fd == -1)
		return (-1);
	buff = ft_strnew(BUFF_SIZE);
	read(fd, buff, BUFF_SIZE);
	while (buff[i] != '\n')
		i++;
	descr = ft_lstnew((void*)(ft_strsub(buff, 0, i)), i);
	descr->content_size = (size_t)fd;
	printf("i= %d\n", i);
	printf("%s\n", (char*)descr->content);
	printf("%d\n", (int)descr->content_size);
	*line = ft_strnew(i);
	ft_strcpy(*line, (char*)descr->content);
	return (0);
}

int	main(int argc, char **argv)
{
	int fd;
	char **line;

	line = (char**)malloc(sizeof(char*) * 5);
	fd = open(argv[1], O_RDONLY);
	printf("result= %d\n", get_next_line(fd, line));
	printf("%s\n", line[0]);
}