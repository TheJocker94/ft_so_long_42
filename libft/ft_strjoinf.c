#include "libft.h"

char	*ft_strjoinf(char *str, char *buff)
{
	char	*temporaneo;

	temporaneo = ft_strjoin(str, buff);
	free(str);
	return (temporaneo);
}