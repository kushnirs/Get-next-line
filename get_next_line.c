/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sergee <sergee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/27 00:33:51 by sergee            #+#    #+#             */
/*   Updated: 2017/11/29 21:54:08 by sergee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

int	ft_read_fd(int fd, t_list *tmp, char *buff)
{
	int	fin;
	t_list			*tm_;

	while (!ft_strchr(tmp->content, '\n') && (fin = read(fd, buff, BUFF_SIZE)))
	{
		tm_ = tmp;
		buff[fin] = 0;
		tmp->content = ft_strjoin(tmp->content, buff);
		// ft_memdel((void**)&tm_);
	}
	printf("%d\n", fin);
	return (fin);
}

t_list *ft_check_fd(int fd, t_list **descr)
{
	if (*descr)
		while (*descr)
		{
			if ((int)(*descr)->content_size == fd)
				return (*descr);
			*descr = (*descr)->next;
		}
	ft_lstadd(descr, ft_lstnew("", 0));
	(*descr)->content_size = fd;
	return (*descr);
}

int	get_next_line(const int fd, char **line)
{
	int				i;
	char			buff[BUFF_SIZE + 1];
	t_list			*tmp;
	t_list			*tm_;
	static t_list	*descr = NULL;

	if (fd < 0 || !line || read(fd, buff, 0) < 0)
			return (-1);
	tmp = ft_check_fd(fd, &descr);
	*line = 0;
	if (!ft_read_fd(fd, tmp, buff))
		return (0);
	i = (int)ft_strlen(tmp->content);
	*line = ft_strnew(i - ft_strlen(ft_strchr(tmp->content, '\n')));
	ft_strncpy(*line, tmp->content, i - ft_strlen(ft_strchr(tmp->content, '\n')));
	tm_ = tmp->content;
	tmp->content = (ft_strdup(ft_strchr(tmp->content, '\n')) + 1);
	printf("ostatok\n%s\n", tmp->content);
	//ft_memdel((void**)tm_);
	return ((*line && **line) ? 1 : 0);
}

int	main(int argc, char **argv)
{
	int fd;
	char **line;

	line = (char**)malloc(sizeof(char*) * 5);
	fd = open(argv[1], O_RDONLY);
	int fd1 = open(argv[2], O_RDONLY);
	printf("result= %d\n", get_next_line(fd, line));
	printf("%s\n\n-------------\n", line[0]);
	printf("result= %d\n", get_next_line(fd, line));
	printf("%s\n\n-------------\n", line[0]);
	printf("result= %d\n", get_next_line(fd, line));
	printf("%s\n", line[0]);
	printf("result= %d\n", get_next_line(fd, line));
	printf("%s\n", line[0]);
	// while (get_next_line(fd, line))
	// {
	// 	printf("%s\n", line[0] );
	// }
}







