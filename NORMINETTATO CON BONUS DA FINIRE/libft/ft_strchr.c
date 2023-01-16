/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgirardi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 14:49:39 by mgirardi          #+#    #+#             */
/*   Updated: 2022/10/11 18:04:16 by mgirardi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	char	*ptr;

	ptr = (char *) s;
	while (*ptr != c)
	{
		if (*ptr == 0)
			return (NULL);
		ptr++;
	}
	return (ptr);
}
