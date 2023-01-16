/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgirardi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 14:11:22 by mgirardi          #+#    #+#             */
/*   Updated: 2022/11/10 14:11:25 by mgirardi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_prossima_linea(char *stringa)
{
	char	*linea;
	int		i;
	int		j;

	j = 0;
	i = 0;
	while (stringa[i] && (stringa[i] != '\n'))
		i++;
	if (stringa[i] == '\0')
	{
		free (stringa);
		return (NULL);
	}
	linea = ft_calloc((ft_strlen(stringa) - i + 1), (sizeof(char)));
	i = i + 1;
	while (stringa[i])
		linea[j++] = stringa[i++];
	free (stringa);
	return (linea);
}

char	*ft_prima_linea(char *stringa)
{
	char	*linea;
	int		i;

	i = 0;
	if (!stringa[i])
		return (NULL);
	while (stringa[i] && (stringa[i] != '\n'))
		i++;
	if (stringa[i] == '\n')
		i++;
	linea = ft_calloc((i + 1), sizeof(char));
	i = 0;
	while (stringa[i] && (stringa[i] != '\n'))
	{
		linea[i] = stringa[i];
		i++;
	}
	if (stringa[i] == '\n')
		linea[i] = '\n';
	return (linea);
}

char	*ft_leggi_file(char *str, int fd )
{
	int		i;
	char	*buff;

	if (!str)
		str = ft_calloc(1, 1);
	buff = ft_calloc((BUFFER_SIZE + 1), sizeof(char));
	i = 1;
	while (i > 0)
	{
		if (ft_strchr(buff, '\n'))
			break ;
		i = read(fd, buff, BUFFER_SIZE);
		if (i < 0)
		{
			free (buff);
			return (NULL);
		}		
		buff[i] = '\0';
		str = ft_strjoinf(str, buff);
	}
	free (buff);
	return (str);
}

char	*get_next_line(int fd)
{
	static char	*stringa;
	char		*linea;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
		return (NULL);
	stringa = ft_leggi_file(stringa, fd);
	linea = ft_prima_linea(stringa);
	stringa = ft_prossima_linea(stringa);
	return (linea);
}

