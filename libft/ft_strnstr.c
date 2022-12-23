/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgirardi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 14:07:51 by mgirardi          #+#    #+#             */
/*   Updated: 2022/10/17 13:22:04 by mgirardi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	j;
	size_t	x;

	i = 0;
	j = 0;
	x = ft_strlen(little);
	if (!big || !little)
	if (x == 0 || little == NULL)
                return ((char *)big);

	while ((little[j] != '\0' && big[i] != '\0') && i < len)
	{
		if (little[j] == big[i])
			j++;
		else
			j = 0;
		i++;
	}
	if (j == x)
		return ((char *)&big[i - j]);
	else
		return (0);
}

int	main(int ac, char **av)
{
	if (ac != 3)
		return 0;
	char *result;
       	result = malloc(20 * sizeof(char));
	result = ft_strnstr(av[1], av[2], atoi(av[3]));
	printf("%s \n", result);
	return (0);
}
