/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skushnir <skushnir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/27 00:36:06 by sergee            #+#    #+#             */
/*   Updated: 2017/11/28 16:27:40 by skushnir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

#include <fcntl.h>
#include "libft/libft.h"
#define BUFF_SIZE 90

int get_next_line(const int fd, char **line);

# endif