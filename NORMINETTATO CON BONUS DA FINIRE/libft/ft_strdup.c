/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgirardi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 16:10:46 by mgirardi          #+#    #+#             */
/*   Updated: 2022/10/12 16:17:42 by mgirardi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *string)
{
	int		i;
	char	*str;

	i = 0;
	str = (char *)malloc(sizeof(char) * (ft_strlen(string) + 1));
	if (!str)
		return (NULL);
	while (string[i] != '\0')
	{
		str[i] = string[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}
