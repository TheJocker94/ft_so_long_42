/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgirardi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 15:44:35 by mgirardi          #+#    #+#             */
/*   Updated: 2022/10/11 20:43:08 by mgirardi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *str, int ch)
{
	char	*ptr;
	int		i;

	ptr = (char *)str;
	i = ft_strlen(str);
	while (ptr[i] != ch && i > 0)
	{
		i--;
	}
	if (ptr[i] == ch)
		return (&ptr[i]);
	else
		return (NULL);
}
