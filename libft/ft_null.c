#include "libft.h"

void	ft_null_num(size_t *a,size_t *b,size_t *c,size_t *d)
{
	if(a)
		*a = 0;
	if(b)
		*b = 0;
	if(c)
		*c = 0;
	if(d)
		*d = 0;
}

void	ft_null_str(char **a,char **b,char **c,char ***d)
{
	if(a)
		*a = NULL;
	if(b)
		*b = NULL;
	if(c)
		*c = NULL;
	if(d)
		*d = NULL;
}
