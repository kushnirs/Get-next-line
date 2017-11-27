/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skushnir <skushnir@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/05 21:43:22 by skushnir          #+#    #+#             */
/*   Updated: 2017/11/05 22:46:49 by skushnir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void const *content, size_t content_size)
{
	t_list	*begin;

	begin = NULL;
	if ((begin = (t_list*)malloc(sizeof(t_list))) == NULL)
		return (NULL);
	if (content)
	{
		if ((begin->content =
		(unsigned char*)malloc(sizeof(unsigned char))) == NULL)
			return (NULL);
		begin->content = ft_memcpy(begin->content, content, content_size + 1);
		begin->content_size = content_size;
	}
	else
	{
		begin->content = NULL;
		begin->content_size = 0;
	}
	begin->next = NULL;
	return (begin);
}
