/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgirardi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 11:46:27 by mgirardi          #+#    #+#             */
/*   Updated: 2022/10/11 20:57:14 by mgirardi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char	*x;
	unsigned char	*y;
	size_t			i;

	i = 0;
	x = (unsigned char *)src;
	y = (unsigned char *)dest;
	if (n == 0 || dest == src)
		return (dest);
	while (n > 0)
	{
		y[i] = x[i];
		n--;
		i++;
	}
	return (dest);
}
