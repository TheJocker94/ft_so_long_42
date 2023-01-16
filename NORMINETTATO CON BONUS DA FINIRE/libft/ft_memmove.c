/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgirardi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 13:33:36 by mgirardi          #+#    #+#             */
/*   Updated: 2022/10/11 13:57:30 by mgirardi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	char	*src_p;
	char	*dest_p;
	size_t	i;

	i = 0;
	src_p = (char *)src;
	dest_p = (char *)dest;
	if (dest_p > src_p)
	{
		while (n > 0)
		{
			n--;
			dest_p[n] = src_p[n];
		}
	}
	else
	{
		while (i < n)
		{
			dest_p[i] = src_p[i];
			i++;
		}
	}
	return (dest);
}
