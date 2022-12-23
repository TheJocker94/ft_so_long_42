/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgirardi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 15:25:40 by mgirardi          #+#    #+#             */
/*   Updated: 2022/10/14 18:25:57 by mgirardi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *str1, const void *str2, size_t n)
{
	unsigned char	*s1;
	unsigned char	*s2;
	size_t			i;

	s2 = (unsigned char *)str2;
	s1 = (unsigned char *)str1;
	i = 0;
	while (i < n)
	{
		if (((unsigned char *)s1)[i] > ((unsigned char *)s2)[i])
		{
			return (1);
		}
		else if (((unsigned char *)s1)[i] < ((unsigned char *)s2)[i])
		{
			return (-1);
		}
		i++;
	}
	return (0);
}
