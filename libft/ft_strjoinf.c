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