/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skushnir <skushnir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/27 00:33:51 by sergee            #+#    #+#             */
/*   Updated: 2017/11/28 20:09:08 by skushnir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

int	get_next_line(const int fd, char **line)
{
	int				i;
	char			*buff;
	t_list			*tmp;
	static t_list	*descr = NULL;

	buff = ft_strnew(BUFF_SIZE);
	if (fd < 0 || !line || (i = read(fd, buff, BUFF_SIZE)) < 0)
			return (-1);
	*line = 0;
	tmp = NULL;
	tmp = descr;
	// while (tmp->content_size != fd && tmp)
	//  	tmp = tmp->next;
	tmp = ft_lstnew((ft_strcpy(ft_strnew(BUFF_SIZE), buff)), ft_strlen(buff));
	tmp->content_size = (size_t)fd;
	// if (!ft_strchr(buff, '\n'))
	//  	return (ft_join(tmp, buff , line, i));
	*line = ft_strnew(i - ft_strlen(ft_strchr(buff, '\n')));
	ft_strncpy(*line, buff, i - ft_strlen(ft_strchr(buff, '\n')));
	free(tmp->content);
	i = ft_strlen(ft_strchr(buff, '\n'));
	tmp->content = ft_strcpy(ft_strnew(i), ft_strchr(buff, '\n'));
	free(buff);
	return (0);
}

int	main(int argc, char **argv)
{
	int fd;
	char **line;

	line = (char**)malloc(sizeof(char*) * 5);
	fd = open(argv[1], O_RDONLY);
	printf("result= %d", get_next_line(fd, line));
	printf("\n-------------\n%s\n", line[0]);
		printf("result= %d", get_next_line(fd, line));
	printf("\n-------------\n%s\n", line[0]);
	// printf("result= %d\n", get_next_line(fd, line));
	// printf("%s\n", line[0]);
}