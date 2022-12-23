/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgirardi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 18:16:49 by mgirardi          #+#    #+#             */
/*   Updated: 2022/10/11 18:30:45 by mgirardi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_logic(int i, int *sign, int *result, const char *str)
{
	while (str[i] == 32 || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '-')
	{
		*sign *= -1;
		i++;
	}
	else if (str[i] == '+')
		i++;
	while (str[i] >= '0' && str[i] <= '9')
	{
		*result *= 10;
		*result += str[i] - '0';
		i++;
	}
}

int	ft_atoi(const char *str)
{	
	int	i;
	int	sign;
	int	result;

	i = 0;
	sign = 1;
	result = 0;
	ft_logic(i, &sign, &result, str);
	return (result * sign);
}
