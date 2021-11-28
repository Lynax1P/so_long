#include "libft.h"

void	ft_error(char *str)
{
	write(1, str, ft_strlen(str));
	exit(1);
}