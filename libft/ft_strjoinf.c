/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoinf.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ocastell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 19:04:46 by ocastell          #+#    #+#             */
/*   Updated: 2023/01/17 19:04:52 by ocastell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoinf(char *str, char *buff)
{
	char	*temporaneo;

	if (!buff)
		return (str);
	temporaneo = ft_strjoin(str, buff);
	free(str);
	return (temporaneo);
}
