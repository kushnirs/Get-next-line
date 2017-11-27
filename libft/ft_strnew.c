/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skushnir <skushnir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/29 19:30:10 by skushnir          #+#    #+#             */
/*   Updated: 2017/10/30 13:41:30 by skushnir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strnew(size_t size)
{
	unsigned int	i;
	char			*pointer;

	if ((pointer = malloc(size + 1)) == NULL)
		return (NULL);
	i = -1;
	while (++i <= size)
		pointer[i] = 0;
	return (pointer);
}
