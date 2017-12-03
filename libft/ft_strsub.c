/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skushnir <skushnir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/30 00:36:26 by skushnir          #+#    #+#             */
/*   Updated: 2017/12/01 17:04:31 by skushnir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strsub(char const *s, unsigned int start, size_t len)
{
	unsigned int	j;
	char			*i;

	if (!s)
		return (NULL);
	if ((i = ft_strnew(len)) == NULL)
		return (NULL);
	j = 0;
	while (j < len)
		i[j++] = s[start++];
	i[j] = 0;
	return (i);
}
