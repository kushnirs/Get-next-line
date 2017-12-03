/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skushnir <skushnir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/28 07:31:52 by skushnir          #+#    #+#             */
/*   Updated: 2017/12/03 15:17:52 by skushnir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *string, int symbol)
{
	if (!string)
		return (NULL);
	while (*string)
	{
		if (*string == symbol)
			return ((char*)string);
		string++;
	}
	if (symbol == '\0')
		return ((char*)string);
	return (NULL);
}
