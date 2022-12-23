/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgirardi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 15:34:51 by mgirardi          #+#    #+#             */
/*   Updated: 2022/10/12 16:08:59 by mgirardi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nitems, size_t size)
{
	void	*i;
	size_t	x;

	if (nitems == 0 || size == 0)
	{
		nitems = 1;
		size = 1;
	}
	x = nitems * size;
	i = malloc(x);
	if (i == NULL)
		return (NULL);
	else
		ft_bzero(i, x);
	return (i);
}
